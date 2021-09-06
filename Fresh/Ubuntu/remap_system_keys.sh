#!/bin/bash

# --------------- Remap System Keys
dir="/home/${USER}/.xkb/keycodes"
file="macOS"
content="xkb_keycodes {
  <LCTL> = 133;     // Super_L -> Ctrl_L
  <LWIN> = 37;      // Ctrl_L  -> Super_L
  <RCTL> = 134;     // Super_R -> Ctrl_R
  <RWIN> = 105;     // Ctrl_R  -> Super_R
};"

if [ -d "${dir}" ]; then
    echo "Directory ${dir} already exists, skipping."
else
    eval "mkdir -p ${dir}"
    echo "Directory ${dir} created."
fi



eval "touch ${dir}/${file}"
eval "echo \"${content}\" > ${dir}/${file}"
echo "File with key re-mapping created."

eval "setxkbmap -print | sed -e '/xkb_keycodes/s/\"[[:space:]]/+macOS&/' | xkbcomp -w 3 -I${HOME}/.xkb - ${DISPLAY}"
echo "Re-mapping applied."
