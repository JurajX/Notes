#!/bin/bash

# --------------- Clear the old Shortcuts
gsettings reset-recursively org.gnome.settings-daemon.plugins.media-keys

# --------------- Create Shortcut Names, Keys, and Bindings
WIDTH="1920"
HEIGHT="1035"

NAMES=( "quarter NW" "quarter NE" "quarter SW" "quarter SE" )

KEYS=( "Home" "Page_Up" "Page_Down" "End" )
POSITIONS=( "0 0" "1920 0" "0 1095" "1920 1095")
BINDINGS=( ${KEYS[@]} )
for idx in ${!KEYS[@]}
do
    KEYS[${idx}]="Ctrl+Alt+${KEYS[${idx}]}"
    BINDINGS[${idx}]="<Ctrl><Alt>${BINDINGS[${idx}]}"
done

# --------------- Path Where the Shortcuts Live in Gnome
SHORTCUT_LIST=()
for i in ${!KEYS[@]}
do
    SHORTCUT_LIST+=( "/org/gnome/settings-daemon/plugins/media-keys/custom-keybindings/custom${i}/" )
done


# --------------- Update the Path
printf -v TMP "'%s', " "${SHORTCUT_LIST[@]}"
TMP=${TMP::-2}
eval "gsettings set org.gnome.settings-daemon.plugins.media-keys custom-keybindings \"[${TMP[*]}]\""


# --------------- Generate Shortcuts
CMD="gsettings set org.gnome.settings-daemon.plugins.media-keys.custom-keybinding:"
for i in ${!KEYS[@]}
do
    eval "${CMD}${SHORTCUT_LIST[${i}]} name '${NAMES[${i}]}'"
    eval "${CMD}${SHORTCUT_LIST[${i}]} command 'bash -c \"xdotool getactivewindow windowmove ${POSITIONS[${i}]} windowsize ${WIDTH} ${HEIGHT}\"'"
    eval "${CMD}${SHORTCUT_LIST[${i}]} binding '${BINDINGS[${i}]}'"
done

echo "Quarter window shortcuts were set."