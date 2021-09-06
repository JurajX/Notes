#!/bin/bash

# --------------- Workspace Availability
gsettings set org.gnome.mutter workspaces-only-on-primary false
gsettings set org.gnome.shell.overrides workspaces-only-on-primary false

echo "Workspace is now available on all screens."
