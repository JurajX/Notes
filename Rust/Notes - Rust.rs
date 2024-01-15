//==================== ==================== ToC
// === Printing Macros
// === Declarations
// === Expressions and Statements
// === Type Aliases
// === Integer
// === Floats
// === Boolean
// === Character
// === Tuple
// === Arrays, Vectors, Slices
// === String Types
// === References
// === Box and Reference Counts
// === Raw Pointers
// === Functions
// === Ownership
// === Structs
// === Enums
// === Optionals and Errors
// === Pattern Matching
// === Traits
// === Statements
// === Operators
// === Keywords


//==================== Printing Macros
println!("{} < {}", 10, 20);        // prints "10 < 20" to stdout
dbg!("haha");                       // prints debug info to stderr, takes and returns ownership, unless passed by reference

//==================== Declarations
let var:type;               // declares an immutable var of type (can be assigned only once)
let var:type = 5;           // as above but with initialisation
let var:type = 6;           // shadows var, can change type

let mut var:type;           // declares a muttable var of type (can be assigned multiple times)
let mut var:type = 5;       // as above but with initialisation

const CONST:type = 3.14;    // declares an immutable constant; type cannot be ommited must be assigned a constexpr (compile-time)
                            //  ...the convention is ALL_CAPS for the names



//==================== Expressions and Statements
4 + 5               // is an expression; returns a value
4 + 5;              // is a statement; does not return a value
let x = 4 + 5;      // is a statement; does not return a value

{                   // start of a block
    let x = 3;      // a statement
    x + 1           // an expression
}                   // the whole block is an expression returning value 4



//==================== Type Aliases
type Bytes = Vec<u8>;       // defines alias for Vec<u8>; same as typedef in c++



//==================== Integer
//---------- types
// i32 is the default
i8, i16, i32, i64, i128     // 8-bit, 16-bit, 32-bit, 64-bit, 128-bit, architecture size signed integers
u8, u16, u32, u64, u128     // 8-bit, 16-bit, 32-bit, 64-bit, 128-bit, architecture size unsigned integers
isize, usize                // architecture size (the same size as an address) signed and unsigned integer

//---------- literals
// _ can be used as visual separator to make numbers more readable
1_i32, 1i32 // represents 1 as i32
98_222      // decimal
0xff        // hex
0o77        // octal
0b1111_0000 // binary

//---------- byte (u8) literals
b'A'        // byte literals of type u8 (only for ASCII)
            // special byte literals
b'\''       // Single quote     39u8
b'\\'       // Backslash        92u8
b'\n'       // Newline          10u8
b'\r'       // Carriage return  13u8
b'\t'       // Tab               9u8

//---------- declarations
let int: u32 = 0xf;        // int is 15
let mut int: u8 = 0xf;     // int is mutable and equal to 15

//---------- members
// XXX can be add, sub, mul, div, rem, neg, abs, pow, shl, shr
checked_XXX                 // return an Option
wrapping_XXX                // return the exact value modulo the range of the type
saturating_XXX              // return the exact value clamped to the range of the type
overflowing_XXX             // return tuple (res, oflwd); res is wrapping operation, oflwd is bool;
     _shl, _shr             //  oflwd ture only if shift distance >= the type bit width; shift applied = requested shift % the type bit width

//---------- type constants
i32::MAX, i32::MIN



//==================== Floats
//---------- types
// f64 is the default
f32, f64                    // IEEE 32-bit, 64-bit float

//---------- literals
2., 2.f64                   // both 64-bit floats
2.f32

//---------- declarations
let flt: f32 = 15.;         // flt is 15_f32
let mut flt = 15.;          // flt is mutable and equal to 15_f64

//---------- members
(2._f64).sqrt();            // square root with an alternative call below
f64::sqrt(2.));             // for all methods see: https://doc.rust-lang.org/std/primitive.f64.html

//---------- type constants
f32::INFINITY, f32::NEG_INFINITY
f32::NAN, f32::MIN, f32::MAX

std::f32::consts, std::f64::consts  // provide mathematical constants; see: https://doc.rust-lang.org/std/f64/consts/index.html



//==================== Boolean
//---------- types
bool                        // true or false; takes 8-bits in memory

//---------- declarations
let b: bool = true;         // b is true
let mut b = false;          // b is mutable and equal to false



//==================== Character
// u8 is used for byte values (as char is 32-bit wide)
//---------- types
char                        // unicode 32-bit wide; ranges from U+0000 to U+D7FF and U+E000 to U+10FFFF inclusive

