#!/bin/zsh

brew install python3

pip3 install --upgrade pip
pip3 install virtualenv

virtualenv ~/.venv/ml
source ~/.venv/ml/bin/activate

pip3 install --upgrade pip
pip3 install --upgrade 'python-language-server[all]'

pip3 install --upgrade mkl

pip3 install --upgrade threadpoolctl
pip3 install --upgrade numpy
pip3 install --upgrade scipy
pip3 install --upgrade matplotlib
pip3 install --upgrade pandas
pip3 install --upgrade scikit-learn
pip3 install --upgrade jupyter
pip3 install --upgrade jupyter_kernel_gateway
pip3 install --upgrade pygame==2.0.0.dev10
pip3 install --upgrade gym

pip3 install --upgrade pytest
pip3 install --upgrade coverage
pip3 install --upgrade pytest-cov

pip3 install --upgrade torch
pip3 install --upgrade torchvision
pip3 install --upgrade torchaudio
# pip3 install --upgrade tensorflow

python -m ipykernel install --user --name ml

deactivate
