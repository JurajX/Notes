#!/bin/bash

# ----- repam keyboard keys
eval "./remap-system-keys.sh"

# ----- set gtk3 keybindings
eval "./gtk3.sh"

# ----- set system shortcuts
eval "./desktop-wm-keybindings.sh"
eval "./mutter-keybindings.sh"
eval "./settings-daemon-plugins-media-keys.sh"
eval "./shell-keybindings.sh"
eval "./terminal-keybindings.sh"

# ----- set terminal profile
eval "./terminal-profile.sh"

# ----- make workspace available on all screens
eval "./workspace.sh"
