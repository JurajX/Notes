# Update machine with internet connection, install python
sudo yum update
sudo yum install python3-pip python3-devel

# Check for the version of pip (comand pip3 alone might not work)
python3 -m pip -V

# Download Packages on a machine with internet connection (assumed pip3 is installed).
mkdir ~/python_lib_download
python36 -m pip download virtualenv numpy scipy matplotlib pandas scikit-learn jupyter -d "~/python_lib_download"

# compress the downloaded files
tar -czvf pylibs.tar.gz python_lib_download

# Move the downloaded packages to the target machine (to e.g. ~/python_lib_download)
# Decompress the downloaded files
tar -xzvf pylibs.tar.gz

# Update the target machine; python3-devel might not be necessary, tmux is optional.
sudo yum update
sudo yum install python3-pip python3-devel
sudo yum tmux

# Install virtualenv, set up one, and activate it
sudo python3 -m pip install virtualenv -f ./ --no-index
virtualenv ~/.venv/env
source ~/.venv/env/bin/activate

# Install packages in the target machine in the virtual env
python3 -m pip install numpy scipy matplotlib pandas scikit-learn jupyter -f ./python_lib_download --no-index

# Keep in mind that you have to forward port 8888 to one at your local machine, e.g. 8000
ssh -L localhost:8000:localhost:8888 host@HOST_IP_ADDRESS

# Start tmux and jupyter notebook without a browser on a specific port
source ~/.venv/env/bin/activate
tmux
jupyter notebook --no-browser --port=8888

# Copy from host to local
scp -r LDAP_NAME@gramos.titan:~/FOLDER_TO_COPY DESTINATION

# Copy from local to host
scp -r FOLDER_TO_COPY LDAP_NAME@gramos.titan:~/DESTINATION
