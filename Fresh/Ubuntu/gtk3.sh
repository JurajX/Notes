#!/bin/bash

# --------------- Set gtk3 Shortcuts
dir="/home/${USER}/.config/gtk-3.0"
file="gtk.css"

if [ -d "${dir}" ]; then
    echo "Directory ${dir} already exists, skipping."
else
    mkdir -p "${dir}"
    echo "Directory ${dir} created."
fi

eval "cp ${file} ${dir}/gtk.css"
echo "Copied ${file} to ${dir}."
