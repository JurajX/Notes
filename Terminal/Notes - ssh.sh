# ==================== ssh
ssh-keygen [-q] [-b bits] [-C comment] [-f output_keyfile] [-m format] [-N new_passphrase] [-t dsa | ecdsa | ed25519 | rsa]
ssh-keygen -t rsa -b 4096                                   # generates private-public rsa key pair

ssh-copy-id -i ~/.ssh/key.pub user@server                   # copies the public key to the server and installs it (generates authorized_keys)
ssh -i ~/.ssh/key user@server                               # connects to the host using the private key
ssh -L localhost:8000:localhost:8888 user@server            # connects to the host and forwards localhost connection

scp -r /from/folder user@server:/to/folder                  # ssh copy from local to host
scp -r user@server:/from/folder /to/folder                  # ssh copy from host to local

sudo cp /etc/ssh/sshd_config /etc/ssh/sshd_config.backup    # back-ups the ssh config file, in the server
sudo nano sshd_config                                       # change PasswordAuthentication no
sudo service ssh restart                                    # applies the changes

ssh-add key                                                 # adds key to the ssh manager so that one does not need to input pass phrase



# ==================== config
Host myname                                                 # used to write 'ssh myname' in terminal to connect
   HostName           rl-005.chair.faculty.uni.com          # IP or domain
   User               juraj
   IdentityFile       ~/.ssh/key
   AddKeysToAgent     yes
   UseKeychain        yes
   LocalForward       10000 localhost:8888
   ForwardX11         yes
   ForwardX11Trusted  yes

Host github
   HostName           github.com
   User               git
   IdentityFile       ~/.ssh/GitHub
   AddKeysToAgent     yes
   UseKeychain        yes
