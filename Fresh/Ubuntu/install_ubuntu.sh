#!/bin/bash

dir="/home/${USER}/.config/gtk-3.0/"

if [ -d "${dir}" ]; then
    echo "Directory ${dir} already exists, skipping."
else
    mkdir -p "${dir}"
    echo "Directory ${dir} created."
fi

eval "cp gtk.css ${dir}"
eval "./remap_system_keys.sh"
eval "./set_terminal_shortcuts_and_colours.sh"