//---------- declarations
let ch: char = 'A';         // ch is a 32-bit long character holding letter A
let mut ch = 'B';           // as above, just mutable and holding B



//==================== Tuple
//---------- types
(i8, f32, char)             // tuple with mixed types
(i8,)                       // single value tuple; the comma is necessary
()                          // 'unit' - an empty tuple

//---------- declarations
let tup: (i32, f64, u8) = (500, 6.4, 1);    // declares and assigns a tuple
tup.0, tup.1, tup.2;                        // access the elements of tuple
let (x, y, z) = tup;                        // destructuring of tuple; x, y, z are of type i32, f64, u8, respectively

let tup: () = ();                           // a special tuple called 'unit'; represents an empty value or an empty return type



//==================== Arrays, Vectors, Slices
//---------- types
[T; N];                     // type denoting a const size array of length N with values of type T
Vec<T>;                     // dynamically allocated sequence with values of type T
&[T], &mut [T];             // (mutable) slice of a sequence container (vector, array, string, etc.)

//---------- declarations
let v: [i32; 2] = [1, 2];           // declaration of an array holding [1, 2]
let v: [i32; 2] = [5; 2];           // declaration of an array holding [5, 5]
let v: Vec = Vec::<i32>::new();     // creates an empty vector of type i32
Vec::<i32>::with_capacity(N);       // use to allocate capacity at creation
let v: Vec<i32> = (1..2).collect(); // creates a vector containing [1, 2]
let v: Vec<i32> = vec![1, 2];       // creates a vector containing [1, 2]
let v: Vec<i32> = vec![5; 2];       // creates a vector containing [5, 5]
let vr: &[i32] = &v[1..3];          // creates a slice of length 2, starting at 1-st (0-indexed) element
let vr: &[i32] = &v[1..v.len()];    // creates a slice starting at 1-st (0-indexed) element
let vr: &[i32] = &v[1..];           // as above
let vr: &[i32] = &v;                // creates a slice starting at 0-th (0-indexed) element
let vr: &[i32] = &v[..];            // as above

//---------- indexing
v[i];                       // i-th element of v; i must be 'usize' and in [ 0, v.len() - 1 ]



//==================== String Types
// stored in memory as UTF-8 with variable-width encoding

//---------- types
String;                     // dyn. sized heap string (i.e. Vec<u8> guaranteed to hold well-formed UTF-8 chars)
&str;                       // ref. to a UTF-8 (i.e. &[u8] guaranteed as above); can be ref to a string literal living in read-only memory
&mut str;                   // exists but can't modify the strings; only make_ascii_uppercase and make_ascii_lowercase are allowed

//---------- declarations
let s = String::from("hi"); // creates a String
let s = "hi".to_string();   // converts &str to String

let s = "Hi, world!";       // defines a string literal saved in read-only memory with the code
let s:&str = "Hi, world!";  // as above
let ss: &str = s[0..1];     // slice (reference to the original) containing "H"
let s: &[u8; 3] = b"GET";   // byte string; use br"text" for raw byte strings


//---------- ways to create string
"\"Ouch!\" he said.\n";     // classic escaping of characters
"line 1,
    line 2 with spaces";    // new line character and leading white spaces are included
"line 1\
    still line 1"           // new line character and leading white spaces are dropped
r"raw string";              // everything inside is included verbatim; r##"alternative with # signs"##



//==================== References
// non-owning pointers that must not outlive their referent
//---------- types
&T;                         // a reference to type T; allows for multiple readers
&mut T;                     // a mutable references; prohibits having any other way accessing the value (single writer)

//---------- declarations
let r: &T = &x;             // r stores a reference to the variable x
let rr: &&T = &r;           // rr stores a reference to a reference to variable x; can be chained undefinitely
*r;                         // dereferencing a reference
r.member;                   // the dot operator automatically dereferences the reference; i.e. (*r).member
r1 == r2; rr1 == rr2;       // both compare values (as many dereferences as needed are applied); to compare addresses use std::ptr::eq
r1 == rr1;                  // this is not allowed

//----------



//==================== Box and Reference Counts
//---------- types
Box<T>                      // a smart pointer owning pointer to value on the heap (unique_ptr)
std::rc::Arc<T>;            // atomic reference count, used for thread-safe code
std::rc::Rc<T>;             // reference count, used for non-thread-safe code (shared_ptr)
std::rc::Weak<T>;           // weak pointer; (weak_ptr)

