# ========== ToC ==========
# CORE LANGUAGE
#   Modules
#   Comments
#   Types
#   Numerical Operators
#   Logical Operators
#   I/O
#   If statement
#   Loops
#   Strings
#   Ranges
#   Lists
#   Tuples
#   Sets
#   Dictionaries
#   Functions
#   Generators
#   Built-in Functions
#   Classes
#   Files
#   Exceptions
#   Main
# MODULES
#   Signal
#   Unittest
#   OS
#   DateTime
#   Logging
#   Collections
#   Random
#   JSON
#   Itertools
#   Argparse
#   Pillow
#   Warnings

# ========== MODULES ==========
# import module  # calling: module.fct(), module.var
# import module as m          # call the module m; calling: m.fct(), m.var
# from module import f, var   # import f and var; calling: f(), var
# from module import f as ff  # import f and call it ff; calling g()
# from module import *        # bad: import all from module; calling f()
import collections
import datetime
import itertools
import json
import logging
import os
import random
import unittest

import PIL

# ========== COMMENTS ==========
# Coment                    # is a simple comment
'''Multiline comment'''    # is a multiline comment
"""Docstring comment"""    # is a docstring comment

# ========== TYPES ==========
# int, float, bool          # integers, floats, boolean variables
# NoneType                  # special, has only one value None
type(var)          # r: type of var
int(var)           # cast operation to int
float(var)         # cast operation to float
bool(var)          # cast operation to bool
str(var)           # cast operation to str (string)
list(range(5))     # cast range into list, i.e. [0, 1, 2, 3, 4]
tulpe(lst)         # cast list into tuple
set(lst)           # cast list into set

# ========== NUMERICAL OPERATORS ==========
# + - * /                   # addition, subtraction, multiplication, division
# += -= *= /=               # add, subtract, multiply, divide; lhs to/from/by rhs
# ** // %                   # exponentiation, floor division, modulus

# ========== LOGICAL OPERATORS ==========
# == != < > <= >=           # comparing operators
# and ; or                  # logical and ; or
# True ; False              # Boolean values

# ========== I/O ==========
print('txt', end='\n')     # prints 'txt' in the console, ends with '\n' (dflt)
input('txt')               # displays 'txt' and returns user's input

# ========== IF STATEMENT ==========
COND1, COND2 = True, False
if COND1:      # this defines if statement
    pass
elif COND2:    # else if
    pass
else:          # else
    pass

# ========== LOOPS ==========
for i in range(5):     # loops i over [0,1,2,3,4]
    if COND1:
        break          # breaks any loop instantly
    continue           # returns at the beginning of the loop
else:                  # executed at the end if brake was not hit, 'no break' statement
    pass

while COND1:   # executes code as long as the condition is true
    if COND2:
        break
    else:      # executed at the end if brake was not hit, 'no break' statement
        pass

# ========== STRINGS ==========
# strings are immutable
subs, s, = 'str', 'string'
'\t', '\n'         # tabulator and new line in strings
s.expandtabs(N)    # sets \t size to N spaces, dflt=8
s.title()          # r: a copy of string with first letters capitalised
s.upper()          # r: a copy of string with all letters capitalised
s.lower()          # r: a copy of string with all letters lower case

s.lstrip(), s.rstrip()     # deletes spaces (or content in brackets) from left, right or...
s.strip()                  # ...from both sides

subs in s              # r: True if substr is somewhere in str
s.replace('s1', 's2')  # r: a copy of s where all substrs 's1' are replaced by 's2'
s.split(subs)          # split s into words on substring subs (dflt subs=' ')
subs.join(LoS)         # join lst of strings on a given substring, i.e LoS[0]+subs+Los[1]+subs+...
s.index(subs)          # r: 1st idx of 1st occurrence of subs or raises an error
s.find(subs)           # r: 1st idx of 1st occurrence of subs, -1 if not found
s.count(subs)          # counts the occurrence of the given substring in s
s.endswith('.jpg')     # r: True if s ends with '.jpg', false otherwise

s[start:stop:step]     # r: slice of the string, if step < 0 reverse the order
s[-1]                  # r: returns the last element

