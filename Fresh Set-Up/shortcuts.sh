#!/bin/bash

# =============== Add Workspace to Secondary Screen
gsettings set org.gnome.mutter workspaces-only-on-primary false
gsettings set org.gnome.shell.overrides workspaces-only-on-primary false



# =============== Shortcuts

# --------------- Manual Settup of Shortcuts
# bash -c "xdotool keyup 'alt+Down' key --delay 0 'Page_Down'"
# bash -c "xdotool keyup 'alt+Up' key --delay 0 'Page_Up'"
# bash -c "xdotool keyup 'alt+Left' key --delay 0 'Home'"
# bash -c "xdotool keyup 'alt+Right' key --delay 0 'End'"

# bash -c "xdotool keyup 'shift+alt+Down' key --delay 0 'shift+Page_Down'"
# bash -c "xdotool keyup 'shift+alt+Up' key --delay 0 'shift+Page_Up'"
# bash -c "xdotool keyup 'shift+alt+Left' key --delay 0 'shift+Home'"
# bash -c "xdotool keyup 'shift+alt+Right' key --delay 0 'shift+End'"


# --------------- Clear the old Shortcuts
gsettings reset-recursively org.gnome.settings-daemon.plugins.media-keys


# --------------- Path Where the Shortcuts Live in Gnome
SHORTCUT_LIST=()
for i in {0..7}
do
    SHORTCUT_LIST+=( "/org/gnome/settings-daemon/plugins/media-keys/custom-keybindings/custom${i}/" )
done


# --------------- Update the Path
printf -v TMP "'%s', " "${SHORTCUT_LIST[@]}"
TMP=${TMP::-2}
gsettings set org.gnome.settings-daemon.plugins.media-keys custom-keybindings "[${TMP[*]}]"


# --------------- Create Shortcut Names, Keys, and Bindings
NAMES=( "Page_Down" "Page_Up" "Home" "End" )
for name in ${NAMES[@]}
do
    NAMES+=( "shift+${name}" )
done

KEYS=( "Down" "Up" "Left" "Right" )
BINDINGS=( ${KEYS[@]} )
for idx in ${!KEYS[@]}
do
    KEYS[${idx}]="alt+${KEYS[${idx}]}"
    KEYS+=( "shift+${KEYS[${idx}]}" )
    BINDINGS[${idx}]="<Alt>${BINDINGS[${idx}]}"
    BINDINGS+=( "<Shift>${BINDINGS[${idx}]}" )
done


# --------------- Generate Shortcuts
CMD="gsettings set org.gnome.settings-daemon.plugins.media-keys.custom-keybinding:"
for i in {0..7}
do
    ${CMD}${SHORTCUT_LIST[${i}]} name "'${NAMES[${i}]}'"
    ${CMD}${SHORTCUT_LIST[${i}]} command "'bash -c \"xdotool keyup \'${KEYS[${i}]}\' key --delay 0 \'${NAMES[${i}]}\'\"'"
    ${CMD}${SHORTCUT_LIST[${i}]} binding "'${BINDINGS[${i}]}'"
done
