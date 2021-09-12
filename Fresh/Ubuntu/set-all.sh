#!/bin/bash

# ----- set general preferences
eval "./general-preferences.sh"
eval "./workspace.sh"

# ----- repam keyboard keys
eval "./remap-system-keys.sh"

# ----- set gtk3 keybindings
eval "./gtk3.sh"

# ----- set terminal and terminator preferences
eval "./terminal-profile.sh"
eval "./terminal-keybindings.sh"
eval "./terminator-preferences.sh"

# ----- set dash-to-dock
eval "./dash-to-dock.sh"

# ----- set window organisation
eval "./window-resizing.sh"

# ----- set system shortcuts
eval "./desktop-wm-keybindings.sh"
eval "./mutter-keybindings.sh"
eval "./settings-daemon-plugins-media-keys.sh"
eval "./shell-keybindings.sh"