for ch in s:   # loop over the string's letters
    pass

'Printing {} numbers'.format(3)
'{0} {1} /{0}'.format('tag', 'text')   # prints "tag text /tag"
'{name}, {age}'.format(name='J', age=18)
'{0[name]},{0[age]}'.format(person)    # person is dict with keys name and age
'{name}, {age}'.format(**person)       # person is dict with keys name and age
'{0.name},{0.age}'.format(person)      # person is class with attr name and age

'{:0X}'.format(number)     # pads with zero to X characters
'{:.Xf}'.format(number)    # prints up to X decimal places
'{:,}'.format(number)      # separates thousands by commas

# f-strings work exactly as '.format(...)', including number padding etc.
f'args: {args}'    # f-string, variables can be directly placed inside
f'{var:,}'         # f-string, formatting works as above (thousand separator)

# ========== RANGES ==========
range(10)          # stop at 10 non-inclusive; i.e. 0,1,...,9
range(1, 5)        # start=1, stop=5; i.e. 1, 2, 3, 4
range(2, 11, 2)    # start=2, stop=11, step=2; i.e. 2, 4, 6, 8, 10

# ========== LISTS ==========
# lists are not hashable!
lst = [1, 2, 3]                # definition of a list with numbers
lst[0], lst[-1]                # r: first and last elements respectively
lst[1:3]                       # r: a slice of lst containing second and third element
lst[:3], lst[1:], lst[-3:]     # equiv. to lst[0:3] lst[1:-1] lst[-3:len(lst)]
lst1 = lst[:]                  # copies the whole lst to a new l1; [:] can't be omitted
lst1 = lst                     # creates an alias lst1 for lst (refers to the same memory)

del lst[i]     # deletes the i-th element from the lst

lst.append(4)          # appends 4 at the end of lst
lst.extend(lst1)       # appends a copy of lst1 to the end of lst
lst.insert(i, 'num')   # inserts 'num' at the i-th pos. and shifts the others
lst.pop(i)             # deletes i-th (or the last element if i not given) and returns it
lst.remove('val')      # removes the first occurrence of 'val'
lst.sort(              # sorts lst in place
    key=abs,           # ...fct applied to elements before sorting
    reverse=True)
lst.reverse()          # reverses the order of elements
lst.index('val')       # r: index of first occurrence of 'val' in lst, or ValueError
lst.count('val')       # r: number of occurrences of 'val' in lst

sorted(lst)            # r: a copy of sorted lst
sorted(lst, key=abs)   # r: a copy of sorted lst, applies abs fct to the elements before sorting
len(lst)               # r: the length of list (i.e. the number of elements)
min(lst), max(lst)     # r: the lowest / highest value in lst
sum(lst)               # r: a sum of the values in lst (only for numbers)

'val' in lst       # r: True if 'val' is in the lst, False if not
'val' not in lst   # r: False if 'val' is in the lst, True if not

while 'itm' in lst:    # 3 lines above
    pass
while lst:             # equiv. to while len(lst) != 0:
    pass

if lst:    # equiv. to if len(lst) != 0
    pass

for item in lst:               # loops through lst
    pass
for item in lst[:3]:           # loops through first three elements
    pass
for i, itm in enumerate(lst):  # loops through lst; itm = lst[i]
    pass

[j**2 for j in range(1, 8)]                    # returns [1, 4, 9, 16, 25, 36, 49]
[j**2 for j in range(1, 8) if j != 3]          # as above but omits 3*3 = 9
[j**2 if j != 3 else 33 for j in range(1, 8)]  # as above but instead of 3*3 = 9 returns 33
[(a, b) for a in range(3) for b in range(3)]   # returns all 9 combination of a,b

# ========== TUPLES ==========
# indexing works exactly the same way as in lists
t = (1, 2, 3)  # a tuple (an immutable list), access elements using []
t = (1, )      # a tuple of one element; comma can't be ommited
t = (1)        # t is now an int

