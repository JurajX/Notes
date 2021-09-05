#!/bin/bash

dir="/home/${USER}/.xkb/keycodes"
file="macOS"
content="xkb_keycodes \"macOS\" {
  <LCTL> = 133;     // Super_L -> Ctrl_L
  <LWIN> = 37;      // Ctrl_L  -> Super_L
  <RCTL> = 134;     // Super_R -> Ctrl_R
  <RWIN> = 105;     // Ctrl_R  -> Super_R
};"

if [ -d "${dir}" ]; then
    echo "Directory ${dir} already exists, skipping."
else
    mkdir -p "${dir}"
    echo "Directory ${dir} created."
fi



touch "${dir}/${file}"
echo "${content}" > "${dir}/${file}"
echo "File with key re-mapping created."

setxkbmap -print | sed -e '/xkb_keycodes/s/"[[:space:]]/+macOS&/' | xkbcomp -I${HOME}/.xkb - ${DISPLAY}
echo "Re-mapping applied. Ignore the warnings!"
