import onnx
from onnxsim import simplify
import onnxoptimizer
import argparse
import os
from onnx import helper

def clean_outputs_advanced(input_path, cleaned_path):
    print(f"[0] Cleaning outputs in model: {input_path}")
    model = onnx.load(input_path)
    graph = model.graph

    # Print output names for debugging
    print("Model outputs:", [output.name for output in graph.output])

    # Collect all input names (from nodes, initializers, and value_info)
    all_input_names = set()
    for node in graph.node:
        all_input_names.update(node.input)
    for initializer in graph.initializer:
        all_input_names.add(initializer.name)
    for value_info in graph.value_info:
        all_input_names.add(value_info.name)

    # Collect all node output names
    all_node_outputs = set()
    for node in graph.node:
        all_node_outputs.update(node.output)

    # Identify valid outputs: prioritize 'disparity' for Monodepth2
    valid_outputs = []
    for output in graph.output:
        if output.name == 'disparity':  # Explicitly select 'disparity'
            valid_outputs.append(output)
            break
    else:
        # Fallback: keep outputs that are node outputs and not used as inputs
        for output in graph.output:
            if output.name in all_node_outputs and output.name not in all_input_names:
                valid_outputs.append(output)

    if not valid_outputs:
        print("⚠️ No independent outputs found, keeping the first output")
        valid_outputs = [graph.output[0]]

    # Clear current outputs
    del graph.output[:]
    # Add back valid outputs
    for output in valid_outputs:
        graph.output.append(output)

    # Validate the model
    try:
        onnx.checker.check_model(model)
        print("✅ Model is valid after cleaning")
    except onnx.checker.ValidationError as e:
        print(f"⚠️ Model validation failed: {e}")
        raise

    onnx.save(model, cleaned_path)
    print(f"✅ Saved cleaned model: {cleaned_path}")
    return cleaned_path

def optimize_onnx(input_path, optimized_path):
    print(f"[1] Optimize model graph with onnxoptimizer: {input_path}")
    model = onnx.load(input_path)
    # Use minimal passes
    passes = ["eliminate_deadend", "eliminate_nop_pad", "eliminate_nop_transpose"]
    optimized_model = onnxoptimizer.optimize(model, passes)
    
    # Validate the optimized model
    try:
        onnx.checker.check_model(optimized_model)
        print("✅ Optimized model is valid")
    except onnx.checker.ValidationError as e:
        print(f"⚠️ Optimized model validation failed: {e}")
        raise

    onnx.save(optimized_model, optimized_path)
    print(f"✅ Saved optimized model: {optimized_path}")
    return optimized_path

def simplify_onnx(input_path, simplified_path, skip_fuse_bn=True):
    print(f"[2] Simplify model with onnxsim: {input_path}")
    try:
        model_simplified, check = simplify(
            input_path,
            skip_fuse_bn=skip_fuse_bn,
            skip_shape_inference=False,  # Enable shape inference
            perform_optimization=True,   # Enable additional optimizations
            skip_constant_folding=False, # Enable constant folding
            dynamic_input_shape=False    # Avoid dynamic shape issues
        )
        if not check:
            raise RuntimeError("Simplify failed!")
        
        # Validate the simplified model
        try:
            onnx.checker.check_model(model_simplified)
            print("✅ Simplified model is valid")
        except onnx.checker.ValidationError as e:
            print(f"⚠️ Simplified model validation failed: {e}")
            raise

        onnx.save(model_simplified, simplified_path)
        print(f"✅ Saved simplified model: {simplified_path}")
        return simplified_path
    except Exception as e:
        print(f"⚠️ Simplify error: {e}")
        print("Falling back to input model")
        return input_path

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", type=str, required=True, help="Path to original ONNX file")
    parser.add_argument("--outdir", type=str, default="output_models", help="Directory to save outputs")
    parser.add_argument("--skip_fuse_bn", action="store_true", default=True, help="Skip batch norm fusion in onnxsim")
    parser.add_argument("--skip_optimize", action="store_true", default=True, help="Skip onnxoptimizer step")
    args = parser.parse_args()

    os.makedirs(args.outdir, exist_ok=True)

    base_name = os.path.splitext(os.path.basename(args.input))[0]

    cleaned_path = os.path.join(args.outdir, base_name + "_cleaned.onnx")
    optimized_path = os.path.join(args.outdir, base_name + "_optimized.onnx")
    simplified_path = os.path.join(args.outdir, base_name + "_simplified.onnx")

    # 0. Clean outputs
    cleaned_model = clean_outputs_advanced(args.input, cleaned_path)
    
    # 1. Optimize graph (unless skipped)
    if args.skip_optimize:
        print("[1] Skipping optimization step")
        optimized_model = cleaned_path
    else:
        optimized_model = optimize_onnx(cleaned_path, optimized_path)
    
    # 2. Simplify model
    final_model = simplify_onnx(optimized_model, simplified_path, skip_fuse_bn=args.skip_fuse_bn)
    
    # Print final model used
    print(f"Final model: {final_model}")

if __name__ == "__main__":
    main()