//---------- declarations
let t = (12, "eggs");       // defines a tuple
let b = Box::new(t);        // allocates a tuple on the heap

let s: Rc<String> = Rc::new("str".to_string()); // creates a string rc pointer; read-only; behaves as a variable
let t: Rc<String> = s.clone();                  // increases a reference count



//==================== Raw Pointers
// can be dereferenced only within an 'unsafe' block
*mut T, *const T;           // mutable or constant raw pointer; works as in c++



//==================== Functions
// the convention are snake-case function names
// must be defined somewhere in a scope that can be seen by the caller (not necesarily before the call)
fn fct() {/*...*/}                          // a function with no return
fn fct(x:i32, y:f32) {/*...*/}              // a function with parameters i32 and f32; and no return
fn fct(x:i32) -> i32 {                      // a function with a parameter i32 returning i32
    x + 1                                   // implicit return statement; can be replaced by 'return x + 1;'
}

//---------- pointers and lambdas
fn(&str) -> bool            // pointer to function taking a string and returning a boolean, e.g. 'str::is_empty'
                            // closure, e.g. '|a, b| { a*a + b*b }'



//==================== Ownership

//---------- Assignment and Functions
fn fct(s: String) -> String {/*...*/};  // a fn taking a string
let s1 = String::from("hello");         // creates a string
let s2 = s1;                            // moves s1 into s2; s1 cannot be used after this point
let s3 = fct(s2);                       // moves s2 into the fct, s2 cannot be used after this point; s3 contain the string moved from the fct

//---------- Cloning
let s1 = String::from("hello");
let s2 = s1.clone();
println!("s1 = {}, s2 = {}", s1, s2);

//---------- References and Borrowing
// const reference
fn fct(s: &String) {/*...*/};       // a fn taking a string reference
                                    // reference is guaranteed to point to a valid value for the life of that reference
let s1 = String::from("hello");     // creates a string
fct(&s1);                           // passes a reference; does not move s1 anywhere

// mutable reference
fn fct(s: &mut String) {/*...*/};   // a fn taking a mutable string reference
let s1 = String::from("hello");     // creates a string
fct(&mut s1);                       // passes a reference; does not move s1 anywhere

// Mutable references cannot coexist with other mutable or immutable references to the same variable!
let r1 = &s; // no problem
let r2 = &s; // no problem
let r3 = &mut s; // BIG PROBLEM, immutable references already exist
let r4 = &mut s; // BIG PROBLEM, both mutable and immutable references aready exist

// Reference's scope lasts untill its last ussage (Non-Lexical Lifetime)
let r1 = &s;                        // no problem
let r2 = &s;                        // no problem
println!("{} and {}", r1, r2);      // variables r1 and r2 will not be used after this point
let r3 = &mut s;                    // no problem
println!("{}", r3);



//==================== Structs
#[derive(Debug)]                    // kinda decorator; helps with printing the struct with println!()
struct Rectangle {                  // struct definition
    width: i64,                     // member field and its type
    height: u64,                    // member field and its type
}

impl Rectangle {                    // implementation block for associated functions; multiple impl blocks are allowed
    fn area(&self) -> u32 {         // member function; shorthand for area(self: &Self), i.e. it borrows a reference
        self.width * self.height    // returns the expression (no semicolon); equivalent to return ...;
    }
    fn square(size: u32) -> Self {  // 'constructor' for a square rectangle; Self is alias for Rectangle
        Self {
            width: size, height: size,
        }
    }
}

let st1 = Rectangle {               // instantiation of a struct
        width: 1,                   // assigning to the width
        height: 1,                  // assigning to the height
};
st1.width;                          // accessing the member width
println!("{:#?}", st1)              // displays "Rectangle { width: 30, height: 50 }"; connected to #[derive(Debug)]
println!("{:?}", st1)               // displays "Rectangle { width: 30, height: 50 }" with each memeber on a new line

let st2 = Rectangle {                // another instance of struct
    width: 10,                      // assigning to the width
    ..st1                           // move the remaining fields from st1; st1 no longer usable if it had heap allocated data
};

let sq = Rectangle::square(3);      // using the 'constructor'


fn build_rect(width: i64, height: u64) -> Rectangle {
    Rectangle (                     // the rectangle instance will be moved
        width: width,               // assigning the width
        height                      // shorthand for height: height, only possible with same-name params
    )
}

