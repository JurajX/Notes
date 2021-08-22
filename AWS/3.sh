# confirm proper installation of GPU

echo "Do you wish to test NVIDIA driver installation? Type 'y' to continue."
read -p "Your input: " continue

if [ "$continue" == "y" ];
then
	nvidia-smi -q | head
	nvcc --version

else
	echo "Skipping test of NVIDIA driver installation."
fi

# unzip, python, virtualenv
sudo apt-get install unzip
sudo apt-get --assume-yes install python3-tk
sudo apt-get --assume-yes install python3-pip
sudo pip3 install --upgrade pip
sudo pip3 install virtualenv

sudo reboot