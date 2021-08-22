# create and activate virtualenv
virtualenv /home/ubuntu/ml
source /home/ubuntu/ml/bin/activate

# install packages in virtualenv
pip3 install numpy scipy matplotlib pandas scikit-learn jupyter pygame gym

# PyTorch
echo "Do you wish to install PyTorch with cuda? Type 'y' to continue."
read -p "Your input: " continue

if [ "$continue" == "y" ];
then
	echo "Installing PyTorch with cuda."
	pip3 install https://download.pytorch.org/whl/cu100/torch-1.0.1.post2-cp36-cp36m-linux_x86_64.whl

else
	echo "Installing PyTorch without cuda."
	pip3 install https://download.pytorch.org/whl/cpu/torch-1.0.1.post2-cp36-cp36m-linux_x86_64.whl
fi
pip install torchvision


# Tensorflow
echo "Do you wish to install TensorFlow with cuda? Type 'y' to continue."
echo "Please note that TensorFlow does not support cuda.10 driver yet."
read -p "Your input: " continue

if [ "$continue" == "y" ];
then
	echo "Installing TensorFlow with cuda."
	pip3 install tensorflow-gpu

else
	echo "Installing TensorFlow without cuda."
	pip3 install tensorflow
fi

sudo reboot