//---------- Tuple Structs
struct Color(i32, i32, i32);        // define a tuple struct; i.e. a named tuple
struct Point(i32, i32, i32);        // is different type from the above

//---------- Unit-Like Structs
struct AlwaysEqual;                 // does not have any field



//==================== Enums
enum Attend {               // enumeration value can only be one of its variants
    OnTime,                 // elements/variants can be empty
    Late(u32)               // ... or hold a value
}

enum Message {                      // enumeration value can only be one of its variants
    Quit,                           // has no data associated with it
    Move { x: i32, y: i32 },        // has named fields, like a struct does
    Write(String),                  // includes a single String
    ChangeColor(i32, i32, i32),     // includes three i32 values
}

impl Message {                      // implementation block for member functions
    fn call(&self) {/*...*/}
}
let m = Message::Write(String::from("hello"));
m.call();

enum IpAddrKind {
    V4(u8, u8, u8, u8),
    V6(String),
}
let home = IpAddr::V4(127, 0, 0, 1);
let loopback = IpAddr::V6(String::from("::1"));



//==================== Optionals and Errors
Option<&str>                // optional value, either None or Some(value); e.g. 'None' or 'Some("Dr.")'
Result<u64, Error>          // result of op. that may fail, either Ok(value) or Err(e); e.g. 'Ok(123)' or 'Err(Error::last_os_error())'



//==================== Pattern Matching
enum UsState {Alabama/*,...*/}
enum Coin { Penny, Nickel, Dime, Quarter(UsState)}
fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {:?}!", state);
            25
        }
        other => do_sth(other),     // placed at the end, calls a specific fn on other values (not aplicable here)
        _ => dont_even_catch(),     // placed at the end, default action for all other values (not aplicable here)
        _ => (),                    // placed at the end, do nothing for all other values (not aplicable here)
    }
}

// the following is a shortcut for pattern matching below
let config_max = Some(3u8);
if let Some(max) = config_max {
    println!("The maximum is configured to be {}", max);
}
// the pattern matching version
let config_max = Some(3u8);
match config_max {
    Some(max) => println!("The maximum is configured to be {}", max),
    _ => (),
}



//==================== Traits
&dyn Any, &mut dyn Read     // Trait object, reference to any value that implements a given set of methods; e.g. 'value as &dyn Any' or '&mut file as &mut dyn Read'



//==================== Statements

//---------- Selection Statements

if COND {/*...*/}           // if statement; COND must evaluate to bool; COND does not have parenthesis
else if COND {/*...*/}      // else if statement
else {/*...*/}              // else branch

let num: i32 = if COND { 5 } else { 6 };    // can be used as an expression; both branches have to return the same type

//---------- Iteration Statements

// loop loop
loop {/*...*/}              // executes the loop indefinitelly untill break is called
'l_name: loop {/*...*/}     // as above but loop has a name 'l_name'

// keywords
break;                      // break out of the most inner loop
break 'l_name;              // break out of the 'l_name' loop
break EXPR;                 // as above but returns the result of the EXPR
continue;                   // skip the rest of the loop

// while loop
while COND {/*...*/}        // while loop

// for loop
for elem in arr {/*...*/}   // for loop; faster, does not do bounds checks when accessing the array element



//==================== Operators
// method calls have a higher precedence than unary prefix operators
+, -, *, /                  // arithmetic ops; over- and under-flows panick in the debug and wrap aroun in release mode


// Operator     Example                                                Explanation                                  Overloadable?
!               ident!(/*...*/), ident!{/*...*/}, ident![/*...*/]   // Macro expansion
!               !expr                                               // Bitwise or logical complement                Not
!=              expr != expr                                        // Nonequality comparison                       PartialEq
%               expr % expr                                         // Arithmetic remainder                         Rem
%=              var %= expr                                         // Arithmetic remainder and assignment          RemAssign
&               &expr, &mut expr                                    // Borrow
&               &type, &mut type                                    // Borrowed pointer type
                &'a type, &'a mut type                              // Borrowed pointer type
