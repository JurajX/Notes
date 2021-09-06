# ------------------------- terminal-keybindings
key_values=(
"new-tab '<Ctrl>t'"
"new-window '<Ctrl>n'"
"close-tab '<Ctrl>w'"
"close-window '<Ctrl>q'"
"copy '<Ctrl>c'"
"paste '<Ctrl>v'"
"select-all '<Ctrl>a'"
"preferences '<Ctrl>comma'"
"full-screen '<Ctrl><Super>f'"
"zoom-in '<Ctrl>plus'"
"zoom-out '<Ctrl>minus'"
"zoom-normal '<Ctrl>0'"
"find '<Control>f'"
"find-next '<Control>g'"
"find-previous '<Control>h'"
"find-clear '<Control>j'"
"prev-tab '<Alt>Left'"
"next-tab '<Alt>Right'"
"move-tab-left '<Alt>Home'"
"move-tab-right '<Alt>End'"
"switch-to-tab-1 '<Alt>1'"
"switch-to-tab-2 '<Alt>2'"
"switch-to-tab-3 '<Alt>3'"
"switch-to-tab-4 '<Alt>4'"
"switch-to-tab-5 '<Alt>5'"
"switch-to-tab-6 '<Alt>6'"
"switch-to-tab-7 '<Alt>7'"
"switch-to-tab-8 '<Alt>8'"
"switch-to-tab-9 '<Alt>9'"
"switch-to-tab-last '<Alt>0'"
)

cmd="gsettings set org.gnome.Terminal.Legacy.Keybindings:/org/gnome/terminal/legacy/keybindings/"
for i in ${!key_values[@]}
do
    eval "${cmd} ${key_values[${i}]}"
done

echo "Sortcuts for Terminal are set!"