# ========== SETS ==========
# sets are hash tebles (dictionaries) without values
s1 = {1, 2, 1}                 # un-subscriptable, storing unique elements, st is {1, 2}
s2 = set()                     # creates an empty set
s2.add(3)                      # adds 3 to the set
s1.update([1, 2, 4], s2)       # adds values from the list and s2 to s1
s1.remove(1)                   # removes 1 from s1, error if 1 is not in s1
s1.discard(1)                  # removes 1 from s1, does nothing if 1 is not in s1
s1.intersection(s2, s3)        # r: s1 ∩ (s2 ∪ s3)
s1.difference(s2, s3)          # r: s1 - (s2 ∪ s3)
s1.symmetric_difference(s2)    # r: (s1 ∪ s2) - (s1 ∩ s2)

'element' in s1    # constant time lookup; r: True if element is in s1

# ========== DICTIONARIES ==========
# hash table
d = {'k1': 'v1', 'k2': 'v2'}   # definition of a dict; order doesn't matter
dict(k1='v1', k2='v2')         # same as above
{i: i + 1 for i in range(3)}   # generates {0: 1, 1: 2, 2: 3}
d['k1']                        # returns v1
d['k3'] = 'v3'                 # overwrite the val of k3 or creates a new pair
del d['k1']                    # deletes key-value pair from the dictionary

d.items()      # r: a list of tuples (key, value)
d.keys()       # r: a list of keys in d
d.values()     # r: a list of values in d

'k1' in d  # r: bool depending on 'k1' being in d

for k in d:                # loops through keys in Dict
    pass
for k in d.keys():         # is the same as above
    pass
for v in d.values():       # loops over the values (v) of d
    pass
for k, v in d.items():     # loops through keys (k) and values (v) of d
    pass


# ========== FUNCTIONS ==========
def fct1(arg1, arg2):  # definition of a function
    pass               # returns None if return statement is omitted


def fct2(arg1, arg2=3):    # a function with a default value
    return arg1 + arg2     # returns addition of arguments


def fct3(arg, *args):  # arbitrary #arguments stored as a tuple, args
    return None        # allows "if (fct):"; e.g. in excep. handling


def fct4(**kwargs):    # arbitrary num of pairs stored in a dict
    pass


fct1(1, 2)             # possible call of the fct, order dependent
fct2(arg1=1, arg2=2)   # another call of the fct, order independent
fct3(lst)              # lst can be modified by fct
fct3(lst[:])           # passes a copy of lst to the function

lambda x: x**2         # defines a quadratic function f(x)
lambda x, y: x + y     # defines an addition function f(x,y)

# ========== Generators ==========
gen = (i for i in range(10))   # defines a generator, generating ints in [0, 10)


def g(n):          # defines fct returning generator
    for i in range(n):
        yield i    # each call __next__() will return next number


def g(n):  # same as above
    i = 0
    while i < n:
        yield i
        i += 1


gen = g()          # necessary for defined generators, not for gen = (...)
gen.__iter__()     # returns iterable, same as above
iter(gen)          # same as above
gen.__next__()     # returns next element
next(gen)          # same as above

# ========== BUILT-IN FUNCTION ==========
# https://docs.python.org/3/library/functions.html
map(fct, iter1, ...)           # applies fct to iter1; #iter == #args for fct
zip(iterable1, interable2)     # r: iterable with the argument bound in a tuple
filter(bool_fct, iter, ...)    # picks item from iter for which bool_fct(item) == True

isinstance(obj1, type1)    # r: True if type(obj1) == type1
issubclass(boj1, obj2)     # r: True if obj1 is subclass of obj2
hasattr(obj, attr)         # ture if obj.attr exists
callable(obj.attr)         # true if obj.attr is callable
dir(obj)                   # r: all methods and attributes of an object


