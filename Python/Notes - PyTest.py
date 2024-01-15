import pytest


# ========================== Running Tests
# ------- running tests
# pytest file.py                        # run all tests in file.py
# pytest file.py::test_name             # run only test_name from file.py
# pytest file.py::TestClass             # run only tests in the TestClass from file.py
# pytest file.py::TestClass::test_name  # run only test_name from the TestClass from file.py
# pytest file1.py file2.py              # runs all tests in file1.py and file2.py
# pytest dir                            # recursively searches for all tests in the dir and all subdirectories of dir and executes them

# ------- options
# pytest
#     -k EXPR                           # only runs tests/classes that match the given EXPR; and, or, not can be used; e.g. 'raises and not delete'
#     -m MARKEXPR                       # only runs tests/classes that match the given MARKEXPR, i.e. tests decorated with @pytest.mark.MARK ->
#                                       # MARKEXPR can be "mark1 or mark2" or "mark1 and mark2" or "mark1 and not mark2"
#     -x, --exitfirst                   # exits instantly on first error or failed test
#     --maxfail=N                       # exits after first N failures or errors
#     --capture=M                       # per-test capturing M is one of fd|sys|no
#     -s                                # shortcut for --capture=no; i.e. print statements are not caputred but outputed in the terminal
#     --lf, --last-failed               # runs only the tests that failed last time (or all if none failed)
#     --ff, --failed-first              # runs all tests but runs the last failures first
#     -v, --verbose                     # verbose test run
#     -q, --quiet                       # decrease verbosity
#     -l, --showlocals                  # show local variables in tracebacks (disabled by default)
#     --tb=STYLE                        # traceback print mode, STYLE is one of auto, long, short, line, native, no
#     --durations=N                     # shows N slowest setup/test durations, N=0 for all
#     --version                         # display pytest lib version and import information
#     -h, --help                        # shows help message and configuration info
#     -r CHARS                          # shows extra test summary info; where CHARS is one of more of ->
#                                       # (f)ailed, (E)error, (s)skipped, (x)failed, (X)passed, (p)passed, (P)passed with output, (a)all except pP
#     --setup-show                      # shows all fixtures that run for all tests
#     --fixtures                        # shows available fixtures, sorted by plugin appearance, use -v for _fuxtures
#     --collect-only                    # dry run; useful to run with other options to see what will be run
#     --basetemp=dir                    # specifies a custom base temporary directory for tmpdir_factory fixture
#     --doctest-modules                 # tests docstring examples
#     --strict-markers                  # disallows for unregistered test markers; i.e. markers must be registered in pytest.ini file

# ------- options for 3rd party packages
#     --cov=XXX                         # reports test coverage of XXX dir; pip install --upgrade pytest-cov
#     --cov-report=html                 # puts the coverage report in html format

# ------- possible test outcomes
# PASSED  (.)                           # test passed
# FAILED  (F)                           # test failed
# SKIPPED (S)                           # test was skipped
# xfail   (x)                           # test was not supposed to pass, it run, and failed
# XPASS   (X)                           # test was not supposed to pass, it run, and passed
# ERROR   (E)                           # an exception happedned outside of the test function


# ========================== Creating Tests
pytest.warns()                          # provides a context manager that collects warnings from the executed block


# ========================== Creating Tests
# ------- naming conventions for tests to be discoverable
# test_STH.py, STH_test.py              # naming convention for files
# test_STH                              # naming convention for test methods and test functions
# Test_STH                              # naming convention for test classes

# ------- defining tests
def test_NAME(sth, sthElse):
    assert sth == sthElse

# ------- asserting
assert STH                             # check inside a test, where STH is a boolean (or boolean convertable) expression

# ------- exceptions
with pytest.raises(E_TYPE) as E_INFO:  # check for exceptions; E_TYPE is the type of the exception, E_INFO is an ExceptionInfo class instance
    STH                                # code to raise exception
assert E_INFO.value.args[0] == 'sth'   # assert that the first parameter returned by the exception is 'sth'


# ========================== Marking Tests
# ------- customs markers
@mark.pytest.STH                         # decorator for adding STH marker to a test

# ------- skipping the tests
@pytest.mark.skip(reason='why')          # skip the test; the reason is optional
@pytest.mark.skipif(EXPR, reason='why')  # skip the test if EXPR is True; the reason is NOT optional
@pytest.mark.xfail(EXPR, reason='why')   # expecting the test to fail; EXPR and reason are optional

# ------- usefixtures
@pytest.mark.usefixtures('fixt1', 'fixt2')  # similar to fixtures in the test's param list, except that the test can't use the fixture's return value

# ------- parametrising tests
@pytest.mark.parametrize(nms, vals, ids=IDS)  # runs the decorated test/class with different values, each reported separately ->
#                                             # nms are a string or comma-separated argument names, vals is an iterable(s) of values
#                                             # optional IDS is a list of strings naming the different reported outcomes
def test_STH(nms): pass                       # nms is actually all the names in it


