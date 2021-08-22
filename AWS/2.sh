# Install Nvidia Drivers

echo "Enter type of EC2 instance, and press [Enter]. Options are: 'C5', 'P2', 'P3' or 'G3'."
echo "If you wish to exit type 'exit'."
read -p "Your input: " type

if   [ "$type" == "C5" ];
then
	echo "This instance does not have GPU card. Nothing to do here."
	exit

elif [ "$type" == "P2" -o "$type" == "P3" ];
then
	echo "Downloading P driver."
	wget http://us.download.nvidia.com/tesla/410.79/NVIDIA-Linux-x86_64-410.79.run

elif [ "$type" == "G3" ];
then
	echo "Downloading G driver."
	wget http://us.download.nvidia.com/XFree86/Linux-x86_64/410.93/NVIDIA-Linux-x86_64-410.93.run

elif [ "$type" == "exit" ];
then
	echo "Exitting."
	exit

else
	echo "'$type' is an invalid option."
	exit
fi

echo "Installing NVIDIA driver."
sudo /bin/sh ./NVIDIA-Linux-x86_64*.run

echo "Do you wish to install NVIDIA cuda toolkit? Type 'y' to continue."
read -p "Your input: " continue

if [ "$continue" == "y" ];
then
	echo "Installing NVIDIA cuda toolkit."
	sudo apt install nvidia-cuda-toolkit

else
	echo "Skipping installation of NVIDIA cuda toolkit."
fi

sudo reboot