//==================== C++

// Compilation
// Preprocessor
//      Source File Inclusion
//      Replacing Text Macros
//      Conditional Inclusion
//      Error Directive
//      # and ## Operators
//      Predefined Macros
// Main Function
// Types and Declarations
//      Types
//      Declarations
//      Type Aliases
//      Casting
//      Structured Bindings
//      Static and Extern
// Pointers, Memory Allocation, Arrays, and References
//      Pointers
//      Memory Allocation
//      Arrays
//      References
// Statements
//      Selection Statements
//      Iteration Statements
// Operators
//      Arithmetic Operations
//      Comparison Operators
//      Variable Modifying Operators
// Operator Precedence
// Functions
//      Function Declarations and Definitions
//      Argument Passing
//      Pointer to a Function
//      Lambda Function
// Modules
// Structures Unions and Enumerations
//      Structures
//      Unions
//      Enumerations
// Modules c++20
// Classes
//      Class Definition, Initialisation, Member Functions
//      Friend Functions and Classes
//      Operator overloading
//      User-defined literals
//      Method Pointers
// Derived Classes
//      Derived Class Definition
//      Base Initialisers
//      Members and Member Functions
//      enable_shared_from_this
// Namespaces
// Exceptions
// Templates
//      Definition
//      Non-Type Template Parameters
//      Function Objects
//      Variadic Templates
//      Aliases
//      Concepts c++20
// Source Files and Programs
//      Linkage
//      Programs


//==================== Compilation
// /usr/local/Cellar/llvm/12.0.0_1/bin/clang++ -std=gnu++20 -ggdb3 -o output  file.cpp
// -ggdb3                                       // allows valgrind to pinpoint lines where leaked memory is allocated
// valgrind --leak-check=full ./executable      // checks for memory leaks



//==================== Preprocessor

//---------- Source File Inclusion
#include <filename>         // The specified file is inserted into the code at the location of the directive
#include "filename"


//---------- Replacing Text Macros
#define [id] [value]        // Every occurrence of the identifier is replaced with the value, can be dangerous; c++ provides better mechanisms
#define IDENTIFIER replacement_list(optional)
#define IDENTIFIER( parameters ) replacement_list(optional)
#define IDENTIFIER( parameters, ... ) replacement_list(optional)
#define IDENTIFIER( ... ) replacement_list(optional)
#undef IDENTIFIER


//---------- Conditional Inclusion
#if CONST_EXPR
#elif CONST_EXPR
#else
#endif

#ifdef [id]        #endif   // Code within the ifdef blocks are conditionally included or omitted based on identifier
#ifdef IDENTIFIER  #endif
#ifndef [id]       #endif   // Code within the ifdef blocks are conditionally included or omitted based on identifier
#ifndef IDENTIFIER #endif
#pragma once                // The file is included only once


//---------- Error Directive
#error error_message


//---------- # and ## Operators
// # operator converts the token (x) to a string surrounded by quotes, e.g. 'cout << MKSTR(hello);' is replaced by 'cout << "hello";'
#define MKSTR( x ) #x
// ## operator concatenates the tokens (x, y), e.g. 'cout << CONCAT(x, y);' is replaced by 'cout << xy;'
#define CONCAT( x, y )  x ## y

//---------- Predefined Macros
__LINE__;       // contains the current line number of the program
__FILE__;       // contains the current file name of the program
__DATE__;       // contains a string of the form month/day/year     that is the date at which the program was compiled
__TIME__;       // contains a string of the form hour:minute:second that is the time at which the program was compiled



//==================== Main Function
int main(               // the main function
    int argc,           // number of arguments passed
    char* argv[]) {     // name of the function (or an empty string) and all the passed arguments
        return 0;       // can be ommited
    }



//==================== Types and Declarations

//---------- Types
void; bool; char; int; float; double;

// Voids
void f();                       // function f does not return a value
void* pv;                       // pointer to object of unknown type

// Booleans
bool; true; false;              // boolean type and possible values

// Characters
char;                           // default character type; either signed or unsigned char
signed char;                    // capable of holding positive and negative numbers
unsigned char;                  // guaranteed to be unsigned
wchar_t;                        // holds characters of a larger character set, e.g. Unicode
char16_t;                       // holds 16-bit characters, e.g. UTF-16
char32_t;                       // holds 32-bit characters, e.g. UTF-32
\n; \t; \v; \b;                 // newline, horizontal tab, vertival tab, backspace,
\r; \f; \a; \\;                 // carriage return, form feed, alert, backslash,
\?; \';                         // question mark, single quote,
\ooo; \xhhh;                    // octal number, hexadecimal number
'a';                            // char

// Integers
signed, unsigned;               // each integer type can be signed or unsigned
short int;                      // short int,       >= 16bit;
int;                            // plain int,       >= 16bit; 32bit on 32/64 bit systems
long int;                       // long int,        >= 32bit;
long long int;                  // long long int,   >= 64bit;
3; 3U; 3L; 3LL;                 // int, unsigned int, long int, and long long int, respectively
123; 0123; 0x123; 0b121;        // decimal, octal, hexadecimal, and binary numbers

// Floats
float;                          // single-precision float
double;                         // double-precision float
long double;                    // extended-precision float
3.14; 3.14F; 3.14L;             // double, float, and long double, respectively
2e3; 2e-3;                      // 2x10^3 = 2000, 2x10^-3 = 0.002
3.141'592                       // digit separator is a single quote
0x3.ABCp-10, 0Xb.cp12l          // hexadecimal floating-point literal

// Alignment
alignof();                      // alignment of an argument in std::size_t; more about is in expressions
alignas();                      // used in declarations of unknown types

// Constants
constexpr;                          // evaluated at compile time, can be initialised only by constant expressions
const;                              // specifies immutability in interfaces, can be initialised by non-constant values or fcts
const int d = 17;                   // defines constant integer d
constexpr double = 1.3*square(d);   // ok if square(d) is a const expr; error if d is a variable
const double = 1.3*square(d);       // ok in any case, can be evaluated at runtime
double sum(const vector<double>&);  // fct sum will not modify its argument

// additional
"some string";                      // C-style (zero terminated) string (const char[11])
R"(raw string)";                    // raw string, escaped sequences are ignored, (\" is ", \n is enter, etc.)
R"delim(raw string)delim"           // raw string; delim can be any 16 char long sequence, used in case )" appears in the middle of the raw string


//---------- Declarations
// the structure of a declaration is as follows:
//  - prefix (static, virtual)
//  - type (int, const int)
//  - declarator (declarator ops, name)
//  - suffix (const, noexcept)
//  - initialiser (=1, {1})

// declarator ops are:
//  - *, *const, *volatile  // plain, constant, and volatile pointer; all prefix
//  - &, &&, []             // lvalue and rvalue reference, array; pre-, pre-, post-fix
//  - auto, (), ->          // fcts (suffix return type), fcts, returns from fcts; pre-, post-, post-fix

// declarations
type x;                     // declaration of a variable of type;
type x, y;                  // declaration of two variables of type;

