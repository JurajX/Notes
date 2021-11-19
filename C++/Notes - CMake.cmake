# ========================== Do's and Don'ts
# ------- CMake Antipatterns
# Do not use global functions: This includes link_directories, include_libraries, and similar
# Don't add unneeded PUBLIC requirements: avoid forcing something on users that is not required (-Wall); make these PRIVATE instead
# Don't GLOB files: if you add files you'll have to re-run CMake (CMake 3.12 adds CONFIGURE_DEPENDS flag that makes it better)
# Link to built files directly: always link to targets if available
# Never skip PUBLIC/PRIVATE when linking: This causes all future linking to be keyword-less

# ------- CMake Patterns
# Treat CMake as code: it is code, it should be as clean and readable as all other code
# Think in targets: your targets should represent concepts; make an (IMPORTED) INTERFACE target for anything that should stay together
# Export your interface: you should be able to run from build or install
# Write a Config.cmake file: this is what a library author should do to support clients
# Make ALIAS targets to keep usage consistent: using add_subdirectory and find_package should provide the same targets and namespaces
# Combine common functionality into clearly documented functions or macros: functions are better usually
# Use lowercase function names: CMake functions and macros can be called lower (always use) or upper case (reserved for variables)
# Use cmake_policy or range of versions: policies change for a reason, only piecemeal set OLD policies if you have to


# ========================== Basics
# ------- Minimum Version
cmake_minimum_required(VERSION 3.22)
cmake_minimum_required(VERSION 3.1...3.15)  # from version CMake 3.12

# ------- Setting a Project
project(
    MyProject
    VERSION 1.0.0
    DESCRIPTION "Very nice project"
    LANGUAGES C CXX CUDA
)

# ------- Making an Executable
add_executable(
    exe1
    src1.cpp
    hdr1.hpp
)

# ------- Making a Library
# meaning of options:
#  - STATIC -> archives of object files for use when linking (bigger executable)
#  - SHARED -> linked dynamically and loaded at runtime
#  - MODULE -> are plugins, not linked into other targets but may be loaded dynamically at runtime using dlopen-like functionality
add_library(
    lib1 STATIC     # options are STATIC, SHARED, or MODULE
    src2.cpp
    src2.h
)

# ------- Targets
# meaning of options:
#  - INTERFACE -> only dependencies have include
#  - PUBLIC    -> target and dependencies have include
#  - PRIVATE   -> only target has include
target_include_directories(
    target          # options are INTERFACE, PUBLIC, or PRIVATE
    PUBLIC include  # folder
)

# ------- Linking
add_library(lib2 STATIC another.cpp another.h)

target_link_libraries(      # more details https://cmake.org/cmake/help/latest/command/target_link_libraries.html
    lib2
    PUBLIC lib1             # options are INTERFACE, PUBLIC, or PRIVATE; same meaning as in Targets
)

# ------- Testing
include(CTest)

# ========================== Variables and the Cache
# ------- Local Variables
# set fct has an optional PARENT_SCOPE, if present the variable is set in the parent scope
set(MY_VARIABLE "value")                # sets a variable
set(MY_LIST "one;two")                  # sets a list, i.e. semicolon-separated list
set(MY_LIST "one" "two")                # as above, literally becomes the above

separate_arguments(MY_VARIABLE)         # turns a space separated string into a list

set(
    MY_CACHE_VARIABLE "VALUE"           # cache variable, does not overwrite existing cache entries by default
    CACHE                               # provide user-settable values, e.g. from command line
    STRING                              # one of BOOL, FILEPATH, PATH, STRING, or INTERNAL
    "Description"
    FORCE                               # optional, does overwrite existing cache entries
)
mark_as_advanced(MY_CACHE_VARIABLE)     # advanced vars will not be displayed in cmake GUIs unless the show advanced option is on

option(MY_OPTION "Description" ON)      # if already set as a normal or cache variable, then the command does nothing; possible values ON, OFF

# ------- Properties
set_property(                           # generic command to set a property
    TARGET TargetName
    PROPERTY CXX_STANDARD 11)

set_target_properties(                  # specific command to set a property for a target
    TargetName
    PROPERTIES CXX_STANDARD 11
)

get_property(                           # generic command to get a property
    ResultVariable
    TARGET TargetName
    PROPERTY CXX_STANDARD
)


# ========================== Programming in CMake
# ------- Control flow
# Unary: NOT, TARGET, EXISTS (file), DEFINED, etc.
# Binary: STREQUAL, AND, OR, MATCHES (regular expression), VERSION_LESS, VERSION_LESS_EQUAL (CMake 3.7+), etc.
# Parentheses can be used to group
if("${MY_VARIABLE}")
    # True if variable is not false-like
