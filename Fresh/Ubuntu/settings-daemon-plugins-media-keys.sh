#!/bin/bash

# --------------- settings-daemon-plugins-media-keys

cmd="gsettings set org.gnome.settings-daemon.plugins.media-keys"

key_values=(
"active true"

"window-screenshot '<Ctrl><Shift>2'"
"window-screenshot-clip '<Ctrl><Shift>6'"
"screenshot '<Ctrl><Shift>3'"
"screenshot-clip '<Ctrl><Shift>7'"
"area-screenshot '<Ctrl><Shift>4'"
"area-screenshot-clip '<Ctrl><Shift>8'"
"screencast '<Ctrl><Shift>5'"
"max-screencast-length 30"

"screenreader '<Alt>Escape'"
"screensaver '<Ctrl><Super>q'"
"logout '<Shift><Ctrl>q'"

"increase-text-size ''"
"decrease-text-size ''"
"magnifier ''"
"magnifier-zoom-in ''"
"magnifier-zoom-out ''"
"video-out ''"
"on-screen-keyboard ''"
"priority 0"
"toggle-contrast ''"
"terminal ''"
"help ''"
)

for i in ${!key_values[@]}
do
    eval "${cmd} ${key_values[${i}]}"
done

echo "Sortcuts for org.gnome.settings-daemon.plugins.media-keys are set!"
