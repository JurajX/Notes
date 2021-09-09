#!/bin/bash

# --------------- Set terminator preferences
dir="/home/${USER}/.config/terminator"

if [ -d "${dir}" ]; then
    echo "Directory ${dir} already exists, skipping."
else
    mkdir -p "${dir}"
    echo "Directory ${dir} created."
fi

eval "cp terminator-config ${dir}/config"
echo "Copied terminator-config to ${dir}."
