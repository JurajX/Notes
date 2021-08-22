--------------------------------------------IPYTHON

http://notebookcloud.appspot.com  # Cloud computing.

ipython                       # Starts ipython from the terminal.
ipython notebook              # Starts ipython (HTML) notebook.

                          -----BASH COMMANDS-----
!cmd                          # Executes 'cmd' as in terminal

                          -----FUNCTIONS-----

import LIBRARY as LIB         # Imports LIBRARY and stores it in the namespace LIB.
reload(LIBRARY)               # Reloads LIBRARY (e.g. when you make a changes to LIBRARY).
dreload(LIBRARY)              # Deep reload of LIBRARY (including the dependencies).

tab                           # Completes commands (variables,modules,file_paths,function arguments, .methods, ._methods).
?                             # Introspection (put before or after an object)-shows a general info about the object.
??                            # Will also show function's source code if possible.
?                             # Searches IPython namespaces e.g. ?np.*load* gives all names matching the wildcard (*).
<Ctrl+C>                      # KeyboardInterrupt.

_                             # Calls the very last output.
__                            # Calls the one before the last.
_NUMBER                       # Returns the output out[NUMBER].
_iNUMBER                      # Returns the input in[NUMBER].
exec STRING                   # Executes command saved in STRING, e.g. exec _i12.



                          -----MAGIC COMMANDS-----

%magic                        # Displays detailed documentation for all of the available magic commands.
%automagic                    # Allows using magic commands without % sign.
%lsmagic                      # Displays all magic commands

%T_CMD                        # T_CMD = terminal command, e.g. ls or !rm 'file' removes 'file'.
!CMD                          # Executes every command, CMD, after ! in the system shell.
%alias MY_ALS CMD             # Creates alias MY_ALS for shell command CMD. Aliases are forgotten after closing the session.
%bookmark                     # Is same as alias but is not forgotten after closing; -l option lists all bookmarks.

%run my_file.py               # Runs the file "my_file"; -d Flag invokes the debugger, press 's' to step through.
%run -i my_file.py            # In addition, gives my_file.py access to already defined variables.
%prun my_file.py              # Prints list of times spent on each function in my_file.py.
%lprun -f fct1 -f fct2 'S'    # Prints list of times spent on each line of code of fct1, and fct2 in statement S.
%load my_file.py              # Loads the file "my_file" into the environment.
%paste                        # Pastes whatever text is in the clipboard and executes it as a sibgle block.
%cpaste                       # Lets you paste more before executing.
%reset                        # Resets the namespace by removing all names defined by the user.

%matplotlib inline            # Matplotlib will use Jupyter’s own backend.
%pylab inline                 # Pylab will use Jupyter’s own backend.

%time 'PRC'                   # Reports the total execution time of the process PRC.
%timeit 'PRC'                 # Reports an average execution time (over multiple runnings) of the process PRC.

%logstart, %logstop           # Starts/stops logging the entire session, inc. in, out, and previous commands.
%logoff, %logon, %logstate    # Temporarily stops logging/resumes logging/prints logging state.
%xmode                        # Setting error description from minimal to verbose.
%debug                        # Steps into the stack; h displays command list; help CMD !var prints var value.
%pdb                          # Stepping into the stack/debug.
