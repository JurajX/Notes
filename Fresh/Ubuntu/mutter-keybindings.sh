#!/bin/bash

# --------------- mutter-keybindings

cmd="gsettings set org.gnome.mutter.keybindings"

key_values=(
"rotate-monitor \"['XF86RotateWindows']\""
"switch-monitor \"['XF86Display']\""
"toggle-tiled-left \"['<Ctrl>Home']\""
"toggle-tiled-right \"['<Ctrl>End']\""
"tab-popup-cancel \"[]\""
"tab-popup-select \"[]\""
)

for i in ${!key_values[@]}
do
    eval "${cmd} ${key_values[${i}]}"
done

echo "Sortcuts for org.gnome.mutter.keybindings are set!"