&               expr & expr                                         // Bitwise AND                                  BitAnd
&=              var &= expr                                         // Bitwise AND and assignment                   BitAndAssign
&&              expr && expr                                        // Short-circuiting logical AND
*               expr * expr                                         // Arithmetic multiplication                    Mul
*=              var *= expr                                         // Arithmetic multiplication and assignment     MulAssign
*               *expr                                               // Dereference                                  Deref
*               *const type, *mut type                              // Raw pointer
+               trait + trait, 'a + trait                           // Compound type constraint
+               expr + expr                                         // Arithmetic addition                          Add
+=              var += expr                                         // Arithmetic addition and assignment           AddAssign
,               expr, expr                                          // Argument and element separator
-               - expr                                              // Arithmetic negation                          Neg
-               expr - expr                                         // Arithmetic subtraction                       Sub
-=              var -= expr                                         // Arithmetic subtraction and assignment        SubAssign
->              fn(...) -> type, |...| -> type                      // Function and closure return type
.               expr.ident                                          // Member access
..              .., expr.., ..expr, expr..expr                      // Right-exclusive range literal                PartialOrd
..=             ..=expr, expr..=expr                                // Right-inclusive range literal                PartialOrd
..              ..expr                                              // Struct literal update syntax
..              variant(x, ..), struct_type { x, .. }               // “And the rest” pattern binding
...             expr...expr                                         // Deprecated, use ..= instead
/               expr / expr                                         // Arithmetic division                          Div
/=              var /= expr                                         // Arithmetic division and assignment           DivAssign
:               pat: type, ident: type                              // Constraints
:               ident: expr                                         // Struct field initializer
:               'a: loop {...}                                      // Loop label
;               expr;                                               // Statement and item terminator
;               [...; len]                                          // Part of fixed-size array syntax
<<              expr << expr                                        // Left-shift                                   Shl
<<=             var <<= expr                                        // Left-shift and assignment                    ShlAssign
<               expr < expr                                         // Less than comparison                         PartialOrd
<=              expr <= expr                                        // Less than or equal to comparison             PartialOrd
=               var = expr, ident = type                            // Assignment/equivalence
==              expr == expr                                        // Equality comparison                          PartialEq
=>              pat => expr                                         // Part of match arm syntax
>               expr > expr                                         // Greater than comparison                      PartialOrd
>=              expr >= expr                                        // Greater than or equal to comparison          PartialOrd
>>              expr >> expr                                        // Right-shift                                  Shr
>>=             var >>= expr                                        // Right-shift and assignment                   ShrAssign
@               ident @ pat                                         // Pattern binding
^               expr ^ expr                                         // Bitwise exclusive OR                         BitXor
^=              var ^= expr                                         // Bitwise exclusive OR and assignment          BitXorAssign
|               pat | pat                                           // Pattern alternatives
|               expr | expr                                         // Bitwise OR                                   BitOr
|=              var |= expr                                         // Bitwise OR and assignment                    BitOrAssign
||              expr || expr                                        // Short-circuiting logical OR
?               expr?                                               // Error propagation




//==================== Keywords

// raw identifiers
r#keyword   // let one use keywords as identifier.

// keywords currently in use:
as          // perform primitive casting, disambiguate the specific trait containing an item, or rename items in use statements
async       // return a Future instead of blocking the current thread
await       // suspend execution until the result of a Future is ready
break       // exit a loop immediately
const       // define constant items or constant raw pointers
continue    // continue to the next loop iteration
crate       // in a module path, refers to the crate root
dyn         // dynamic dispatch to a trait object
else        // fallback for if and if let control flow constructs
enum        // define an enumeration
extern      // link an external function or variable
false       // Boolean false literal
fn          // define a function or the function pointer type
for         // loop over items from an iterator, implement a trait, or specify a higher-ranked lifetime
if          // branch based on the result of a conditional expression
impl        // implement inherent or trait functionality
in          // part of for loop syntax
let         // bind a variable
loop        // loop unconditionally
match       // match a value to patterns
mod         // define a module
move        // make a closure take ownership of all its captures
mut         // denote mutability in references, raw pointers, or pattern bindings
pub         // denote public visibility in struct fields, impl blocks, or modules
ref         // bind by reference
return      // return from function
Self        // a type alias for the type we are defining or implementing
self        // method subject or current module
static      // global variable or lifetime lasting the entire program execution
struct      // define a structure
super       // parent module of the current module
trait       // define a trait
true        // Boolean true literal
type        // define a type alias or associated type
union       // define a union; is only a keyword when used in a union declaration
unsafe      // denote unsafe code, functions, traits, or implementations
use         // bring symbols into scope
where       // denote clauses that constrain a type
while       // loop conditionally based on the result of an expression

// reserved keywords:
abstract    //
become      //
box         //
do          //
final       //
macro       //
override    //
priv        //
try         //
typeof      //
unsized     //
virtual     //
yield       //