// declarations with initialisation
type t1 {v};                // declaration of t1 with initialisation to v; does not allow narrowing
type t2 = {v};              // same as above, no narrowing allowed; = is redundant
type t3 {};                 // initialise t3 to a default value (zero initialiser), depends on the type
type t4 = v;                // initialise t4 to v, narrowing applies
type t5(v);                 // depending on the constructor, different actions might apply
auto t6 {1};                // t5 is of type initializer_list<int>, always use = with auto to prevent this

static;                     // object declared to be static live until the program terminates
auto;                       // deducing a type of an object; it strips away references and const qualifiers and thus creates a copy
const auto; auto &;         // specifiers and modifiers are needed if one wants to preserve them, as they are stripped by default
auto *;                     // for pointers, this is not necessary as pointer specifier is not stripped away
const auto; auto const;     // both make int *const (e.g. for int *)
const auto *; auto *const;  // first makes const int *, second makes int *const (e.g. for int *)
const auto *const;          // makes const int *const (e.g. for int *)
decltype(expr)              // deducing a type of an object from an expression, e.g. function; does not strip away references and const qualifiers

// postfixes bind tighter than prefixes
char (*kings)[];            // kings is a pointer to an array of char
char* kings[];              // kings is an array of pointers to char, i.e. char *(kings[])

int * p, y;                 // declaration of a pointer, p, to an integer and of an integer, y
int x, * q;                 // declaration of an integer, x, and of a pointer, q, to an integer

// decltype vs auto
auto x { f() };             // auto strips reference and const qualifiers
decltype(fct()) x { f() };  // decltype strips nothing, x is a (const) reference if f returns a (const) reference
decltype(auto) x { f() };   // as above


//---------- Type Aliases
using Pchar = char*;        // creates alias for char*
typedef char* Pchar;        // old syntax, same as above

using a = unsigned my_int;  // applying type specifiers to an alias is not allowed


//---------- Casting
(int)myFloat                        // C casting, not recommended
int(myfloat)                        // rarely used
const_cast<new_type>(expr);         // used to cast away (remove) constness or volatility
static_cast<new_type>(expr);        // compile-time checked, for
                                    //  ...well-def implicit conversions (int to double),
                                    //  ...class conversions on ptrs and refs -> A to B where B has a constructor taking A as an argument, and
                                    //  ...class hierarchy traversions on ptrs and refs -> D to B (no cast); B to D (needs cast and caution!)
reinterpret_cast<new_type>(expr);   // unchecked conversion, changing the meaning of bit patterns
dynamic_cast<new_type>(expr);       // run-time checked conversion, class must have a vtable (a virtual fct) for
                                    //  ...class hierarchy traversions on ptrs and refs -> B to D, preffered over static_cast
std::bit_cast<new_type>(expr);      // defined in <bit>, c++20, requires sizeof(src) == sizeof(target) and both are trivially copyable, for
                                    //  ...copying bits of source obj to a target obj and interpreting the copied bits as a target object


//---------- Structured Bindings
array tmp { 11, 22, 33 };       // defines 2-element array of ints
auto [x, y, z] { tmp };         // defines x, y, z as ints with values from tmp

std::pair tmp { "hi", 5 };      // defines a pair
auto [s, i] { tmp };            // defines s, i with values from the pair tmp


//---------- Static and Extern
static int x;           // internal linkage variable x (accessible only from withing the file); use unnamed namespaces for the same effect instead
static void f();        // interanl linkage function f (accessible only from withing the file); use unnamed namespaces for the same effect instead

extern int x;           // tells compiler that x is a global variable defined elswhere; not recommended using global variables

void f() {
    static bool init { false };     // the init variable "remembers" the state of the f() between different calls; not recommended
    ...;
}



//==================== Pointers, Memory Allocation, Arrays, and References

//---------- Pointers
nullptr;            // null pointer, i.e. pointer not pointing to any object
type *ptr;          // declares a pointer, i.e. ptr is a pointer to type; best practice initialise it always to the nullptr
*ptr;               // dereference the pointer, i.e. reffere to the object pointed to
type **ppc;         // pointer to a pointer to type
type *ap[10];       // an array of 10 pointers to type
type *f(char);      // function taking char as an argument and returning a pointer to type
type (*f)(char);    // pointer to a function taking char as an argument and returning type

// pointers to void
//  -can hold any object type except pointers to functions or to members
//  -can't be dereferenced(*), incremented (++), assigned to another non-void pointer
//  -they must be explicitely converted to a pointer to a specific type first
void *vp = p;                   // implicit convertion of p's type to void
int *p = static_cast<int*>(v);  // safe if *p1 is int, otherwise unsafe

type *const cptr = sth; // constant pointer;     cptr can't be modified, *cptr can
const type *ptrc = sth; // pointer to constant; *ptrc can't be modified,  ptrc can

int i = 10;             //
int *pi = &i;           // definition of a pinter pointing to i

*var; &var;             // as prefixes: contents of, address of
type*; type&;           // as postfixes: pointer to, reference to
&&                      // rvalue reference, not possible to assign to (e.g. returned by a fct call)


//---------- Memory Allocation
type *p = new type[N];  // allocates memory for N elements of type and returns a ptr to the zeroth; throws an exception if allocation fails
new(nothrow) type[N];   // as above, but doesn't throw; returns nullptr if allocation fails
delete [] p;            // frees the allocated memory returned by new type[]
type *p = new type;     // allocates memory for a variable of type and returns a ptr to the memory; throws an exception if allocation fails
new(nothrow) type;      // as above, but doesn't throw; returns nullptr if allocation fails
delete p;               // frees the allocated memory returned by new type

type *p = new type[N]; delete p;    // can delete only p[0] or corrupts memory (compiler dependent); new and new[] migh use different heaps

class Foo;                                  // dummy class
Foo *myFoo { (Foo *)malloc(sizeof(Foo)) };  // only allocates enough memory to hold Foo and casts it to (Foo *)
Foo *myOtherFoo { new Foo{} };              // allocates enough memory to hold Foo and calls the default constructor on every Foo element
free(myFoo);                                // only frees the allocated memory; if Foo aquired additional memory it will be leaked
delete myOtherFoo;                          // also calls Foo's destructor and frees all additional memory acquired by Foo
realloc()                                   // allocates block of memory of new size and bit-wise copy old data; tears objects holding other objects

// pointer arithmetic
int *arr { new int[5] };    // defines an array pointer with allocated memory
arr[2] == *(arr + 2);       // returns true; alternative way of accessing elements
int *arr2 = arr + 2;        // defines a smaller array with the same underlying memory


//---------- Arrays
float v[N];                 // an array of N floats allocated on the stack, n must be a constant expression; elements hold garbage values
float v[N] {1.0, 2.0};      // as above but sets first two elements to 1.0 and 2.0 and the rest to 0.0
float v[N] {1.0};           // as above but sets all elements to 1.0
float v[N] { };             // as above but sets all elements to 0.0
int myArray[] { 1, 2, 3};   // an array of 3 ints, the size if automatically deduced from the initialiser list
v[0] = 1.0;                 // assigning 1.0 to the first element
int v1[] {1, 2, 3};         // declare v1 and initialise it to 1, 2, 3
int v2[4] {1, 2};           // v2 = {1, 2, 0, 0}

// String Literals
sizeof("Juraj") == 6;       // is true, string literals are zero terminated ('\0')
const char *ptr {"Juraj"};  // ptr now behaves like char ptr[] {"Juraj"}

