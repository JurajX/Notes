import argparse

p = argparse.ArgumentParser(
    prog=None,
    usage=None,
    description=None,
    epilog=None,
    parents=[],
    formatter_class=argparse.HelpFormatter,
    prefix_chars='-',
    fromfile_prefix_chars=None,
    argument_default=None,
    conflict_handler='error',
    add_help=True,
    allow_abbrev=True
)

p.add_argument(
    name or flags...            # Either a name or a list of option strings, e.g. foo or -f, --foo.
    [, action]                  # The basic type of action to be taken when this argument is encountered at the command line.
    [, nargs]                   # The number of command-line arguments that should be consumed.
    [, const]                   # A constant value required by some action and nargs selections.
    [, default]                 # The value produced if the argument is absent from the command line.
    [, type]                    # The type to which the command-line argument should be converted.
    [, choices]                 # A container of the allowable values for the argument.
    [, required]                # Whether or not the command-line option may be omitted (optionals only).
    [, help]                    # A brief description of what the argument does.
    [, metavar]                 # A name for the argument in usage messages.
    [, dest]                    # The name of the attribute to be added to the object returned by parse_args().
)

p.parse_args(
    args=None,                  # List of strings to parse. The default is taken from sys.argv.
    namespace=None              # An object to take the attributes. The default is a new empty Namespace object.
)

p = argparse.ArgumentParser()               # returns a parser
p.add_argument(                             # adding a positional argument
    "name",                                 # name of the arg
    help="help msg",                        # help message of the arg
    type=X)                                 # cast the input into X, e.g. int
a = p.parse_args()                          # parses cmd line args

a.name                                      # returns the parsed argument
