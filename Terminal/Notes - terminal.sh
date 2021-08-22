# key shortcuts:
# ctrl + a                  # go to the beginning of line
# ctrl + e                  # go to the end of line
# ctrl + u                  # delete everything until the cursor
# ctrl + k                  # delete everything after the cursor
# ctrl + r                  # reverse interactive search
# alt + <- or ->            # jumps by words
# alt + click               # jumps to the clicked location
# !num                      # re-runs num-th command from history

# create aliases, paste it in ~/.bash_profile
# alias name="statement1; statement2; etc."


# https://ss64.com/osx/
man cmd                     # lists man pages for cmd, press q for exit


# ===== Print Working Directory, Change Directory
pwd                         # print working directory
cd                          # change directory
    /                       # root directory
    -                       # previous directory
    ~                       # home directory

# ===== Open Files, Concatinate Files
open file                   # opens a file in default application
cat file1 file2             # concatinates file1 and file2, can be written to another file using > another_file
cat <(cmd1) <(cmd2)         # concatinates outputs of cmd1 and cmd2


# ===== List
ls [opt] [path]             # list current directory
    -l                      # ...list files in the long format
    -a                      # ...list also items starting with '.'


# ===== User Groups and Rights
drwxrwxrwx N owner group    # directory, read, write, execute (owner, group, everyone); N - number of hard links, owner, group
                            # for dirs, r -> listing content of the dir; w -> create, delete change metadata of files; x -> enter the directory
chmod OGA myfile            # r = 4, w = 2, x = 1; OGA = 640 means rw-r-----


# ===== Create Directories and Files
mkdir [opt] [mode] path     # make directory
    -p                      # create intermediate folders
    -v                      # verbose, i.e. list folders as they are created
    -m mode                 # chmod file permission bits

touch [opt] file            # change time stamp of a file, or create one
    -a                      # ...change access time
    -c                      # ...do not create file if it does not exist
    -m                      # ...change modification time


# ===== Copy, Move, Remove
cp [opt] src trgt           # copy source to target
    -r                      # ...recursively, copies the entire file hierarchy

mv [opt] src trgt           # move (rename) src to trgt
    -n                      # ...do not overwrite existing file
    -i                      # ...prompt before moving a file which would overwrite another
    -f                      # ...force, i.e. always overwrite without prompt
    -v                      # ...verbose

rm [opt]                    # remove files and folders
    -d                      # ...atemp to remove folder (must be empty)
    -f                      # ...force, i.e. without confirmation
    -i                      # ...prompt before removing
    -P                      # ...overwrite file 3x before deleting
    -r                      # ...recursively, remove the entire file hierarchy
    -v                      # ...verbose


# ===== Searching Paths for Files
find [path] expression      # searches path hierarchy for filename(s) that meet a desired criteria
    -type d, f              # ...finds only directories, files
    -name 'te*'             # ...looks for a file with starting with 'te'
    -iname 'te*'            # ...as above but case-insensitive
    -mmin -10, +10          # ...modified in last 10 minutes, longer than 10 minutes ago
    -mtime, amin, cmin      # ...modified days, accessed minutes, created minutes, etc...
    -size 5M                # ...over 5 Mb, similarly k(bytes) G(bites)
    -maxdepth 1             # ...searched only depth 1 (current directory)
    -exec cmd {} +          # ...executes cmd on files/directories returned by find


# ===== Redirecting Inputs and Outputs
cmd < STH                   # makes STH as input to cmd; STH is file or another input
cmd > STH                   # takes the output of cmd and redirects it to STH
cmd >> STH                  # takes the output of cmd and appends it to STH
cmd1 | cmd2                 # pipe, forwards output of cmd1 to input of cmd2


# ===== Miscellaneous
# to install new GNU grep run 'brew install grep --with-default-names'
grep [opt] 'srch str' file  # Global Regular Expression Print, use ./* for all files in ./
    -c                      # ...lists files and displays number of mathces in them
    -i                      # ...case insensitive
    -l                      # ...displays only file name of match
    -n                      # ...shows also the line number
    -r                      # ...recursively, i.e. search directory recursively
    -w                      # ...searches only whole words
    -A n                    # ...shows also n lines after
    -B n                    # ...shows also n lines before
    -C n                    # ...shows also n lines before and after


rsync [opt] src [src] trgt  # remote synchronization of file tree
    -a                      # ...archive, as '-r' but preserves symlinks, modification times, etc.
    -n                      # ...(--dry-run), use with verbose (-v)
    -r                      # ...recursively, sync entire file hierarchy
    -v                      # ...verbose, use with --dry-run (-n)
    -z                      # ...compress file data
    -P                      # ...show progress and keep partially transferred files
    --del                   # ...delete files that don't exist on the src side


# ===== Scripting
#!/usr/bin/env python       # as a first line tells bash to execute the (python) script with python binary that is found automatically

shellcheck FILE             # diagnoses the file for problems
$_                          # argument provided to the last called function
cmd1; cmd2                  # concatinates commands
&& || true false            # and or true false
var=$(cmd)                  # stores return value of cmd in var
"$(cmd)" '$(cmd)'           # double quotes expand commands, single quotes do not

fct () {                    # defines a fct
    cmd1 "$1" "$2"          # calls cmd1 with the first and second arguments provided to fct
    for arg in "$@"; do     # loops over all provided arguments
        cmd2 arg
    done
}

for ARGinARGS               # for loop
do
    STATEMENTS
done

if [[ TEST-COMMAND ]]       # if statement
then
    STATEMENTS
elif [[ TEST-COMMAND ]]
then
    STATEMENTS
else
    STATEMENTS
fi


# ===== Job Control
SIGHUP                      # signal sent to a program when closing a (terminal) session

SIGINT                      # signal interrupt - terminate the process
SIGTSTP                     # signal stop - suspend execution of the process
SIGQUIT                     # signal quit - terminate and dump core
SIGINFO                     # signal info - show information about the running command

^C ^Z ^\ ^T                 # SIGINT, SIGTSTP, SIGQUIT, SIGINFO

jobs                        # list all jobs running in the background
kill -SIGNAL                # send SIGNAL to a job

bg JOB_SPEC                 # place job(s) in the background, as if they had been started with '&'
bg JOB_SPEC                 # place job in the foreground
                            # JOB_SPEC is e.g. %1 (for the first job); if omitted, the current job is used
