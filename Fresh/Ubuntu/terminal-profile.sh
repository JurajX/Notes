#!/bin/bash

# ------------------------- terminal-profile
key_values=(
"allow-bold true"
"audible-bell true"
"background-color 'rgb(255,255,255)'"
"background-transparency-percent 50"
"backspace-binding 'ascii-delete'"
"bold-color '#000000'"
"bold-color-same-as-fg true"
"bold-is-bright false"
"cell-height-scale 1.0"
"cell-width-scale 1.0"
"cjk-utf8-ambiguous-width 'narrow'"
"cursor-background-color '#000000'"
"cursor-blink-mode 'system'"
"cursor-colors-set false"
"cursor-foreground-color '#ffffff'"
"cursor-shape 'block'"
"custom-command ''"
"default-show-menubar true"
"default-size-columns 80"
"default-size-rows 24"
"delete-binding 'delete-sequence'"
"encoding 'UTF-8'"
"exit-action 'close'"
"font 'Monospace 14'"
"foreground-color 'rgb(0,0,0)'"
"highlight-background-color '#000000'"
"highlight-colors-set false"
"highlight-foreground-color '#ffffff'"
"login-shell false"
"palette \"['rgb(0,0,0)', 'rgb(170,0,0)', 'rgb(0,170,0)', 'rgb(170,85,0)', 'rgb(0,0,170)', 'rgb(170,0,170)', 'rgb(0,170,170)', 'rgb(170,170,170)', 'rgb(85,85,85)', 'rgb(255,85,85)', 'rgb(85,255,85)', 'rgb(255,255,85)', 'rgb(85,85,255)', 'rgb(255,85,255)', 'rgb(85,255,255)', 'rgb(255,255,255)']\""
"rewrap-on-resize true"
"scrollback-lines 10000"
"scrollback-unlimited false"
"scrollbar-policy 'always'"
"scroll-on-keystroke true"
"scroll-on-output false"
"text-blink-mode 'always'"
"use-custom-command false"
"use-system-font false"
"use-theme-colors false"
"use-theme-transparency false"
"use-transparent-background false"
"visible-name 'default'"
"word-char-exceptions \"@ms nothing\""
)

profile=$( gsettings get org.gnome.Terminal.ProfilesList default )
profile=${profile:1:-1}
cmd="gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:${profile}/"

for i in ${!key_values[@]}
do
    eval "${cmd} ${key_values[${i}]}"
done

echo "Colours and fonts for terminal are set!"
