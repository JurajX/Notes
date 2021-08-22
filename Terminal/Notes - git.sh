git --version                           # git verstion
git cmd --help                          # display help for cmd
git config --list                       # list git configuration
git config --global user.name "Juraj"   # set global name for git
git config --global user.email "jurajvrabel1@gmail.com"

# creating/cloning project
git init                                # init a new Git repository in cwd
touch .gitignore                        # contain files to be ignored, e.g. .DS_Store
git clone url/path1 paht2               # doenload repository from url or path1 to path2

# working <-> staging environment
git status                              # display git's relations to the existing files
git add                                 # move from working to staging
    file                                # ...move file
    my_dir                              # ...move all files from my_dir
    -A                                  # ...move all files
    -n                                  # ...dry run
    -u                                  # ...move all modified and deleted, not untracked
    -p                                  # ...interactive staging of changes (parts of files)
git reset                               # move all files from staging to working
    file                                # ...move file
git checkout -- my_file                 # discards changes in the working environment
git rm --cached my_file                 # removes my_file from staging environment
git clean [opt]                         # deletes untracked
    -d                                  # ...directories
    -f                                  # ...files
    -n                                  # ...dry-run
git stash                               # stashing:
    save "msg"                          # ...revert changes in working environment but save them
    list                                # ...list saved stashes
    apply stash@{n}                     # ...load stashed changes back to working environment
    pop                                 # ...load the topmost stash and drop it from saved
    drop stash@{n}                      # ...delete the stash@{n}
    clear                               # ...delete all stashes

# history, changes, commits
git log                                 # show history of commits
git log --all --graph --decorate        # show history of commits as a graph
git diff                                # shows made modifications to files
git diff FILE                           # shows made modifications to the FILE
git diff CommitHash1 CommitHash2        # shows modifications between two commits
git commit -m "My_message"              # makes commit
    --amend                             # ...amends the previous commit with new msg, files, etc.
git revert CommitHash                   # new commit reverting changes of the commit CommitHash
git cherry-pick CommitHash              # copies (without deleting) CommitHash to the active branch
git reset CommitHash                    # reset active branch to CommitHash, keep all modified files in working env
    --soft                              # ...keep all modified files in staging env
    --hard                              # ...delete all modified tracked files,
git reflog                              # shows history, one can...
git checkout LogHash                    # ...and ...
git branch backup                       # ...rescue deleted files

# pushing and pulling
git fetch; git merge                    # the two are equivalent to git pull
git pull origin branch                  # pulls things from master branch on GitHub
git pull --rebase origin branch         # identifies remote and local branches, they won't be separate things
git push origin my_branch               # uploads local master to GitHub
    -u                                  # ...link local and remote; use only: git push, git pull
    -d (--delete) my_branch             # ...delete branch from remote

# branches
git branch                              # displays all branches
    -a                                  # ...display remote and local branches
    -r                                  # ...display only remote branches
    -d                                  # ...delete branch, branch must be fully merged
    -D (-df)                            # ...force delete branch
git branch my_branch                    # creates a new branch named my_branch
    -d                                  # ...delete my_branch from local
git checkout my_branch                  # makes my_branch active
    -b                                  # ...creates my_branch and makes it active
    -t <remote>/<branch>                # ...fetches remote branch from remote (usually origin)

git merge my_branch                     # merges my_branch with active branch


# bisect
git bisect ???                          # binary searches history to find the first commit that did something, e.g. broke a testcase


# Cleaning the old commit history and keep the code in the current state
git checkout --orphan latest_branch     # checkout to a new branch
git add -A                              # add all the files to the new branch
git commit -am "commit message"         # commit the changes
git branch -D master                    # delete the master branch
git branch -m master                    # rename the current branch to master
git push -f origin master               # force update your repository
