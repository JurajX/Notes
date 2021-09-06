#!/bin/bash

# --------------- Set gtk3 Shortcuts
dir="/home/${USER}/.config/gtk-3.0/"

if [ -d "${dir}" ]; then
    echo "Directory ${dir} already exists, skipping."
else
    mkdir -p "${dir}"
    echo "Directory ${dir} created."
fi

eval "cp gtk.css ${dir}"