else()
    # Note that undefined variables would be `""` thus false
endif()

# ------- Generator Expressions
# https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html
# used for e.g. specifying a different location for build and install directories
$<KEYWORD>              # evaluates to a piece of information relevant for the current configuration
$<KEYWORD:value>        # KEYWORD that controls the evaluation, and value is the item to evaluate

target_include_directories(
    MyTarget
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# ------- Macros and Functions
# the difference between a function and a macro is scope; macros don't have one

function(SIMPLE POS_ARG)    # a fct taking one positional argument
    # ARGN lists all given args except POS_ARG
    # ARGV lists all given args including POS_ARG
    message(STATUS "Simple arguments: ${POS_ARG}, followed by ${ARGN}")
    set(${POS_ARG} "From SIMPLE" PARENT_SCOPE)
endfunction()

simple(This Foo Bar)            # fct simple call
message("Output: ${This}")      # return value from fct simple; This contains "From SIMPLE"

# ------- Argument Parsing
function(COMPLEX)
    cmake_parse_arguments(
        COMPLEX_PREFIX
        "SINGLE;ANOTHER"
        "ONE_VALUE;ALSO_ONE_VALUE"
        "MULTI_VALUES"
        ${ARGN}
    )
endfunction()
# Inside the function after this call, you'll find:
complex(SINGLE ONE_VALUE value MULTI_VALUES some other values)
COMPLEX_PREFIX_SINGLE = TRUE
COMPLEX_PREFIX_ANOTHER = FALSE
COMPLEX_PREFIX_ONE_VALUE = "value"
COMPLEX_PREFIX_ALSO_ONE_VALUE = <UNDEFINED>
COMPLEX_PREFIX_MULTI_VALUES = "some;other;values"
COMPLEX_PREFIX_UNPARSED_ARGUMENTS = <UNDEFINED>         # contains optional positional arguments

# ------- Message
# message level
#  - FATAL_ERROR    -> error, stop processing and generation
#  - SEND_ERROR     -> error, continue processing, but skip generation
#  - WARNING        -> warning, continue processing
#  - AUTHOR_WARNING -> warning (dev), continue processing
#  - DEPRECATION    -> deprecation error or warning if variable CMAKE_ERROR_DEPRECATED or CMAKE_WARN_DEPRECATED is enabled, else no message
#  - NOTICE (none)  -> important message printed to stderr to attract user's attention
#  - STATUS         -> interesting messages that users might be interested in; ideally these should be concise but informative
#  - VERBOSE        -> detailed informational messages intended for users; should provide additional details
#  - DEBUG          -> detailed informational messages intended for developers working on the project itself
#  - TRACE          -> fine-grained messages with very low-level implementation details; log level normally removed before releasing
message(STATUS "msg")       # print message with STATUS level


# ========================== Communication with Code
# ------- Configure File
# file: Version.h.in
#pragma once

#define MY_VERSION_MAJOR @PROJECT_VERSION_MAJOR@
#define MY_VERSION_MINOR @PROJECT_VERSION_MINOR@
#define MY_VERSION_PATCH @PROJECT_VERSION_PATCH@
#define MY_VERSION_TWEAK @PROJECT_VERSION_TWEAK@
#define MY_VERSION "@PROJECT_VERSION@"

# file: CMake
configure_file (
    "${PROJECT_SOURCE_DIR}/include/My/Version.h.in"
    "${PROJECT_BINARY_DIR}/include/My/Version.h"
)


# ========================== Adding Features
# ------- C++11 and Beyond
# proper way to set C++ level; if a target further down the dependency chain specifies a higher C++ level, this interacts nicely
target_compile_features(myTarget PUBLIC cxx_std_20)
set_target_properties(myTarget PROPERTIES CXX_EXTENSIONS OFF)

# ------- Position independent code (-fPIC flag)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)                                 # globally
set_target_properties(lib1 PROPERTIES POSITION_INDEPENDENT_CODE ON)     # on target

# ------- Project Structure
- project
  - .gitignore
  - README.md
  - LICENCE.md
  - CMakeLists.txt
  - cmake
    - FindSomeLib.cmake
    - something_else.cmake
  - include
    - project
      - lib.hpp
  - src
    - CMakeLists.txt
    - lib.cpp
  - apps
    - CMakeLists.txt
    - app.cpp
  - tests
    - CMakeLists.txt
    - testlib.cpp
  - docs
    - CMakeLists.txt
  - extern
    - googletest
  - scripts
    - helper.py