int v[] {1,2,3};            // array of three integers; allocated on the stack (no need to delete)
int *p1 = v;                // pointer to initial element of the array v
int *p2 = v+3;              // pointer to the one-past-last element of v
int len = p2 - p1;          // len = 3, possible only for pointers pointing to the same array

int matrix[2][3];           // 2 arrays with 3 integers each, i.e. 00,01,02;10,11,12

// arrays can only be passed as a pointer to its first element, no passing by value
// when a multi-dimensional array is passed it is 'flattened'
void fct(int* theArray);        // declares a fct taking a pointer to any array of ints
void fct(int theArray[]);       // same as above (even though it seems different)
void fct(int (&theArray)[N]);   // declares a fct taking only stack-based (not heap-based) arrays of length N


//---------- References
int i = 1;                  // definition of i
int &j = i;                 // creating reference j to i; reference must be assigned at declaratin;
j = 4;                      // also i = 4

int *p {nullptr};           // pointer declaration
int *&pRef {intP};          // reference to a pointer
int &*refP;                 // pointer to a reference, does not compile
int &&ref;                  // reference to a reference, does not compile

// lvalue reference, &, must be initialised by lvalue of the same type
// constant lvalue reference does not need lvalue nor a value of the same type
const double &cdr {1};      // 1 converted to 1.0 and stored in a kinda temp variable to which cdr refferes to

// rvalue reference, &&, can bind only to rvalue objects
string &&rr {"Rval str"};   // rr refers to a temporary holding the str; extends the lifetime of the temporary
string &r {"Rval str"};     // not possible, compilation error

static_cast<T&&>(x)         // is the same as move(x), function for moving objects without copying



//==================== Statements

//---------- Selection Statements
if(cond) {...;}             // structure of if-statement
if(init; cond) {...;}       // structure of if-statement with and initialiser; i.e. int i {0}, i lives in if, if else, and else scopes
else if(cond) {...;}        // additional condition check (optional)
else {...;}                 // else part (optional)

if constexpr (cond) {} else {}  // evaluated at compile-time; branch can be rejected at compile-time and thus never get compiled