# ========== CLASSES ==========
# https://docs.python.org/3/reference/datamodel.html#basic-customization
class BaseCls():   # definition of a class
    cls_var1 = 0   # class variable

    def __init__(self, a):         # self must be first
        self.a = a                 # definition of a new data in the class
        self.b = BaseCls.cls_var1  # assing class var as ID of an instance
        BaseCls.cls_var1 += 1      # change class var

    def met(self, prmts):  # def of a method
        pass

    @property  # fct called as an attribute, i.e. without parenthesis
    def prop123(self):
        pass

    @prop123.setter    # allows setting attributes, self.prop = sth
    def prop123(self, sth):
        pass

    @prop123.deleter   # allows deleting, i.e del self.prop
    def prop(self, sth):
        pass

    @classmethod               # can be used as an alternative constructor
    def cls_met(cls, amount):  # first arg is class (cls), not instance (self)
        pass

    @staticmethod  # gets neither self nor cls as the first arg
    def sta_met(arg):
        pass

    def __add__(self, other):  # overloads +
        pass

    # magic methods: add(+), sub(-), mul(*), truediv(/), floordiv(//), mod(%), pow(**)
    #                lshift(<<), rshift(>>), and(&), xor(^), or(|)
    # augmented asignment: iadd(+=), etc...
    # reflected operators: radd(+) (a+b -> b+a) is called only if b.__add__ is not defined; etc...
    # undefined operators should return (not raise) NotImplemented
    # eq(==), ne(!=), lt(<), le(<=), gt(>), ge(>=)
    # neg(-), pos(+), abs(abs), invert(~)
    # str, repr


obj.met(prmts)             # calling method
BaseCls.met(obj, prmts)    # alternative way of calling method


class DerivedCls(BaseCls):     # definition of a derived class
    cls_var2 = 0

    def __init__(self, a, c):
        super(DerivedCls, self).__init__(a)    # preferred base class construction
        super().__init__(a)                    # ...alternative
        BaseCls.__init__(a)                    # ...alternative
        self.c = c                             # new data - an instance of another class

    def met(self, prmts):                      # def of a method
        super(DerivedCls, self).met(prmts)     # calls the base met method
        fct()                                  # adds additional functionality to the derived calss


# ========== FILES ==========
# possible modes: r,  w,  a,  w+  (read, write, append, read-write)
#                 rb, wb, ab, wb+ (binary modes, same as above)
f = open('file', 'X')  # r: pointer to file, X is mode
f.close()              # closes the file saved in the file_object f

with open('file', 'X') as f:   # opens a file in mngr. context
    pass

f.name, f.mode     # r: name, mode
f.read()           # r: the entire file content
f.read(N)          # r: next N characters of f
f.readline()       # r: one line at a time
f.readlines()      # r: list of all lines from f
list(f)            # same as above
f.tell()           # r: current pointer position
f.seek(i)          # sets the pointer in the file to i-th position
f.write('str')     # writes in file, doesn't add '\n'

for line in f:     # same as: for line in f.readline():
    pass

# ========== EXCEPTIONS ==========
try:                   # handling exceptions, try block
    pass
except someExcept:     # executed if except 'someExcept' is raised (else part is skipped)
    pass
except:                # deals with all other exceptions
    pass
else:                  # (optional) if no exception is raised the code continues here
    pass
finally:               # executed always
    pass

raise EXCEPT("text")   # throw an exception

Exception          # catches all exceptions
SyntaxError        # program can't be parsed
NameError          # local or global name not found
AttributeError     # attribute reference fails
TypeError          # operand doesn't have correct type
ValueError         # operand type okay, but value is illegal
IOError            # IO system reports malfunction
ZeroDivisionError
FileNotFoundError
AssertionError     # produced by assert

assert cond, 'error msg'   # crash the program if condition == False

# ========== MAIN ==========
if __name__ == "__main__":
    main()

# ========== SIGNAL MODULE ==========
# import signal
signal.SIGINT                          # SIGINT (signal interrupt) is sent by (^C) key combination
signal.signal(signal.SIGINT, MYFCT)    # calls MYFCT when SIGINT is sent to the program (at some point)


# ========== UNITTEST MODULE ==========
# write this in a separate file test_XXX.py
# import unittest                   # module for testing code
# import XXX.py                     # import the file to be tested
class TCclass(unittest.TestCase):  # this defines a test case (TS)

    @classmethod
    def setUpClass(cls):   # runs first, before running setUp and test_FCT
        pass

    @classmethod
    def tearDownClass(cls):    # runs last, after running test_FCT and tearDown
        pass

    def setUp(self):   # run before each test_XXX
        pass

    def tearDown(self):    # run after each test_XXX
        pass

    def test_FCT(self):            # a unit test; methods starting with 'test_' are auto run
        o = XXX.FCT(...)           # call the tested function/method...
        self.assertEqual(o, e)     # compare actual (o) with expected (e)...


