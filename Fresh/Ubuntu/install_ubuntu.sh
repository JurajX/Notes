#!/bin/bash

dir="/home/${USER}/.config/gtk-3.0/"

if [ -d "${dir}" ]; then
    echo "Directory ${dir} already exists, skipping."
else
    mkdir -p "${dir}"
    echo "Directory ${dir} created."
fi

$( cp gtk.css ${dir} )
$( "remap_system_keys.sh" )
$( "set_terminal_shortcuts_and_colours.sh" )