switch(val) {               // structure of switch-statement; val must be of (or convertible to) integral type
switch((init; val)) {       // switch-statement with initialiser
    case opt1:              // case labels must be a constant expression of integral of enumeration type
        ...;                // body for opt1
        break;              // breaks the switch statement (optional); [[fallthrough]] can be used to indicate intended fallthrough
    default:                // default is executed for all values (optional)
        ...;
}


//---------- Iteration Statements
// range-for statement
for(type x: v) {...;}                       // for each x in the range v (e.g. std::vector<type>)
                                            // v must offer v.begin()/begin(v) and v.end()/end(v) iterators
for(auto x: v) {...;}                       // as above
for(type &x: v) {...;}                      // allows to modify the elements, x's, in v
for(auto p=begin(v); p<end(v); ++p) {...;}  // equivalent to the above expression
for (init; type &x: v)                      // for loop with initialiser; c++20

// for statement
for(iterator, condition, increment){...}
for(int i=0; i!=max; ++i) {...;}    // iterate over i=0 to i=max (excluded)
for(string s; cin>>s; ) {...;}      // terminates when cin>>s returns false (e.g. reading fails)
for( ; *ptr!=0; ++p) {...;}         // iterate over a pointer to a zero-terminated array
for( ; ; ) {...;}                   // same as while(true) {...;} which is preferred

// while statement
while(cond) {...;}          // while loop

// do statement
do {...;} while(cond)       //

// loop exit
break                       // breaks out of the nearest enclosing switch or iteration statements
                            // use when you need to exit loop 'in the middle'
continue                    // skips the rest of the body of an iteration statement

goto identifier;            // jumps to the statement marked by 'identifier'
identifier: statement       // statement marked by 'identifier', i.e. to be executed



//==================== Operators


//---------- Boolean Operations
!x; not x;                  // negation of x
x&&y; x and y;              // logical and
x||y; x or y;               // logiacal or


//---------- Comparison Operators
x==y; x!=y;                 // equality, non-equality
x<y; x>y;                   // less than, greater than
x<=y; x>=y;                 // less than or equal, greater than or equal
x<=>y;                      // three-way comparison; c++20 and <compare> header


//---------- Bitwise Operations
x&y;                        // bitwise and operator
x&=y;                       // x = x & y
x|y;                        // bitwise or operator
x|=y;                       // x = x | y
x<<N; x>>N;                 // left, right shifts bits of x by N
x<<=N; x>>=N;               // x = x<<N; x = x>>N;
x^y;                        // bitwise exclusive or
x^=y;                       // x = x ^ y;


//---------- Arithmetic Operations
x+y; x-y;                   // addition and subtraction
x+=y; x-=y;                 // x = x+y, x = x-y
++x; --x;                   // x = x+1, x = x-1; returns the new value of x
x++; x--;                   // x = x+1, x = x-1; returns the old value of x (might be slower)
+x; -x;                     // unitary plus and minus
x*y; x/y;                   // multiplication, division
x*=y; x/=y;                 // x = x*y, x = x/y
x%y;                        // reminder (modulus) for integers
x%=y;                       // x = x%y


//---------- Ternary Operator
cond ? "cond is true" : "cond is false";



//==================== Operator Precedence

// Precedence   Operator                Description                                                     Associativity
    1           ::                      // Scope resolution                                             Left-to-right
    2           a++   a--               // Suffix/postfix increment and decrement                       Left-to-right
                type()   type{}         // Functional cast                                              Left-to-right
                a()                     // Function call                                                Left-to-right
                a[]                     // Subscript                                                    Left-to-right
                .   ->                  // Member access                                                Left-to-right
    3           ++a   --a               // Prefix increment and decrement                               Right-to-left
                +a   -a                 // Unary plus and minus                                         Right-to-left
                !   ~                   // Logical NOT and bitwise NOT                                  Right-to-left
                (type)                  // C-style cast                                                 Right-to-left
                *a                      // Indirection (dereference)                                    Right-to-left
                &a                      // Address-of                                                   Right-to-left
                sizeof                  // Size-of[note 1]                                              Right-to-left
                co_await                // await-expression (C++20)                                     Right-to-left
                new   new[]             // Dynamic memory allocation                                    Right-to-left
                delete   delete[]       // Dynamic memory deallocation                                  Right-to-left
    4           .*   ->*                // Pointer-to-member                                            Left-to-right
    5           a*b   a/b   a%b         // Multiplication, division, and remainder                      Left-to-right
    6           a+b   a-b               // Addition and subtraction                                     Left-to-right
    7           <<   >>                 // Bitwise left shift and right shift                           Left-to-right
    8           <=>                     // Three-way comparison operator (since C++20)                  Left-to-right
    9           <   <= >   >=           // For relational operators < and ≤ and > and ≥ respectively    Left-to-right
    10          ==   !=                 // For equality operators = and ≠ respectively                  Left-to-right
    11          &                       // Bitwise AND                                                  Left-to-right
    12          ^                       // Bitwise XOR (exclusive or)                                   Left-to-right
    13          |                       // Bitwise OR (inclusive or)                                    Left-to-right
    14          &&                      // Logical AND                                                  Left-to-right
    15          ||                      // Logical OR                                                   Left-to-right
    16          a?b:c                   // Ternary conditional[note 2]                                  Right-to-left
                throw                   // throw operator                                               Right-to-left
                co_yield                // yield-expression (C++20)                                     Right-to-left
                =                       // Direct assignment (provided by default for C++ classes)      Right-to-left
                +=   -=                 // Compound assignment by sum and difference                    Right-to-left
                *=   /=   %=            // Compound assignment by product, quotient, and remainder      Right-to-left
                <<=   >>=               // Compound assignment by bitwise left shift and right shift    Right-to-left
                &=   ^=   |=            // Compound assignment by bitwise AND, XOR, and OR              Right-to-left
    17          ,                       // Comma                                                        Left-to-right



//==================== Functions

//---------- Function Declarations and Definitions
// Functions and Procedures
type f(type a, ...)         // required parts of a function declaration: return type, name, argument list
void f(type a, ...){...;}   // same as above with a definition in {...;}
auto f(...) -> type         // same as above with a suffix return type
auto f(...) -> void {...;}  // same as above with a definition in {...;}

static type id              // in the fct body allows the fct to preserve info between calls
__func__                    // name of the function; accessible in the functin body

// specifiers and modifiers
[[noreturn]]                // not using the standard call-return mechanism, usage with return is undefined
inline                      // implemented by in-lining (before return type)
constexpr                   // is a constant expression (before return type)
static                      // linkage specification (before return type)
noexcept                    // may not throw an exception (after arg. list)
noexcept(cond)              // may not throw an exception if (constexpr) cond is true (after arg. list)
noexcept(noexcept(expr))    // if all operations in expr have noexcept, return true else return false

// specifiers and modifiers for member functions
virtual                     // can be overridden in a derived class
override                    // must be overridden in a derived class
final                       // can't be overridden in a derived class
static                      // not associated with a particular object
const                       // can't modify its object


//---------- Attributes
[[nodiscard]] int fct();                // compiler issues a warning if the return value is discarded
[[nodiscard("reason")]]                 // provides an explanation for nodiscard; c++20
int fct([[maybe_unused]] int param)     // suppresses compiler warning for unused parameter of a fct
[[noreturn]] void kill();               // suppresses compiler warning for functions that do not return (process termination, etc.)
[[deprecated]] int fct();               // compiler issues a warning that the function is deprecated
[[deprecated("reason")]]                // provides an explanation for deprecated; c++20
[[likely]], [[unlikely]]                // gives compiler hint how (un)likely certain branch is to be executed (if-else; switch)


//---------- Argument Passing
int printf(const char * ...);   // a std fct takse a C-style string and ellipsis - additional arguments
// examples of printf() in use %s denotes char *, %d denotes int
printf("Hello, world!");
printf("My name is %s %s.", first_name ,second_name);
printf("%d + %d = %d",2,3,5);


//---------- Pointer to a Function
void f(string);         // a fct taking a string returning nothing
void (*pf)(string);     // a pointer to void(string) fct
pf = &f; pf = f;        // two ways how to assign function address to a pointer
pf("message");          // is equivalent to the function call, f("message")

// better approach is to use std::function from <functional>
using fctPtr = bool(*)(int, int);               // defines an alias for a function taking two ints and returning a bool
bool f(fctPtr myfct) { return myfct(1, 1); };   // takes an instance of fctPtr and calls it in the body
bool f(bool(*myfct)(int, int)) {/*...*/};       // same as above but without using the alias
bool f(bool(*)(int, int) myfct) {/*...*/};      // equivalent to the above
template<typename T> bool f(T myfct) {/*...*/}; // as above, but with template
bool f(auto myfct) {/*...*/};                   // as above, c++20


//---------- Lambda Function
[capture_block] <template_params> (parameters) mutable constexpr noexcept_specifier attributes -> return_type requires {body}
// capture_block           // cptr_lst captures elems in the scope; if empty the lambda is called stateless
// template_params         // template is c++20
// parameters              // params are as in normal fcts; can be ommited is no params present and no mutable, constexpr, noexcept
// mutable                 // the generated function obj has non-const op(); else the op() is const, i.e. can't change captured params
// constexpr               // implicitely constexpr if it fulfills the criteria
// noexcept_specifier      // as for normal fcts
// attributes              // attributes, check notes
// return_type             //
// requires                // template type constraints c++20
// body                    //

// lambdas can be params if one uses std::function with matching signature or template

[cptr_lst](params){...;};   // cptr_lst captures elems in the scope, params are as in normal fcts; compiler creates a function object with const op()
[cptr_lst]{...;};           // () can be omitted if no parameters are to be passed
[&]; [=]; []; [a, &b];      // capture all by reference; all by copy (this is not implicitly captured c++20); nothing; a by copy, b by reference
[&, cpt_lst]; [=, &cpt_lst];// capture all by reference but cpt_lst; capture all by copy but cpt_lst
[this]; [*this];;           // captures the current object via pointer/copy; if [this] the obj has to be alive; access to all members
[a]()mutable{...;};         // a is captured by copy and can be modified by the lambda fct; makes the op() non-const
[myCapture = "Pi: ", pi]{}; // capture expression; usefull for vars that can't be copied (e.g. unique_ptr)

[...](...)->type {...;};                        // specified return type of lambda fct; type can be decltype(auto) to preserve refs and const
[] <typename T> (const vector<T>& values) {};   // ussage of the template
[] (const auto &par) {};                        // parameters can have auto type; compiler generates templatised version of op()

[] <typename T> (T &v1, T &v2) requires integral<T> {}; // template lambda with an integral constraint

function<int(void)> multBy2Lmbd(int x) { return [x]{ return 2 * x; }; } // allows lambda to be a return type
auto multiplyBy2Lambda(int x) { return [x]{ return 2 * x; }; }          // same as above
using LambdaType = decltype([](int a, int b) { return a + b; });        // valid only in c++20



//==================== Modules

// - make splitting declarations and definitions in different files obsolete;
// - can be split into "submodules" using dots: my.module.name; (p.404 professional c++, 5th edition)

// module interface files
//  - have .cppm extension (not standardised yet)
//  - only exported things will be visible
export module moduleName;   // named module declaration, exports module name
export namespace myN {...;} // exports everything in the namespace
export class MyClass;       // exports class
export struct MyStruct;     // exports struct
export {...;}               // export block, exports everything declared inside
export import MyClass;      // imports MyClass and also exports it so it's also visible when importing only the current module

import <iostream>           // <> are used for std modules
import moduleName           // no <> can be used

// module implementation file
//  - can't export anything
//  - all imports/includes from interface file are visible here; only true for the implementation files of the module
module moduleName;          // automatically imports all things declared in the interface file

// the global module fragment (interface and implementation files)
module;                     // starts the global module fragment
#include <cLIB>             // c headers can only be included in the global module fragment
export module moduleName;   // named module declaration ends the global module fragment in the interface file
module moduleName;          // named module declaration ends the global module fragment in the implementation file
import xyzModule;           // all imports need to follow the named module declaration



//==================== Structures, Unions, and Enumerations

//---------- Structures
struct MyStruct {                   // definition of a structure, can have member fcts (as class, but default specifier is public)
    string var1;                    // can hold variables of any type
    int var2;                       // members are in memory in order they were defined
};
MyStruct mstrct1 {"string", 2};     // memberwise initialisation
MyStruct mstrct2 {.var1 = "var"}    // designated initialiser, more clear what's initialised; uninitialised members are default-initialised
MyStruct mstrct3 {mstrct1};         // copy initialisation
MyStruct mstrct4 {};                // default initialisation equivalent to mstrct3 {{}, {}}

ptr->member;                    // access to members through - a pointer
instance.member;                //                   through - a name or a reference

auto [v1, v2] {mstrct1};        // initialises string v1 to var1 and int v2 to var2 of the mstrct1
auto &[v1, v2] {mstrct1};       // initialises string reference v1 to refer to var1 and int reference v2 to var2 of the mstrct1
const auto &[v1, v2] {mstrct1}; // initialises string reference v1 to refer to var1, int reference v2 to var2, and makes both constant

// Bit-fields
struct bit_fields {             // bit-field must be of integral or enumeration type and confined in a structure
unsigned int PFN : 22;          // this one takes 22 bits
int : 3;                        // unused 3 bits
bool dirty : 1; };              // boolean var using 1 bit


//---------- Unions
// Unions allocate members at the same address
union myU {                 // definition of an union
char *s;                    // s and i have the same address
int i;                      // s and i have the same address
};


//---------- Enumerations
// Plain Enumeration, not recommended, they mix up scopes as they are exported to the enclosing scope (analogous to using enum Color for 'enum class')
enum Color {                // definition of a plain enumeration with default ops =, ==, <, >; ?more ops can be defined?
    red, green, blue};      // elements are implicitly converted to integers
TrafficL x = blue;          // okay
TrafficL x = 2;             // error

// Enumeration Class
enum class Color : long {   // enum class internaly represented as long (default is int); default ops =, ==, <, >; more ops can be defined
    red=1, green, blue=5};  // elements represented as integers, starting with 1 (the default is 0); green is 2 (previous + 1)

Color x = TraffidL::red;    // definition of an instance red
Color x = red; Color x = 2; // error

using enum Color;           // red can be used without the Color:: prefix
using Color::red;           // red can be used without the prefix, but other colours can't



//==================== Modules c++20
export; module; import;         // keywords
// module interface file
export module NAME;             // exports module name
export class X {...};           // specifies which classes of the module are accessible
// module implementation file
module NAME;                    // specifies for which module the implementation methods are
X::member_fct() {...};          // defines the member_fct



//==================== Classes

//---------- Class Definition, Initialisation, Member Functions
public:                     // members are visible to everyone (the class, derived class, outside of the class)
protected:                  // members are visible only to the members of the class and to members of the derived class
private:                    // members are visible only to the members of the class
;

class X {                       // class definition, members private by default
private:                        // only members can access (default)
    type data1;                 // declaration of a data member
    int x = 7;                  // in-class initialiser; x will be 7 if the constructor doesn't change it
    int y { 7 };                // as above, preffered (best practice: always initialise memebers)
    int &ref;                   // reference data member; must be initialised in the constructor initialiser
    cont int &ref1;             // reference to const data member; must be initialised in the constructor initialiser
    mutable int x1              // modifiable even in a const instance of the class or by const method, e.g. 'Get1() const' can change this
    static int s_data;          // static data member, only one for all instances
    static inline int s_i { 0 };// inline static data member, no need to initialise the static member (as opposed to s_data); c++17
    static cont int s_max { 9 };// const static data member, can be initialised in the class declaration
    static X dflt;              // as above; the X (class's) type can be used as a default for constructor, static member fct can set it
protected:                      // only members, friends, derived classes (with public or protected access).
public:                         // everyone can access
    // the default constructors, copy/move constructor/assignment are generated by the compiler (they are non-virtual!); but if any
    //    - constructor is provided the default constructor is not generated by the compiler
    //    - copy/move constructor/assignment or destructor are provided, none of the other defaults are generated by the compiler
    // to get back the default declare it =default; to delete the default declare it =delete
    // if a class member has deleted default (or copy) constructor the class itself has deleted default (or copy) constructor
    X();                    // default constructor declaration, declared and defined by compiler by default if no constructor is provided
    X(type);                // "ordinary" constructor declaration
    X(type1) = delete;      // deletes constructor taking type1 as an argument, i.e. prevents undesired convertions from type1 to type
    explicit X(int);        // explicit constructor declaration; prevents following X x = {1}; X x = 1; but allows X x = X(1); and X x{1};
    explicit(expr) X(int);  // explicit is used only if expr evaluates to true; usefull e.g. for templates

    X(const X&);                // copy constructor declaration, e.g. X x = y; the default generated initialises all members in the initialiser
    X& operator=(const X&);     // copy assignment declaration,  e.g.   x = y;
    X(X &&) noexcept;           // move constructor declaration, e.g. X x = f(...);  noexcept is for compatibility with std::
    X& operator=(X&&) noexcept; // move assignment declaration,  e.g.   x = f(...);    ->(e.g. moving objecte when resizing vectors)
    virtual ~X();               // destructor declaration, no arguments, can be only one, used to release heap memory; make always virtual;
    virtual ~X() = default;     // makes default constructor virtual (needed for inheritance); all destructors are implicitly marked as noexcept

    static void sFct();             // static fct, does not have this pointer, sees only static members; static keyword not repeated in the definition
    void SetValue(int v);           // everybody can access
    void SetValue1(int v=0);        // with default; default is only in the declaration
    int& Get() {return &x;};        // in-class function definition, the function is considered to be inline (if compiler agrees)
    inline int& Get();              // inlined (if compiler agrees); definition should be in the same file (advanced compilers don't require this)
    const int& Get() const {...};   // const overload of get; use Scott Meyer’s const_cast() pattern (def the const one and const_cast for non-const)
    int Get1() const;               // does not allow to modify any data members except the mutable ones

    type fct1() & {...};            // can only be called on non-temporary instances
    type fct2() && {...};           // can only be called on     temporary instances
};

// static data member initialisation;
int X::s_data;          // initialisation of the static data member (necessary); default initialisation is 0 (for primitive types)
int X::s_data { 1 };    // as above, just custom explicit initialisation
X X::dflt;              // as above

// member function definitions
X::X() {...;}                   // default constructor definition; called as this: 'X myX {};' or 'X myX;' 'X myX();' is fct declaration!
X::X(type) {x{1}, x1{2}, ...;}  // "ordinary" constructor definition, x is set to 1 and x1 to 2
X::X(type):x{1}, x1{2} {...;}   // same as above just with an initialiser for the data member x and x1
X::X(int x) {...;}              // explicit constructor definition, do not repeat 'explicit'

X::X(const X &x) {...;}             // copy constructor definition,   copy all memory (non-heap and heap) from src to dst
X& X::operator=(const X &x) {...;}  // copy assignment definition,    copy all memory (non-heap and heap) from src to dst (check sizes for heap)
X::X(const X &&x) {...;}            // move constructor declaration, steal all memory (non-heap and heap) from src and leave it with nullptrs
X& X::operator=(const X &&x) {...;} // move assignment definition,    swap all memory (non-heap and heap) between src and dst
X::~X() {...;}                      // destructor definition; delete all heap memory

void X::sFct() {...;}               // definition of the static method
void X::SetValue(int v) {...;}      // definition of a member function
void X::SetValue1(int v) {...;}     // with default
int X::Get1() const {...;}          // the const keyword if required in the definition as well


//---------- Friend Functions and Classes
//  - can access private and protected members of a class
//  - declarations are placed in the class definition; friend function definitions don't have scope resolution ::, i.e.  type fct(...) {...;}
class Foo {                             // friend keyword is not repeated in the definitions; can be
    friend class Bar;                   // Bar class is a friend of Foo (all methods of Bar can access private and protected methods of Foo)
    friend void Bar::doFoo(const Foo&); // only doFoo method of Bar class is a friend of Foo
    friend type fct();                  // stand-alon fct can access private and protected members of Foo
};


//---------- Operator overloading
// meaning for the following operators can be defined for a class T and another class E; see (p.540 professional c++, 5th edition)
+ − * / %               // binary arithmetic ops; recommended as global function; T operator+(const T&, const T/E&)
+ − ~                   // unitary arithmetic and bitwise ops; recommended as method; T operator-() const
++ --                   // pre-/post- in/de -crement; recommended as method; (pre-) T& operator(); (post-) T opeartor++(int)
=                       // assignment op; required as method; T& operator=(const T&)
+= −= *= /= %=          // short arithmetic ops; recommended as method; T& operator+= (const T/E&)
<< >> & | ^             // binary bitwise ops; recommended as global function; T operator<< (const T&, const T/E&)
>>= <<= &= |= ^=        // short bitwise ops; recommended as method; T& operator<<= (const T/E&)
<=>                     // three-way comp op; recommended as method; auto operator<=> (const T&) const; partial_ordering operator<=>(const E&) const
== !=                   // equality/inequality; recommended as method (c++20); bool operator== (const T/E&) const
!                       // boolean negation op; recommended as method; bool operator!() const
< > <= >=               // comparison ops; recommended as global function; bool operator< (const T&, const T/E&)
<< >>                   // I/O ops; recommended as global function; ostream& operator<<(ostream&, const T&); istream& operator>>(istream&, T&)
&& ||                   // bin boolean ops; recommended as global function; bool operator&&(const T&, const T&);
[]                      // subscripting; required as method; E& operator[](size_t); const E& operator[] (size_t) const;
()                      // function call; required as method;
""_x                    // user defined literal op; global function required; T operator""_i(long double d);
new new[]               // memory ops; recommended as method; void* operator new(size_t size); void* operator new[](size_t size);
delete delete[]         // memory ops; recommended as method; void operator delete(void* ptr) noexcept; void operator delete[](void* ptr) noexcept;
* −>                    // dereferencing ops; required as method; E& operator*() const; E* operator->() const;
&                       // address of; should never change
−>*                     // deref. pointer to memeber; should never change
,                       // comma operator; should never change

= & ,                   // assignment, address-of, sequencing can explicitely be deleted or given new meaning

:: . .* ?:              // cannot be defined by user
sizeof alignof typeids  // cannot be defined by user

operator T()                    // defines a conversion to a type T
X::operator int() const {...;}  // defines a conversion from a user-defined type to int (no return type)

// unitary and binary operators as member and non-member fcts
// unitary operators do not have arguments in (), example is the prefix operator++() below
class X {
public:
    X& oparator+=(int)      // member     binary       (one argument)  += -increment- ; should be always method; returns a refefence to the lhs
    X oparator+(X)          // member     binary       (one argument)  +  -addition-  ; should be implemented in terms of the above (as a non-member)
    X* operator&();         // member     prefix unary (no arguments)  &  -address of-
    X operator&(X);         // member     binary       (one argument)  &  -and-
};
// global operators:
// their advantage is that they are not tied to the class object (in certain cases this implies commutativity)
void operator+(X, X);           // non-member binary       (two arguments) + -addition-
void operator+(X, double);      // non-member binary       (two arguments) + -addition-
X operator-(X);                 // non-member prefix unary (one argument)  - -negative of-
X operator-(X, X);              // non-member binary       (two arguments) - -subtraction-

// comparison ops pre c++20
bool operator<op>(const X&, const X&);  // should be non-member to support implicit conversions; <op> in (==, <, >, !=, <=, >=)
// comparison ops post c++20; all should be member fcts
[[nodiscard]] bool operator==(const X&) const;  // compiler can reorder arguments to use implicit conversions; != is generated by the compiler
[[nodiscard]] bool operator==(double) const;    // compiler can reorder arguments so 9.0==X works; != is generated by the compiler
[[nodiscard]] partial_ordering operator<=>(const X&) const; // (<, >, <=, >=) are generated by compiler; e.g. X1<X2 is std::is_lt(X1<=>X2)
[[nodiscard]] partial_ordering operator<=>(double) const;   // (<, >, <=, >=) are generated by compiler; arguments can be reordered

[[nodiscard]] partial_ordering operator<=>(const X&) const = default;   // compiler can generate all comparisons; default compares member by member
[[nodiscard]] partial_ordering operator==(const X&) const = default;    // needed if custom operator== is defined; e.g. operator==(double)

// special operators:
[] () −> ++ −−
operator[](args);           // must be a non-static member function, for a class X it allows instance[args] call; 19.2.1
operator()(args);           // must be a non-static member function, for a class X it allows instance(args) call; also called function objects
operator->();               // must be a non-static member function, I DIDN'T GET THIS PROPERLY; 19.2.3
operator++();               // prefix, structure used for all unitary operators
operator++(int);            // postfix, the int is a dummy argument to distinguish between pre-fix and post-fix

// memory operators: (p.563 professional c++, 5th edition)
void* operator new(size_t);
void  operator delete(void*, size_t);
void* operator new[](size_t);
void  operator delete[](void*, size_t);
void* operator new(size_t, const std::nothrow_t&) noexcept;
void operator delete(void*, const std::nothrow_t&) noexcept;
void* operator new[](size_t, const std::nothrow_t&) noexcept;
void operator delete[](void*, const std::nothrow_t&) noexcept;

// conversion operators; they don't have a return type (it's deduced from the name)
explicit X::operator double() const;    // explicit is optional
explicit X::operator int() const;       // explicit is optional
X::operator void*() const;              // converts to pointer


//---------- User-defined literals
complex<double> operator"" _i(double);      // declares cooked literal; ussage: complex<double> c1 { 9.6_i }; auto c2 { 1.2_i }
complex<double> operator"" _i(const char*)  // declares raw-mode literal; needs to pars the \0 terminated c_string; ussage same as above
string operator"" _s(const char*, size_t)   // declares cooked literal; ussage: string str1 { "Hello World"_s }; auto str2 { "Hello World"_s }

// std reserves all suffixes not starting with an underscore, always start user-defined suffixes with _
LITERAL                 CREATES INSTANCES OF    EXAMPLE                             REQUIRES NAMESPACE
s                       string                  auto myString {"Hello"s };          string_literals
sv                      string_view             auto myStringView {"Hello"sv };     string_view_literals
h, min, s, ms, us, ns   chrono::duration        auto myDuration{ 42min };           chrono_literals
y, d                    chrono::year and day    auto thisYear{ 2020y };             chrono_literals
i, il, if               complex<T>              auto myComplexNumber { 1.3i };      complex_literals

operator""                                          // defines user-defined literals, for example 12e3 (12*10^3)
constexpr complex operator"" i(long double d);      // could be used as 12e3i meaning complex{0, 12e3}
std::string operator"" s(const char *p, size_t n)   // used as "someText"s

// 4 literals to be suffixed to define new one
unsigned long long or const char*               // integral literal, char* passes C-style string
long double or const char*                      // floating-point literal, char* passes C-style string
(const char*, size_t)                           // string literal
char or wchar_t or char16_t or char32_t         // character literal

// template literal operator
template<char...>
constexpr int operator"" _b3();     // base 3, i.e., ternar y
201_b3;                             // means operator"" b3<’2’,’0’,’1’>(); so 9*2+0*3+1 == 19


//---------- Method Pointers
using metPtr = int (T::*)();        // defines an alias for a method of T taking no arguments and returning an int
metPtr myMetPtr { &T::met };        // defines a var of type metPtr (a method pointer) and initialises it with a method of T called met
auto myMetPtr { &T::met };          // same as the two lines above
T myT{}, *myTp{};                   // constructs an instance of T (with default constructor)
(myT.*myMetPtr)();                  // calls myT.met() using the above pointer to a method
(myTp->*myMetPtr)();                // as above but with pointer to an instance T



//==================== Derived Classes

//---------- Derived Class Definition
// default access specifier for parents is private for classes and public for struct; non-public inheritance is rare
class D: (virtual) <access_spec> B {...;};      // template for defining a Derived class; virtual Base class (p.389 professional c++, 5th edition)
// members\access_spec  public      protected   private
//  public               public      protected   private
//  protected            protected   protected   private
//  private              N/A         N/A         N/A

class Foo final {...;};             // no class can inherit from Foo

class Employee {...;};
class Manager {                     // bad design!  Manager class contains Employee as a member data for 'is a relationship'
    Employee emp;...;};
class Manager: public Employee {    // good design! Manager class is derived from Employee class (would be bad if 'has a relationship')
    ...;};

Employee *pe = &mm;                 // mm is an instance of Manager, which is also an Employee
Manager *pm = &ee;                  // error: ee is an instance of Employee, which is not a Manager


//---------- Base Initialisers
// objects are constructed bottom-up (base before member) and destructed top-down (member before base)
// class can initialise its members and bases (but not directly members or bases of its bases)
class B1 {B1();};           // has a default constructor
class B2 {B2(int);          // does not have a default constructor
class D1: B1, B2 {          // class with two base classes
    D1(int i)               // constructor of the derived class
        :B1{}, B2{i} {...;} // bases are initialised before and destroyed after members; B1 default constructor is called by default (can be ommited)
    D1() :D1{0} {...;}      // delegating constructor, uses another constructor
};


//---------- Members and Member Functions
// destructors in a hierarchy need to be virtual
// copy constructors of classes in a hierarchy should be used with care (if at all) to avoid slicing
// function overriding virtual function becomes itself virtual
// avoid having different default values for base function and its derived override! (p.382 professional c++, 5th edition)
class B {
    virtual void fct();             // a virtual function
    virtual void fct0();            // a virtual function
    virtual void fct0(int);         // a virtual function
    virtual void fct1() const = 0;  // pure virtual functions do not need to be defined; virtual keyword is not repeated in the definition
    virtual void fct2();            // virtual keyword is not repeated in the definition
    void fct3();                    // normal method, can't be overriden
};

class D: public B {
    using B::B;                         // explicitely inherits all the base constructors
    using B::fct();                     // explicitely inherits all the overloads of the base method fct (here only one); changes access specifier
    virtual void fct(int);              // adds a new overload of the inherited fct(), doing this is rare
    virtual void fct0(int) override;    // overriding one overloaded base method hids all other base overloads; i.e. fct0() no longer accessible
    using B::fct0();                    //  ...one needs to explicitely inherit the not overriden base overloads of fct0; not recommended
    virtual void fct1() const override; // same argument list needed; use of virtual is optional and override is optional but recommended
    final void fct2();                  // fct2 cannot be overriden
    ...;};

D::D(const D &src) : B {src} {...;}     // copy constructor of D has to call the B's copy constructor (else B's dflt constructor is called -> wrong)
D& D::operator=(const D &rhs) {         // assignment operator
    if (&rhs == this) {return *this;}
    B::operator=(rhs);                  // B's assignment operator has to be called (else only part of the object will be assigned)
    // more code
    this->base_met_or_member;           // required to call base methods or base data members; alternative below
    B::base_met_or_member;              // required to call base methods or base data members; alternative aboved
    return *this;
}


//---------- enable_shared_from_this<T>
class X : public std::enable_shared_from_this<X> { }    // X is derived from enable_shared_from_this
X.shared_from_this()                // returns shared_ptr if the instance has been stored in a shared pointer, else bad_weak_ptr exception is thrown
X.weak_from_this()                  // teruns a weak_ptr if the instance has been stored in a shared pointer, else returns en empty weak_ptr



//==================== Namespaces

namespace My_nspace {...;}  // namespace definition
My_nspace::sth;             // refers to sth in the namespace My_nspace
::sth;                      // refers to sth in the global namespace

namespace {...;}            // an unnamed namespace, accessible only from within the translation unit (usually the file where it is defined)
                            // an unnamed namespace has implied using-directive

using std::string;          // use string to mean std::string, applies to all overloaded versions
using namespace std;        // make every name from std accessible

namespace s_lib = std;      // make namespace alias, usefull for long neasted namespaces like namespace sth = sth1::sth2::sth3;

using namespace std;        // use standard library for everything but String (next line)
using My_lib::String;       // use String from My_lib
using M_str = My_lib::String// rename My_lib::String to M_str (alias)

namespace My_nspace {
    inline namespace v3 {   // default meaning of the namespace My_nspace
        double f(double);
    }
    namespace v2 {          // older namespace
        double f(double);
}}
// example
using namespace My_nspace;
f(1);                       // use the default f from My_nspace
v2::f(1);                   // use the older f from the v2 namespace of My_nspace



//==================== Exceptions

// to set custom program terminations when an exception is not caught see (p.505 professional c++, 5th edition)

try {}                          // tries to perform the code in {}, if an exception is thrown the catch block
catch (const e_type &e) {...;}  //  ...catches the exception of type e_type, and executes the code in {}; catching by reference prevents slicing
catch (...) {}                  //  ...catches all possible exceptions

throw My_error { "msg" };       // throws an exception called My_error
throw;                          // in the catch-block re-throws the caught exception; do not re-throw this way "throw e;" might cause slicing

e.what()                        // returns const char* describing the exception

// function-try-blocks, can be used for constructors (p.530 professional c++, 5th edition)
MyCls::MyCls()
try : ctor_init {/* body */}
catch (...) {/* clean-up */}



//==================== Templates

// compiler generates code for all virtual methods and only called (used) non-virtual methods of a template class
template class Nspc::MyClass<type>;     // explicit instantiation; generates code for all methods; if exists, namespace can't be ommited


//---------- Definition
template<typename T> class Vector {...;};   // specifies a parameter T of the declaration of a class; can have default value e.g. <typename T=int>

template<typename T>                        // specifies a parameter T of the declaration it prefixes (here a member function)
Vector<T>::Vector() {...;}                  // definition of a member function (default constructor here) with a template T
Vector::Vector() {...;}                     // same as above, only valid in the class definition (outside of the class <T> is required)

template <typename T> template <typename E> // cannot be combined into template <typename T, typename E>; usually put on 2 lines
Vector<T>::Vector(const Vector<E>& src)     // copy constructor for template class between different template typas; e.g. T=double; E=int

explicit TmpltName(Params) -> ShouldBe;     // template deduction rules; explicit is optional
Vector(const char*) -> Vector<string>;      // example of the above
Vector myVec { "Hello" };                   // myVec will be of type Vector<string> not Vector<const char*>

template<typename type1, typename type2>    // specifies template parameters to be used by the function
type1 fct(type1 a, type2 b) {...;}          // definition of the function (standard one)
decltype(auto) fct(auto a, auto b) {...;}   // as above; no need for template<typename type1, typename type2> line

// variable templatess
template <typename T> constexpr T pi { T { 3.141592653589793238462643383279502884 } };
float piFloat { pi<float> };


//---------- Non-Type Template Parameters
// non-type tmplt params can be integral types, enums, pointers, and references; c++20 adds floating point nums and some (very restricted) classes
template<typename T, int INT> class Vector {...;}           // Vector class defn with non-type param INT (e.g. used as a default length)
template<typename T, int INT=32> class Vector {...;}        // as above but with a default falue
Vector<int, 32> myVec;                                      // when instantiating, the non-type param needs to be constexpr
template <typename T, const T DFLT = T{}> class Vector {};  // Vector class defn with a default element having a default value
template <typename T, const T& DFLT> class Vector {};       // Vector class defn with a default element as ref. (with internal/external linkage)


//---------- Template Template Parameters
template <..., template <TemplateTypeParams> class ParameterName, ...> class MyClass {};        // template template parameter definition
template <..., template <TemplateTypeParams> typename ParameterName, ...> class MyClass {};     // alternative to the above
// example of a class that takes a parameter T and a container type with default being vector
template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container = std::vector> class MyClass {};


//---------- Function Objects
template<typename T>
class Less_than {                           // Function object, Less_than<int> lti{42};
    const T val;                            // one can now compare int i with 42 like this: lti(i) <=> i<42
    Less_than(const T& v): val{v}{}
    bool operator()(const T& x) const{
        return x<val;}  };


//---------- Variadic Templates
// T&& is only a forwarding reference when it is used as a parameter for a function or method template with T as one of its template parameters
template<typename T1, typename... Tn>       // a template function accepting an arbitrary number of atguments
void f(T1 &&arg1, Tn... &&args) {           // Tn... indicates the rest of the passed list; args are forwarded, not copied
    g(forward<T1>(arg1));                   // apply fct g on head, i.e. the first passed element; g() taking no args required to stop recursion
    f(forward<Tn>(args)...); }              // repeat the function f on the rest of the list (kinda recursion)


//---------- Aliases
template<typename Key, typename Value>
class Map{...;};                            // define generic Map<Key, Value>

template<typename Value>
using String_map = Map<string, Value>;      // define String_map<Value> = Map<string, Value>
String_map<int> m;                          // m is a Map<string, int>


//---------- Concepts c++20
template <typename T> concept name = constrExpr;    // syntax for concepts; constrExpr must result in boolean value or be a requires expression
requires (paramList) { requirements; }              // syntax for requires expression; paramList is optional; 4 types of requirements:
{ expr }                                            //  ...simple; is an arbitrary expression statement
{ typename expr }                                   //  ...type; starts with typename
{ expr } noexcept -> typeConstr;                    //  ...compound; noexcept and typeConstr are optional; to check no-throw or return type of methods
{ requires (paramList) { requirements; } };         //  ...nested; more requirements inside the requirement block.

template <typename T> concept C1 = (sizeof(T) == 4);                                            // a concept with boolean constrExpr
template <typename T> concept C2 = requires (T x) { x++; ++x; };                                // a simple req; T can be incremented
template <typename T> concept C3 = requires { typename T::value_type; };                        // a type req; T has value_type member
template <typename T> concept C4 = requires { typename myClass<T>; };                           // a type req; T can be used in myClass
template <typename T> concept C5 = requires (T x, T y) { { x.swap(y) } noexcept; };             // a compound req; swap does not throw
template <typename T> concept C6 = requires (T x) { { x.size() } -> convertible_to<size_t>; };  // a compound req; size() returns size_t equiv.

// ussage
C2 auto value1 { 1 };            // ok, value1 will be int, int is incrementable (concept C2)
C2 auto value { "abc"s };        // error, string is not incrementable

template <typename T> requires constrExpr void fct(T t);    // T has to fulfill constrExpr; constrExpr is boolean or a requires expression
template <typename T> void fct(T t) requires constrExpr;    // as above
template <conceptName T> fct(T t);                          // alternative to the above
void fct(C2 auto t);                                        // as above; this is still a template function; more readable
template<conceptName T> class ClassName {};                 // as above but for classes

template <convertible_to<bool> T> void handle(const T& t);                              // argument to handle() has to be convertable to boolean
template <typename T> requires convertible_to<T, bool> void process(const T& t);        // as above, different syntax
template <C2 T> void process(const T& t);                                               // argument to process() has to be incrementable
template <typename T> requires C2 void process(const T& t);                             // as above, different syntax
template <typename T> requires (requires(T x) { x++; ++x; }) void process(const T& t);  // as above, but without the need to define C2
template <typename T> requires (sizeof(T) == 4) void process(const T& t);               // same as C1

//---------- Template Specialization and Recursion
// Class Template Specialization; see (p.442 professional c++, 5th edition)
// Class Template Partial Specialization; see (p.884 professional c++, 5th edition)
// Function Template Specialization is not permitted, only through overloading; see (p.888 professional c++, 5th edition)
// Template Recursion; see (p.889 professional c++, 5th edition)



//==================== Source Files and Programs

//---------- Linkage
// file1.cpp
int x = 1;      // definition of x
// file2.cpp
extern int x;   // declaration of x already defined in file1.cpp
extern int y=1; // definition of y, extern is ignored

// translation unit is the result of preprocessing (think of is as of the source file)
// internal/external linkage, i.e. (un)accessibility from other translation units
static int x1=1;            // static implies internal linkage
static, const, constexpr    // all three have internal linkage
extern const char x3 = 'a'  // extern const implies external linkage
// effect of using unnamed namespace is very similar to that of internal linkage

#include <iostream>     // including standard library header
#include "my_header.h"  // including file from the current directory

extern "C" int f();     // extern "C" specifies the linkage directive for using with C-compilers, not semantics (type-checking, etc.)
extern "C" {...;}       // can contain multiple declarations


//---------- Programs
exit();     // first calls the destructors for constructed static objects, might result in an infinite loop
abort();    // does not invoke destructors for constructed static objects