# ========================== Fixtures
# fixtures can be in the test files themselves or in a conftest.py if ones want to share the same fixture among multiple files
# fixtures from a conftest.py are available in the directory of the file and all subdirectories (there can be multiples of conftest.py files)
@pytest.fixture(            # fixture
    scope=SCP,              # scope of a fixture; SCP can be 'function', 'class', 'module', 'session'; default is 'function'
    autouse=BOOL,           # defines if the fixture is automatically used for all scope-tests
    params=PRMS,            # parameters for parametrising fixtures
    ids=IDS                 # names for parametrised tests; list of strings of len(PRMS) or a fct taking param at a time and generating a string name
)

# ------- using fixtures
@pytest.fixture()           # the decorated fct becomes a fixture that can be used as argument to other tests
def some_fixture(): pass

@pytest.fixture()           # set-up and teardown fixture
def tasks_db(tmpdir):
    # Setup
    yield STH               # execute test, yielding STH is optional
    # Teardown

# ------- default fixtures
tmpdir                  # test-scoped, provides a temporary directory unique to the test invocation
#     .join(sht.txt)    # adds a file
#     .mkdir(dir)       # adds a directory
#     .write('string')  # writes into a file created using .join
#     .read()           # read a file

tmpdir_factory          # session-scoped, can be used to create arbitrary temp directories, after creating a directory everything is as in tmpdir
#     .mktemp(dir)      # creates a temporary directory
#     .getbasetemp()    # returns the base directory of tmpdir_factory

request                 # represents a calling state of the fixture
#     .param            # a field that is filled one by one with elements from params in pytest.fixture decorator
#     .node.nodeid      # a unique identifier for every test

parser                  # used to add custom terminal options; should be done via plugin or in conftest.py
#     .addoption(...)   # adds a custom option

pytestconfig            # used to access (custom) terminal options and initial state of pytest
#     .getoption(OPT)   # returns the option OPT, can be custom or not; e.g. verbose, quiet, keyword, etc.
#     .args             # returns the args to pytest; e.g. test_file
#     .inifile          # returns the pytest.ini file
#     .invocation_dir   # returns the invocation directory
#     .rootdir          # returns the root directory

cache                   # used to forward information between test runs; e.g. in --failed-first
#     .get(key, dflt)   # gets the cached key value from the last run, default if first run
#     .set(key, value)  # sets the value to the key for the current run

capsys                  # allows to retrieve stdout and stderr, and to disable output capture
#     .readouterr()     # returns stdout and stderr
#     . disabled()      # returns a context manager with dissabled capture mechanism; i.e. print will show up in the output

monkeypatch             # a.k.a. mocking
#     .setattr(trgt, name, val, raising) # sets an attribute or member fct; i.e. trgt=module.os.path, name='expanduser', val=value or lambda-fct
#     .delattr(trgt, name, raising)      # deletes an attribute or member fct; i.e. trgt=module.os.path, name='expanduser'
#     .setitem(dic, name, val)           # sets a dictionary entry
#     .delitem(dic, name, raising)       # deletes a dictionary entry
#     .setenv(name, val, prepend)        # sets an environmental variable
#     .delenv(name, raising)             # deletes an environmental variable
#     .syspath_prepend(path)             # prepend path to sys.path
#     .chdir(path)                       # change current working directory

doctest_namespace       # doctest_namespace['np'] = numpy transforms np.XXX to numpy.XXX in all docstring example tests

recwarn                 # allows for testing warnings in python; similar to pytest.warns()
#     .clear()          # clears collected warnings; used usually before the place where we care about collected warning
#     .pop()            # pops the last warning
#         .category     # category of the poped warning
#         .message      # message string of the poped warning
#         .filename     # filename of the poped warning
#         .lineno       # line number of the poped warning


# ============= PyTest Classes
# ------- ExceptionInfo Class           # https://docs.pytest.org/en/stable/reference.html#exceptioninfo
ExceptionInfo
    .type                               # type of the exception
    .value                              # value of the exception
    .typename                           # type name of the exception
    .exconly()                          # returns the exception as a string
    .match(regexp)                      # checks if the regexp matches the string representation of the exception


# ============= Initialisation of Pytest
# ------- pytest.ini file
[pytest]
addopts = OPT                            # adds pytest options by default; e.g. addopts = ​-rsxX -l --tb=short --strict-markers

# register markers
markers =
    smoke:explanation                   # silences warning from custom markers

minversion = X.X                        # minimum version for pytest
norecursedirs = XXX                     # recursive test discovery omits XXX dir, dftl: *.egg .* _darcs build CVS dist node_modules venv {arch}
testpaths = tests                       # where to look for tests
python_classes = XXX                    # changes the naming convention for test classes; default: Test*
python_files = XXX                      # changes the naming convention for test files; default test_* *_test
python_functions = XXX                  # changes the naming convention for test functions; default test_*
xfail_strict = true                     # makes passing tests marked with xfail as failed instead of XPASS


# ============= TEXT
# ------- TEXT
