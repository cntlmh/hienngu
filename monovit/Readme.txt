1. Prepare workspace:
  Clone repo:
    - Clone monodept2:
        + Repo: https://github.com/nianticlabs/monodepth2.git
        + Commit: b676244e5a1ca55564eb5d16ab521a48f823af31
    - Clone monovit:
        + Repo: https://github.com/zxcqlf/MonoViT.git
        + Commit: 3960e94ce4980ffb7dabc879bd5566323167126f
  Then copy workspace monovit to monodept2 (replace also)

2. Prepare environment:
  Use conda with python 3.8 and install all the package as file <monovit_env.yml>
  Copy folder <kitti_data>, <splits>, <weight> and replace file <evaluate_depth.py> (can diff to have the modification information)
  
3. Gen onnx and testing saved model:
  Run command:
	$python evaluate_depth.py --load_weights_folder ./weight --eval_mono
  The onnx file is in the folder <weight>. Then run:
        $python onnx_testing.py
  to test the onnx model.