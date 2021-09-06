#!/bin/bash

# --------------- desktop-wm-keybindings
cmd="gsettings set org.gnome.desktop.wm.keybindings"

key_values=(
# switchers
"switch-input-source \"['<Alt>space']\""
"switch-input-source-backward \"['<Shift><Alt>space']\""
"switch-applications \"['<Ctrl>Tab']\""
"switch-applications-backward \"['<Ctrl><Super>Tab']\""
"switch-windows \"['<Alt>Tab']\""
"switch-windows-backward \"['<Shift><Alt>Tab']\""
"switch-group \"[]\""
"switch-group-backward \"[]\""
"switch-panels \"[]\""
"switch-panels-backward \"[]\""
# random
"close \"['<Ctrl>q']\""
"toggle-fullscreen \"['<Ctrl><Super>f']\""
"minimize \"['<Ctrl>m']\""
# workspace shortcuts
"move-to-workspace-1 \"[]\""
"move-to-workspace-2 \"[]\""
"move-to-workspace-3 \"[]\""
"move-to-workspace-4 \"[]\""
"move-to-workspace-up \"[]\""       # might be usefull
"move-to-workspace-down \"[]\""     # might be usefull
"move-to-workspace-left \"[]\""     # might be usefull
"move-to-workspace-right \"[]\""    # might be usefull
"move-to-workspace-last \"[]\""     # might be usefull
"switch-to-workspace-1 \"[]\""
"switch-to-workspace-2 \"[]\""
"switch-to-workspace-3 \"[]\""
"switch-to-workspace-4 \"[]\""
"switch-to-workspace-up \"[]\""    # might be usefull
"switch-to-workspace-down \"[]\""    # might be usefull
"switch-to-workspace-left \"[]\""    # might be usefull
"switch-to-workspace-right \"[]\""    # might be usefull
"switch-to-workspace-last \"[]\""    # might be usefull
"toggle-on-all-workspaces \"[]\""
# window move
"move-to-center \"[]\""
"move-to-corner-ne \"[]\""
"move-to-corner-nw \"[]\""
"move-to-corner-se \"[]\""
"move-to-corner-sw \"[]\""
"move-to-monitor-down \"[]\""
"move-to-monitor-left \"[]\""
"move-to-monitor-right \"[]\""
"move-to-monitor-up \"[]\""
"move-to-side-e \"[]\""
"move-to-side-n \"[]\""
"move-to-side-s \"[]\""
"move-to-side-w \"[]\""
# the rest
"activate-window-menu \"[]\""
"always-on-top \"[]\""
"begin-move \"[]\""
"begin-resize \"[]\""
"cycle-group \"[]\""
"cycle-group-backward \"[]\""
"cycle-panels-backward \"[]\""
"cycle-panels \"[]\""
"cycle-windows \"[]\""
"cycle-windows-backward \"[]\""
"lower \"[]\""
"maximize \"[]\""
"unmaximize \"[]\""
"maximize-horizontally \"[]\""
"maximize-vertically \"[]\""
"panel-main-menu \"[]\""
"panel-run-dialog \"[]\""
"raise \"[]\""
"raise-or-lower \"[]\""
"set-spew-mark \"[]\""
"show-desktop \"[]\""
"toggle-above \"[]\""
"toggle-maximized \"[]\""
"toggle-shaded \"[]\""
)

for i in ${!key_values[@]}
do
    eval "${cmd} ${key_values[${i}]}"
done

echo "Sortcuts for org.gnome.desktop.wm.keybindings are set!"
