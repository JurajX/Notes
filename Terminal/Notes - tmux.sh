#     ==================== tmux ====================     #
tmux ls                 # list sessions
tmux new                # creates new session
tmux new    -s name     # creates new session with name
tmux a                  # attach to the last session
tmux attach             # attach to the last session
tmux attach -t name     # attach to the session
tmux kill-session -a    # closes all sessions


# --- Key Commands
ctrl+b  # is the prefix

?       # list all key commands
:       # written commands

d       # detach from session
$       # rename session

    # window mngt
c       # create a new window
,       # rename the active window
w       # list windows
p       # previous window
n       # next window

    # split panes (=window), to close pane: 'ctrl+d' or type 'exit'
""      # split horizontally (only one ")
%       # split vertically
q       # pane number (+type number to go to the window)
arrow   # switch pane
o       # go to the next pane

# --- Written Commands
split-window        # splits window horizontally

# --- Sessions
tmus new -s name    # creates new session
