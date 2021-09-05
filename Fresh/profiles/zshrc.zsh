# Enable colors
autoload -U colors && colors
autoload -U add-zsh-hook

# Enable version control system (vcs) info
autoload -Uz vcs_info
precmd () { vcs_info }

setopt PROMPT_SUBST               # allows for inline functions, e.g. %{$fg[black]%}
zstyle ':vcs_info:git:*' check-for-changes true
zstyle ':vcs_info:git*' formats "%{$fg[black]%}on %{$fg[blue]%}%B%b %{$fg[red]%}%c%u%m"
# above %B - bold, %b - branch name, %c - staged changes, %u - unstaged changes, %m - ???

if [[ "${SSH_TTY}" ]]; then
	hostColour="red";
else
	hostColour="magenta";
fi;

PROMPT=$'\n'                      # '\n'    - new line
PROMPT+='%{$fg[green]%}%B%n%b'    # %n      - username
PROMPT+='%{$fg[black]%}@'         # %B (%b) - start (stop) bold face text
PROMPT+='%{$fg[$hostColour]%}%m'  # %M (%m) - full host name (host name till first '.')
PROMPT+='%{$fg[black]%}:'         #         - prints ':'
PROMPT+='%{$fg[black]%}%B%~%b '   # %~      - cwd; '%(4~|%-1~/…/%2~|%4~)' instead of '%~' paths longer than 4 are printed as 1/.../last-1/last
PROMPT+='${vcs_info_msg_0_}%b'    #         - prints version control info if available
PROMPT+=$'\n'                     # '\n'    - new line
PROMPT+='%{$reset_color%}%# '     # %#      - displays ‘#’ if the shell is running with privileges, a ‘%’ if not

# Disable the default virtualenv prompt change
export VIRTUAL_ENV_DISABLE_PROMPT=1

function virtualenv_indicator {
    # Get Virtual Env
    if [[ -z $VIRTUAL_ENV ]] then
        # In case you don't have one activated
        psvar[1]=''
    else
        # Strip out the path and just leave the env name
        psvar[1]=${VIRTUAL_ENV##*/}
    fi
}

# Call the virtualenv_indicator fct every time a prompt is created and dysplay it in the right prompt
add-zsh-hook precmd virtualenv_indicator
RPROMPT='%(1V.(%1v).)'

# History in cache directory:
HISTFILE=~/.zsh_history
HISTSIZE=10000
SAVEHIST=10000
setopt appendhistory

# Basic auto/tab complete
autoload -U compinit
zstyle ':completion:*' menu select
zmodload zsh/complist
compinit
_comp_options+=(globdots)         # Include hidden files

# Load zsh-syntax-highlighting; should be last
source /usr/local/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 2>/dev/null

# Nvidia library path, only on Ubuntu
# export LD_LIBRARY_PATH=/usr/lib/cuda/lib64:$LD_LIBRARY_PATH
# export LD_LIBRARY_PATH=/usr/lib/cuda/include:$LD_LIBRARY_PATH

# set XQuartz X11 display, only for MAC Book!
# export DISPLAY=":0"