# for additional assertSTH: https://docs.python.org/3.7/library/unittest.html#test-cases

unittest.main()    # this function runs all the test cases

# Running test file from terminal without __name__ == "__main__"
# $python3 -m unittest test_XXX.py

# ========== OS MODULE ==========
# import os                 # imports standard library os module
path = os.getcwd()         # r: current working directory
os.chdir(path)             # change current working directory to path
os.listdir(path)           # r: list the content of path directory, dflt=cwd
os.mkdir(path)             # create one-level deep directory
os.rmdir(path)             # delete one-level deep directory
os.makedirs(path)          # create arbitrary-level deep directory
os.removedirs(path)        # delete arbitrary-level deep directory
os.rename('orig', 'new')   # rename 'orig' to 'new'
os.stat(path)              # prints statistics of a file / directory
os.walk(path)              # r: dirpaht, dirnames, filenames recursively for depth first pathtree

os.path.join(path, path1)  # joins two paths, e.g. path and file name
os.path.basename(path)     # r: basename, i.e. file/dir name for files/dirs
os.path.dirname(path)      # r: dirname
os.path.split(path)        # r: (dirname, basename)
os.path.exists(path)       # r: True if path exists
os.path.isdir(path)        # r: True if path is a dir
os.path.isfile(path)       # r: True if path is a file
os.path.splitext(path)     # r: (rest, extension)

# ========== DATETIME MODULE ==========
# import datetime           # imports standard library datetime module
# naive, avare datetimes - 1st does not contain enough info for timezones etc.
datetime.date(Y, M, D)         # creates naive date
d = datetime.date.today()      # r: today day
d.year, d.month, d.day         # r: Y, M, D
d.weekday, d.isoweekday        # r: M=0...S=6, M=1...S=7
datetime.timedelta(days=7)     # r: delta of 7 days

t = datetime.time(h, m, s, us)
t.hours, t.minutes, t.seconds

dt = datetime.datetime(Y, M, D, h, m, s, us)
dt.date(), dt.time()

# ========== LOGGING MODULE ==========
# import logging                        # imports standard library module
# levels of logging: DEBUG < INFO < WARNING < ERROR < CRITICAL
FORMAT = '%(asctime)-15s %(levelname)s %(message)s'
logging.basicConfig(       # setting root logger configuration
    filename='log.log',    # logs into a file, if omitted logs into console
    level=logging.INFO,    # logs messages with level >= INFO
    format=FORMAT)         # formatting the logged message

logging.LVL('msg')     # send 'msg' LVL(DEBUG, INFO, etc.) to the root logger

f_hnd = logging.FileHandler('log.log')     # create file to log into
f_hnd.setLevel(logging.INFO)               # sets log level for file handler
formatter = logging.Formatter(FORMAT)      # create format for logging messages
f_hnd.setFormatter(formatter)

logger = logging.getLogger('name')     # creating a new logger, name is usually __name__
logger.addHandler(log_f)               # logger sends logs into log_f, can have multiple log_f
logger.setLevel(logging.DEBUG)         # sets log level for logger

logger.LVL('msg')  # send 'msg' LVL(debug, info, etc.) to created logger

# ========== COLLECTIONS MODULE ==========
# import collections            # is a module in standard library
Color = collections.namedtuple('Color', ['red', 'green', 'blue'])
c = Color(55, 100, 54)
c['red']   # return 0-th element
c.red      # same as above
c[0]       # same as above

d = collections.OrderedDict()  # creates a variable of type OrderedDict

