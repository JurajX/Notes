# Makefile is the recommended name for the file

include filename1 filename2         # pastes verbatim the filenames here; non-existing filenames are blamed for missing targets
-include filename                   # ignores errors if file does not exist


# ==================== Rules
target ... : prerequisite ...       # definition of a rule for a target depending on prerequisite; recipe are executed in shell
	recipe
	recipe
target : prerequisite ; recipe      # another way to define a rule for a target
	recipe
target : normal | order-only        # updates target if normal prerequisite is updated, but not if order-only prerequisite is

target :: prerequisite              # double-colon rule, explanation (https://www.gnu.org/software/make/manual/html_node)

FORCE:                              # empty target; all targets depending on it are considered to be updated

# ----- Special targets
# each recipe is executed in a new shell, by default; see .ONESHELL
.ONESHELL: target                   # target execute all recipes in one shell, only the first recipe is checked for ‘@’, ‘-’, and ‘+’
.PHONY: target                      # target is not a file (even if such a file exists); can have multiple targets on one line
.SILENT: target                     # does not print recipes
.DEFAULT:                           # the recipes of this target are run for any target that has no rules


# ==================== Recipes
# options at the beginning of a recipe
@                                   # supresses the echoing; recipes are displayed (echoed) in terminal, by default
-                                   # ignore the exit status of the command; error stops recipe execution, by default
+                                   # execute the command under 'make -n' or 'make -t' or 'make -q'

$$                                  # $ must be doubled in a recipe


# ==================== Variables
# ----- Assignments
:=                                  # defines a simple variable; all references are expanded and fixed with the definition
::=                                 # as above
=                                   # defines a recursive variable; all references are expanded every time the variable is expanded
?=                                  # defines a recursive variable if the variable has not yet been defined
!=                                  # defines a recursive variable that stores the result of shell execution of the RHS
+=                                  # appends a variable with the RHS; if variable does not exist it defines a recursive variable

a := $($(x))                        # a will be expantion of the content of x

$(var) ${var}                       # two ways of a variable expansion

target: var-assignment              # defines a target specific variable; all prerequisites inherits it as well
pattern: var-assignment             # defines a pattern specific variable; i.e. target specific variable for all targets matching the %-pattern

# ----- Substitution reference
foo := a.o b.o l.a c.o              # helper def
$(foo:.o=.c)                        # gives a.c b.c l.a c.c; is equivalent to '$(patsubst %a,%b,var)'
$(foo:%.o=%.c)                      # gives a.c b.c l.a c.c; is equivalent to '$(patsubst a,b,$(var))'

# ----- Special variables
SHELL                               # defines the shell to be used; default is '/bin/sh'
.SHELLFLAGS                         # defines the arguments to be passed to shell; default '-c'

CURDIR                              # set by make to the directory of invocation; is same for all recursive invocations
MAKE                                # path to make; should be always used in recursive use, i.e. ${MAKE}

MAKEFILE_LIST                       # holds all makefiles that have been included

# ----- Special keywords
define multiline-var                # defines a multiline variable
first line
second line
endef
undefine var                        # undefines a variable; behaves as if the var was never set

private var                         # visible in global scope, not in targets; prerequisites won't inherit var in target specific variable

# the assignments in makefile are ignored for variables defined on command line
override                            # allows to re-assign or append a command-line defined variable

# a variable needs to be exported in order to be seen in recursions
export                              # export all variables by default
export var = value                  # defines and exports a recursive variable 'var'
export var := value                 # same as above just for a simple variable

export var                          # export previously defined variable 'var'
unexport var                        # unexport previously defined variable 'var'


# ==================== Conditionals
ifXX (cond)                         # if cond is true
else ifXX (cond)                    # else if cond is true
else                                # else
endif


ifeq (a, b)                         # test equality; alternative forms: ifeq 'a' 'b'     ifeq "a" "b"     ifeq "a" 'b'     ifeq 'a' "b"
ifneq (a, b)                        # test inequality; alternatives as above
ifdef (a)                           # test if defined; alternatives similar to the above
ifndef (a)                          # test if not defined; alternatives similar to the above

# ==================== Functions

$(fn args) ${fn args}               # function call

