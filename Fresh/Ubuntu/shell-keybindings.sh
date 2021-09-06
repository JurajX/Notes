#!/bin/bash

# --------------- shell-keybindings
cmd="gsettings set org.gnome.shell.keybindings"

key_values=(
"focus-active-notification \"[]\""
"open-application-menu \"[]\""
"pause-resume-tweens \"[]\""
"toggle-application-view \"[]\""
"toggle-message-tray \"[]\""
"toggle-overview \"['<Super>Up']\""
)

for i in ${!key_values[@]}
do
    # echo "${cmd} ${key_values[${i}]}"
    eval "${cmd} ${key_values[${i}]}"
done

echo "Sortcuts for org.gnome.shell.keybindings are set!"