# ========== RANDOM MODULE ==========
# import random                 # module
random.random()            # r: random float from [0,1)
random.uniform(a, b)       # r: random float from [a,b) or [a,b] depending or rounding
random.randint(a, b)       # r: random int from [a,b]
random.choice(lst)         # r: random element from lst
random.choices(            # r: k random elems from lst (with replacement) weighted with probs
    lst,
    weights=probs,         # ...unnormalised probabilities
    k=10)
random.shuffle(lst)        # randomly shuffle lst in place
random.sample(lst, k=5)    # r: k random sampled elems from lst (without replacement)

# ========== JSON MODULE ==========
# import json                   # JavaScript Object Notation
json.dump(obj, f_hndl)     # stores obj in f_hndl, beneficial *.json ending
json.load('file')          # r: exactly the content stored in file

json.loads(str)    # load json-string to python data structures
json.dumps(var)    # dump python data structure to json-string

# ========== ITERTOOLS MODULE ==========
# import itertools              # python standard library module
itertools.count(                   # r: counter
    start=0, step=1)
itertools.zip_longest(             # as zip, but pairs with the longer iter
    it1, it2, fillvalue=None)
itertools.cycle(iterable)          # r: iter cycling over the values indefinitely
itertools.repeat(obj, times=n)     # r: iter yielding obj n-times
itertools.starmap(fct, seq)        # applies fct to elements in seq, i.e. starmap(pow, [(2, 5), (3, 2)])

itertools.combinations(it, r)  # r: iter of r-combinations of elems in it (order does not matter)
itertools.permutations(it, r)  # same as above, but order does matter
itertools.product(it, repeat)  # permutations with replacement

itertools.chain(it1, it2, it3)     # r: iter going over chain of it1, it2, etc.
itertools.islice(it, a, b, c)      # r: iter over elements of it a, b, c = start, stop, step
itertools.compress(d, slctrs)      # r: iter over elems of d having corresponding elems in slctrs True
itertools.accumulate(it, fct)      # r: iter 'accumulating' values of it by applying fct

# ========== ARGPARSE MODULE ==========
# import argparse               # imports argparse module
parser = argparse.ArgumentParser(description='Description of the programe')
# mandatory arguments do not start with '-' or '--'.
parser.add_argument(
    "mandatory",       # name of the argument
    metavar="",        #
    type="",           # type for the argument, e.g. 'int' for integer or argparse.FileType('r') for read only file
    default="",        # default for the argument
    help=""            # description of the argument, shown in help (default=...)
)
parser.add_argument(   # optional arguments do start with '-' or '--'.
    '-o',              # short name for the optional argument
    '--optional',      # full name of the optional argument
    metavar="",        #
    type="",           # type for the argument, e.g. 'int' for integer or argparse.FileType('r') for read only file
    default="",        # default for the argument
    help=""            # description of the argument, shown in help (default=...)
)

args = parser.parse_args()
mandatory = args.mandatory
optional = args.optional

# ========== PILLOW MODULE ==========
# from PIL import Image         # imports Image processing library
# https://pillow.readthedocs.io/en/stable/
im = Image.open('im1')         # opens an image
im.show()                      # displays the image in default image preview program
im.thumbnail((xsize, ysize))   # resized the image
im.rotate(deg)                 # rotates the image by deg
im.convert(mode='L')           # converts the image to black&white
im.save('im2')                 # saves image as 'im2'

# ========== PILLOW MODULE ==========
# import warnings               # imports warnings module
warnings.warn('warning', WARNING)

Warning                    # This is the base class of all warning category classes;, it is a subclass of Exception
UserWarning                # The default category for warn()
DeprecationWarning         # Base category for warnings about deprecated features when those warnings are intended for other Python developers
SyntaxWarning              # Base category for warnings about dubious syntactic features
RuntimeWarning             # Base category for warnings about dubious runtime features
FutureWarning              # Base category for warnings about deprecated features, intended for end users of Python applications
PendingDeprecationWarning  # Base category for warnings about features that will be deprecated in the future (ignored by default)
ImportWarning              # Base category for warnings triggered during the process of importing a module (ignored by default)
UnicodeWarning             # Base category for warnings related to Unicode
BytesWarning               # Base category for warnings related to bytes and bytearray
ResourceWarning            # Base category for warnings related to resource usage