# ----- String functions
$(subst from,to,txt)               # substitution
$(patsubst ptrn,replcmnt,txt)      # pattern substitution; ptrn can contain % (wildcard), % is excaped with '\'
$(strip str)                       # strips leading and trailing whitespaces, sequence of inner whitespaces are replaced by a single whitespace
$(findstring substr,str)           # if substr is found it's returned; otherwise an empty string is returned
$(filter pattern ...,text)         # returns whitespace separated elements of text matching any of the patterns
$(filter-out pattern ...,text)     # returns whitespace separated elements of text that do not match any of the patterns
$(sort list)                       # returns sorted list
$(word n,txt)                      # returns n-th word; 1-indexed; if n>len(txt) an returns empty string
$(wordlist i,j,txt)                # returns [i, j] elements of the txt; if j>len(txt) returns [i len(txt)]; if i>len(txt) returns an empty string
$(words txt)                       # returns the number of words in the txt
$(firstword names...)              # returns the first word in the given sequence; same as $(word 1,text)
$(lastword names...)               # returns the last word in the given sequence

# ----- Filesystem functions
$(dir names...)                    # extract the directory-part of each file name in names
$(notdir names...)                 # extract all but the directory-part of each name
$(suffix names...)                 # extract all file suffixes; if element has no suffix it produces an empty string
$(basename names...)               # extract all but the suffix
$(addsuffix suffix,names...)       # add suffix to names
$(addprefix prefix,names...)       # adds prefix to the names
$(join list1,list2)                # concatinates n-th words from list1 and list2; i.e. list1[1]+list2[1] list1[2]+list2[2]...
$(wildcard pattern)                # returns all files in the current dir fulfilling the pattern
$(realpath names...)               # returns list of canonical absolute paths
$(abspath names...)                # returns list of absolute paths

# ----- Conditional functions
# conds can be normal string, non-empty string string is evaluated as true
$(if cond,true-part[,false-part])  # return either the true-part or the false-part
$(or cond1[,cond2[,cond3…]])       # returns the first non-empty cond or an empty string
$(and cond1[,cond2[,cond3…]])      # returns the last cond if all cond are evaluated to true; otherwise an empty string

# ----- Special functions
$(foreach var,list,txt)            # see https://www.gnu.org/software/make/manual/html_node/Foreach-Function.html#Foreach-Function
$(file op filename[,text])         # i/o for files
$(call variable,param,param,...)   # see https://www.gnu.org/software/make/manual/html_node/Call-Function.html#Call-Function
$(value var)                       # use the value of a var without having it expanded
$(eval params...)                  # see https://www.gnu.org/software/make/manual/html_node/Eval-Function.html#Eval-Function
$(origin var)                      # returns one of: undefined, default, environment, environment override, file, command line, override, automatic
$(flavor var)                      # returns one of: undefined, recursive, simple
$(error text...)                   # see https://www.gnu.org/software/make/manual/html_node/Make-Control-Functions.html#Make-Control-Functions
$(warning text...)                 # see https://www.gnu.org/software/make/manual/html_node/Make-Control-Functions.html#Make-Control-Functions
$(info text...)                    # see https://www.gnu.org/software/make/manual/html_node/Make-Control-Functions.html#Make-Control-Functions
$(shell cmd)                       # evaluates cmd in shell, returns the output

# ----- Wildcard
# wildcard expansion does not take place when:
#  - a variable is set, or
#  - inside arguments of a function

obj = *.o                           # all object files in the directory; recursive variable, obj contains '*.o'
obj := $(wildcard *.o)              # all object files in the directory; simple variable, obj contains the file names


# ==================== Processing of Makefile
# two phase approach:
#  - 1st phase:
#    - read all the makefiles,
#    - internalise variables and their values, and implicit and explicit rules
#    - build a dependency graph of all targets and their prerequisites
#  - 2nd phase:
#    - determine which targets to update
#    - run the recipes

# two types of expansion:
#  - immediate -> this happens during the 1sh phase
#  - deffered  -> it's not immediate; i.e. delayed until it is used
#                     either when referenced in an immediate context
#                     or when needed during the 2nd phase

.SECONDEXPANSION                    # see https://www.gnu.org/software/make/manual/html_node/Secondary-Expansion.html#Secondary-Expansion

# expansion types for different constructs:
immediate = deferred
immediate ?= deferred
immediate := immediate
immediate ::= immediate
immediate += deferred or immediate  # immediate if the variable was previously set as a simple variable (':=' or '::=')
immediate != immediate

define immediate
  deferred
endef

define immediate =
  deferred
endef

define immediate ?=
  deferred
endef

define immediate :=
  immediate
endef

define immediate ::=
  immediate
endef

define immediate +=                 # immediate if the variable was previously set as a simple variable (':=' or '::=')
  deferred or immediate
endef

define immediate !=
  immediate
endef

immediate : immediate ; deferred
	deferred
