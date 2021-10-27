#!/bin/zsh

virtualenv ~/.venv/linters
source ~/.venv/linters/bin/activate

pip3 install --upgrade pip
pip3 install --upgrade 'python-language-server[all]'

deactivate

brew install shellcheck     # sudo apt install shellcheck
brew install llvm           # sudo apt install llvm

apm install build
apm install build-cmake

apm install script
apm install hydrogen
apm install latex

apm install language-cmake
apm install language-cuda
apm install language-kotlin
apm install language-latex
apm install language-lua

apm install file-icons
apm install minimap
apm install todo-show

apm install autocomplete-cmake
apm install autocomplete-clang
apm install git-plus
apm install git-blame
apm install ftp-remote-edit
apm install teletype

apm install linter
apm install busy-signal
apm install linter-ui-default
apm install intentions

# apm install linter-clang-tidy
# linter-clang-tidy, set path to: /usr/local/Cellar/llvm/12.0.1/bin/clang-tidy
apm install linter-flake8
apm install linter-shellcheck
apm install linter-kotlin
apm install linter-chktex

apm install python-isort
# manually as 'apm install python-yapf' not working
curl -L -o ~/Downloads/python-yapf.zip https://github.com/blacktop/atom-python-yapf/zipball/master
cd ~/Downloads
unzip ~/Downloads/python-yapf.zip
rm ~/Downloads/python-yapf.zip
mv ~/Downloads/blacktop-atom-python-yapf-* ~/.atom/packages/python-yapf
cd ~/.atom/packages/python-yapf
apm install
cd ~

# change theme
# NEVER INSTALL KITE!

# adjust keymap file
# 'body':
#   'ctrl-tab': 'pane:show-next-item'
#   'ctrl-shift-tab': 'pane:show-previous-item'
#   'alt-cmd-right': 'pane:show-next-recently-used-item'        # leave out in Ubuntu
#   'alt-cmd-left': 'pane:show-previous-recently-used-item'     # leave out in Ubuntu
# 'atom-text-editor':
#   'alt-space': 'autocomplete-plus:activate'
#   'alt-right': 'editor:move-to-end-of-screen-line'            # only keep for Ubuntu
#   'alt-left': 'editor:move-to-first-character-of-line'        # only keep for Ubuntu
#   'alt-up': 'core:page-up'                                    # only keep for Ubuntu
#   'alt-down': 'core:page-down'                                # only keep for Ubuntu
# Editor
#     - font size 16
#     - set preffered line length 150
#     - mark scroll past the end
#     - mark show indent guide
#     - mark show invisibilities
#     - mark soft wrap
#     - mark soft wrap at preffered lenght
#     - tab lenght to 4
#     - tab type soft

# build-cmake, change line 54 in cmake.js to: "/[\*\s]{3}(.*)\s*=\sGenerates?(.*\.|.*\s*.*\.)(\s*Optional\s\[arch\]\scan\sbe\s(".*").)?/g,"
# autocomplete-plus in Settings change 'keymap for confirming the suggestion' from 'tab and enter' to 'enter'
# autocomplete-clang, set path to: /usr/local/Cellar/llvm/12.0.1/bin/clang; on ubuntu to clang-10
# spell-check in Settings add 'text.tex.latex' to Grammars
# linter change Lint on Change Interval to 3000
# linter-flake8 add path /Users/juraj/.venv/linters/bin/flake8
# linter-flake8 change line length to 150
# python-isort add path /Users/juraj/.venv/linters/bin/isort
# copy python-yapf setting file style.yapf to /Users/juraj/.venv/linters/
# python-yapf add path /Users/juraj/.venv/linters/bin/yapf
# python-yapf add path to style setting /Users/juraj/.venv/linters/style.yapf
