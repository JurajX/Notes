# --------------- Fonts
eval "gsettings set org.gnome.desktop.wm.preferences titlebar-font 'Ubuntu Bold 16'"
eval "gsettings set org.gnome.desktop.interface monospace-font-name 'Ubuntu Mono 18'"
eval "gsettings set org.gnome.desktop.interface document-font-name 'Sans 16'"
eval "gsettings set org.gnome.desktop.interface font-name 'Ubuntu 16'"
eval "gsettings set org.gnome.desktop.wm.preferences titlebar-font 'Ubuntu Bold 16'"

# --------------- Themes
# first you need to download
#  - the gtk  theme from here: https://www.gnome-look.org/p/1357889 and unpack it to ~/.themes folder; and
#  - the gtk  theme from here: https://www.gnome-look.org/p/1403328 and unpack it to ~/.themes folder; and
#  - the icon theme from here: https://www.gnome-look.org/p/1405756 and unpack it to ~/.icons  folder
eval "gsettings set org.gnome.desktop.interface cursor-theme 'DMZ-Black'"
eval "gsettings set org.gnome.desktop.interface icon-theme 'WhiteSur'"
eval "gsettings set org.gnome.desktop.interface gtk-key-theme 'Default'"
eval "gsettings set org.gnome.desktop.interface gtk-theme 'WhiteSur-light-solid'"
eval "gsettings set org.gnome.desktop.wm.preferences theme 'Adwaita'"
eval "gsettings set org.gnome.shell.extensions.user-theme name 'Orchis-light-compact'"      # shell theme name

eval "gsettings set org.gnome.desktop.interface show-battery-percentage true"
eval "gsettings set org.gnome.desktop.interface clock-show-date true"
eval "gsettings set org.gnome.desktop.interface toolbar-icons-size 'large'"

eval "gsettings set org.gnome.desktop.interface scaling-factor 0"
