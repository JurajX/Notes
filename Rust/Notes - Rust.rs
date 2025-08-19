//==================== ==================== ToC
// - Declarations
// - Expressions and Statements
// - Type Aliases
// - Integer
// - Floats
// - Boolean
// - Character
// - Tuple
// - References
// - Box and Reference Counts
// - Raw Pointers
// - Ranges
// - Iterators
// - Arrays, Slices
// - Vectors
// - String Types
// - HashMap
// - Entry
// - Macros
// - Functions
// - Ownership
// - Structs
// - Enums
// - Result
// - Generics (Templates)
// - Traits
// - Option
// - Statements
// - Lifetimes
// - Tests
// - Packages & Crates
// - Operators
// - Keywords



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
4 + 5;              // is astatement; does not return a value
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
i8, i16, i32, i64, i128     // 8-bit, 16-bit, 32-bit, 64-bit, 128-bit
u8, u16, u32, u64, u128     // 8-bit, 16-bit, 32-bit, 64-bit, 128-bit
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

//--- special byte literals
b'\''       // Single quote     39u8
b'\\'       // Backslash        92u8
b'\n'       // Newline          10u8
b'\r'       // Carriage return  13u8
b'\t'       // Tab               9u8

//---------- declarations
let int: u32 = 0xff;        // int is 15
let mut int: u8 = 0xff;     // int is mutable and equal to 15

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
let ch: char = 'A';         // cha is a 32-bit long character holding letter A
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



//==================== References
// non-owning pointers that must not outlive their referent
//---------- types
&T;                         // a reference to type T; allows for multiple readers
&mut T;                     // a mutable references; prohibits having any other way accessing the value (single writer)

//---------- declarations
let r: &T = &x;             // r stores a reference to the variable x
let mut r: &T = &x;         // as above, but r is mutable (i.e. can be reassigned)
let r: &mut T = &mut x;     // r stores a mutable reference to the variable x
let mut r: &mut T = &mut x; // r is mutable and stores a mutable reference to the variable x
let rr: &&T = &r;           // rr stores a reference to a reference to variable x; can be chained undefinitely
*r;                         // dereferencing a reference
r.member;                   // the dot operator automatically dereferences the reference; i.e. (*r).member
r1 == r2; rr1 == rr2;       // both compare values (as many dereferences as needed are applied); to compare addresses use std::ptr::eq
r1 == rr1;                  // this is not allowed



//==================== Box and Reference Counts
//---------- types
Box<T>                      // a smart pointer owning pointer to value on the heap (unique_ptr)
std::rc::Arc<T>;            // atomic reference count, used for thread-safe code
std::rc::Rc<T>;             // reference count, used for non-thread-safe code (shared_ptr)
std::rc::Weak<T>;           // weak pointer; (weak_ptr)

//---------- declarations
let t = (12, "eggs");       // defines a tuple
let b = Box::new(t);        // allocates a tuple on the heap

let s: Rc<String> = Rc::new("str".to_string()); // creates a string rc pointer; read-only; behaves like a variable
let t: Rc<String> = s.clone();                  // increases a reference count



//==================== Raw Pointers
// can be dereferenced only within an 'unsafe' block
*mut T, *const T;           // mutable or constant raw pointer; works as in c++



//==================== Ranges
let r: Range<i32> = 1..5;          // range from 1 to 4 (not including 5)



//==================== Iterators
let mut cont: T1<T2> = /* ... */;           // defines a container type T1 with elements of type T2
let mut iter: Iter<'_, T2 > = cont.iter();  // creates an iterator over the vector
iter.next();                                // returns Option<&T2>, and advances the iterator



//==================== Arrays, Slices
//---------- types
[T; N];                                       // type denoting a const size array of length N with values of type T
&[T], &mut [T];                               // (mutable) slice of a sequence container (vector, array, string, etc.)

//---------- declarations
let arr: [i32; 2] = [1, 2];                   // declaration of an array holding [1, 2]
let arr: [i32; 2] = [5; 2];                   // declaration of an array holding [5, 5]
let arr_slice: &[i32] = &arr;                 // creates a slice containing the whole array
let arr_slice: &[i32] = &arr[1..];            // creates a slice starting at 1-st element
let arr_slice: &[i32] = &arr[1..4];           // 1-st element end ending at 4-th element (not included)

//---------- indexing
arr[i];             // i-th element of arr; i must be 'usize' and in [ 0, arr.len() - 1 ]
&arr[i];            // reference to i-th element of arr; i must be 'usize' and in [ 0, arr.len() - 1 ]

vec.get(0)          // returns an Option<&T> for the first element of v



//==================== Vectors
Vec<T>;                                       // dynamically allocated sequence with values of type T
let vec: Vec = Vec::<i32>::new();             // creates an empty vector of type i32
               Vec::<i32>::with_capacity(N);  // use to allocate capacity at creation
let vec: Vec<i32> = (1..4).collect();         // creates a vector containing [1, 2, 3]
let vec: Vec<i32> = vec![1, 2];               // creates a vector containing [1, 2]
let vec: Vec<i32> = vec![5; 2];               // creates a vector containing [5, 5]
let vec_slice: &[i32] = &vec;                 // creates a slice containing the whole vector

//---------- indexing
// same as in arrays

//---------- modification
vec.push(4);        // adds an element to the end of the vector
vec.pop();          // removes the last element of the vector; returns Option<T>

//---------- iterators
vec.iter()          // returns an iterator; does imutable borrow



//==================== String Types
// stored in memory as UTF-8 with variable-width encoding

//---------- types
String;                     // dyn. sized heap string (i.e. Vec<u8> guaranteed to hold well-formed UTF-8 chars)
&str;                       // ref. to a UTF-8 (i.e. &[u8] guaranteed as above); can be ref to a string literal living in read-only memory
&mut str;                   // exists but can't modify the strings; only make_ascii_uppercase and make_ascii_lowercase are allowed

//---------- declarations
let s = String::new();      // creates an empty String
let s = String::from("hi"); // creates a String
let s = "hi".to_string();   // converts &str to String; available for all types implementing Display trait

let s = "Hi, world!";       // defines a &'static str (string literal saved in read-only memory with the code)
let s:&str = "Hi, world!";  // similar as above
let s: &[u8; 3] = b"GET";   // byte string; use br"text" for raw byte strings

//---------- indexing
s1[0];                      // does not work
s1.chars()                  // returns an iterator over the characters
s1.bytes()                  // returns an iterator over the bytes (u8)
                            // grapheme clusters from strings is complex; use crate with this functionality

//---------- modification
let mut s1 = String::from("Hello"); // creates a mutable string
s1.push_str(" world");              // appends a string slice to the end of the string
s1.push('!');                       // appends a single character to the end of the string
s1.remove(0);                       // removes the character at the specified position
s1.insert(0, 'H');                  // inserts a character at the beginning of the string
s1.insert_str(5, " beautiful");     // inserts a string slice at the specified position
let s2 = String::from("Meow.");
let s3 = s1 + &s2;                  // s1 moved, s2 borrowed; uses deref coercion and fn add(self, s: &str) -> String


//---------- other moethods
s1.split_whitespace();              // returns an iterator over the subslices separated by whitespace

//---------- ways to create string
"\"Ouch!\" he said.\n";     // classic escaping of characters
"line 1,
    line 2 with spaces";    // new line character and leading white spaces are included
"line 1\
    still line 1"           // new line character and leading white spaces are dropped
r"raw string";              // everything inside is included verbatim; r##"alternative with # signs"##



//==================== HashMap
use std::collections::HashMap;                  // uses of SipHash, denial-of-service (DoS)

let mut hm: HashMap<K, V> = HashMap::new();     // K and V could be references, but then the variables must outlive the map

//---------- modification
hm.insert(k1, v1);          // k1, v1 are moved unless they implement Copy trait; returns Option<V> Some(old_value)
hm.get(k1);                 // returns Option<&V>; returns None if k1 is not found
hm.entry(k1);               // returns Entry<K, V>; allows to modify the value if it exists or insert a new one


//---------- iterating
for (key, value) in &hm;    // iterates over the k-v pairs



//==================== Entry
let e = hm.entry(k1);       // Entry<K, V> where K and V are from the HashMap
e.or_insert(v1);            // inserts v1 if k1 not found; returns a mutable reference to hm[k1];



//==================== Macros

println!("Hello, world!");      // prints to the standard output
let s = format!("{s1}-{s2}");   // creates a formatted string



//==================== Functions
// the convention are snake-case function names
// must be defined somewhere in a scope that can be seen by the caller (not necesarily before the call)
fn fct() {/*...*/}                          // a function with no return
fn fct(x:i32, y:f32) {/*...*/}              // a function with parameters i32 and f32 (types are mandatory); and no return
fn fct(x:i32) -> i32 {                      // a function with a parameter i32 returning i32
    x + 1                                   // implicit return statement; can be replaced by 'return x + 1;'
}

//---------- pointers and lambdas
fn(&str) -> bool            // pointer to function taking a string and returning a boolean, e.g. 'str::is_empty'
                            // closure, e.g. '|a, b| { a*a + b*b }'



//==================== Ownership

//---------- Ownership and Functions
fn fct(s: String) {/*...*/};        // a fn taking a string
let s1 = String::from("hello");     // creates a string
let s2 = s1;                        // moves s1 into s2; s1 cannot be used after this point
fct(s2);                            // moves s2 into the fct; s2 cannot be used after this point

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
let r3 = &mut s; // BIG PROBLEM
let r4 = &mut s; // BIG PROBLEM

// Reference's scope lasts untill its last ussage (Non-Lexical Lifetime)
let r1 = &s;                        // no problem
let r2 = &s;                        // no problem
println!("{} and {}", r1, r2);      // variables r1 and r2 will not be used after this point
let r3 = &mut s;                    // no problem
println!("{}", r3);



//==================== Structs
struct Rectangle {                  // struct definition; no support for partialy mutable fields (either the whole thing is mut or not)
    width: u32,                     // width field and its type
    height: u32,                    // height field and its type
}

impl Rectangle {                    // implementation block for associated functions; multiple impl blocks are allowed
    fn area(&self) -> u32 {         // member functions are statically dispatched by default, and exist as free-standing functions
        self.width * self.height    // returns the expression (no semicolon); equivalent to return ...;
    }
    fn square(size: u32) -> Self {  // 'constructor' for a square rectangle; Self is alias for Rectangle
        Self {
            width: size, height: size,
        }
    }
}

let st1 = Rectangle {               // instantiation of a struct; fields can be instantiated in any order
    width: 1,                       // assigning to the width
    height: 1,                      // assigning to the height
};
st1.width;                          // accessing the width

let st2 = Rectangle {               // another instance of struct
    width: 10,                      // assigning to the width
    ..st1                           // move the remaining fields from st1; this moves/copies movable/copyable traits from st1
};                                  // ... if anything is moved from st1, it is no longer usable

fn build_rect(width: u32, height: u32) -> Rectangle {   // function returning a Rectangle
    Rectangle { width, height }                         // shorthand for 'Rectangle { width: width, height: height }'
}

let sq = Rectangle::square(3);      // using the 'constructor'

#[derive(Debug)]                    // kinda decorator; helps with printing the struct with println!()
struct Another {/*...*/}            // just definition

//---------- Tuple Structs
struct Color(i32, i32, i32);        // define a tuple struct; i.e. a named tuple

struct Point(i32, i32, i32);        // is different type from the above
let origin = Point(0, 0, 0);
let Point(x, y, z) = origin;        // destructuring the tuple struct; as oposed to tuples: let(x, y, z) = tup1

//---------- Unit-Like Structs
struct AlwaysEqual;                 // does not have any field; has zero size;
struct Success;                     // (Failure) can be used as a marker and variants

struct Logger;                      // can be used to implement a stateless utils
impl Logger {
    fn log(&self, message: &str) {/* */}
}



//==================== Enums
enum Attend {               // enumeration
    OnTime,                 // elements can be empty
    Late(u32)               // ... or hold a value
};

impl Attend {                           // enums can have methods, rest is as in structs
    fn is_late(&self) -> bool {
        match self {
            Attend::OnTime => false,
            Attend::Late(_) => true,
        }
    }
}



//==================== Generics (Templates)
fn fun<T>(param: T) -> T { /* ... */}   // template function

struct Point<T> { x: T, y: T }          // template struct
impl<T> Poinit<T> {                     // impl needs <T> too; could be different letter (tho everywhere)
    fn x(&self) -> &T { &self.x }
    fn mix<U, V> (&self, other: Point<U>) -> V { /* ... */ }  // method with multiple template parameters
}
impl Point<f32> {
    fn fun(&self) -> f32 { /* ... */ }  // method only for f32; can't be templated if there is a concrete impl
}

struct Point<T, U> { x: T, y: U }       // template struct, with different types



//==================== Traits
// one can implement trait on a type iff either the trait or the type is defined in the current crate
pub trait TraitName{
    fn method1(&self) -> i32 { /* ... */}   // method with self as a parameter and default implementation
    fn method2(&self) -> f32 { /* ... */}   // method with self as a parameter and default implementation
    fn method3(&self, param: i32);          // method with self and a parameter
}

pub struct StructName { /* ... */ }             // a struct defiinition
impl TraitName for StructName {                 // implementation of TraitName for StructName
                                                // method1 uses the default impl
    fn method2(&self) -> f32 { /* ... */ }      // method2 overwrites the default impl
    fn method3(&self, param: i32) { /* ... */ } // implementation of method3 (mandatory)
}

//---------- ussage
pub fn fct1<T: TraitName>(item: &T) {           // fn that takes any type that implements TraitName, kinda polymorphism
    item.method1();                             // call to method1 from TraitName
}
pub fn fct(item: & impl TraitName) {/* ... */}  // syntax sugar for the above

//---------- conditional impl of methods
impl<T: Trait1> Trait2 for T {/* ... */}    // implements Trait2 for all Ts that implement Trait1

struct MyStruct<T> {/* ... */}          // generic struct with a type parameter T
impl<T: TraitName> MyStruct<T> {        // conditional impl for MyStruct<T> where T implements TraitName
    fn sth(&self) { /* ... */ }         // this is available only if T implements TraitName
}

//---------- details
pub fn fct1(item1: &impl TraitName, item2: &impl TraitName) {}  // item1 and item2 can be different types
pub fn fct1<T: TraitName>(item1: &T, item2: &T) {}              // both must be the same type

pub fn fct1<T: Summary + Display>(item: &T) {}          // item must impl both
pub fn fct1(item: &(impl Summary + Display)) {}         // as above

fn fct2() -> impl TraitName {}                          // returns type that implements TraitName

//---------- generics
fn fct1<T: Display + Clone, U: Clone + Debug>(t: &T, u: &U) -> i32 {}   // complicated
fn fct1<T, U>(t: &T, u: &U) -> i32                                      // as above
where                                                                   // details are in the where block
    T: Display + Clone,
    U: Clone + Debug,
{}

// ---------- trait objects
&dyn Any, &mut dyn Read     // Trait object, reference to any value that implements a given set of methods; e.g. 'value as &dyn Any' or '&mut file as &mut dyn Read'



//==================== Option
//---------- types
pub enum Option<T> { None, Some(T) }    // definitioon

Option<T>               // option enum, either None or Some(value); e.g. 'None' or 'Some("Dr.")'
                        // ... has a lot of member functions, e.g. is_none, is_some, etc.

opt.unwrap();           // returns the value if Some, panics if None
opt.copied();           // fn copied (Option<&T>) -> Option<T>; copies the value if Some, returns None if None
opt.unwrap_or();        // returns the value if Some, or the default value if None; eagerly evaluated



//==================== Result
pub enum Result<T, E> { Ok(T), Err(E) }   // definition

Result<T, E>            // result of op. that may fail, either Ok(value) or Err(e); e.g. 'Ok(123)' or 'Err(Error::last_os_error())'

let x = match res {                 // a way to handle Result
    Ok(val) => val,                 // if res is Ok, returns the value
    Err(e) => panic!("Error: {e}"), // if res is Err, panics with the error message
};

res.unwrap();           // returns the value if Ok, panics if Err
res.expect("message");  // returns the value if Ok, panics with the message if Err

let val = res?;         // if OK(val) assigns val, else early fn return of Err.
                        // only in fns returning Result<T, E>, Option<T> or types that implement FromResidual

fn read_username_from_file() -> Result<String, io::Error> {
    let mut username_file = File::open("hello.txt")?;
    let mut username = String::new();
    username_file.read_to_string(&mut username)?;
    Ok(username)
}



//==================== Statements
//---------- Selection Statements
if COND {/*...*/}           // if statement; COND must evaluate to bool; COND does not have parenthesis
else if COND {/*...*/}      // else if statement
else {/*...*/}              // else branch

let num: i32 = if COND { 5 } else { 6 };    // can be used as an expression; both branches have to return the same type

match expr {                        // match statement; all options have to be covered
    PATTERN1 => EXPR1,              // only the first matching pattern is executed
    PATTERN2 => {Multi_line_EXPR2}, // {} are mandatory if the expresion is multi-line
    _ => EXPR3,                     // default case, _ catches all options and ignores them, returns EXPR3
    var => EXPR4(var),              // as above, but does not ignored the caught value
    _ => (),                        // as above, but does nothing
}

let var = Some(3u8);
if let Some(n) = var {              // if let statement; only matches the Some(n) pattern
    println!("The value is {n}.");
} else {/* */}                      // else branch is optional

let var = None;
let Some(n) = var else {            // let else statement; like above but matches the else part
    println!("No value found.");
}

//---------- Iteration Statements
// loop loop
loop {/*...*/}              // executes the loop indefinitelly untill break is called
'l_name: loop {/*...*/}     // as above but loop has a name 'l_name'

// keywords
break;                      // break out of the most inner loop
break EXPR;                 // as above but returns the result of the EXPR
break 'l_name;              // break out of the 'l_name' loop
break 'l_name EXPR;         // break out of the 'l_name' loop and returns the result of the EXPR
continue;                   // skip the rest of the loop

// while loop
while COND {/*...*/}        // while loop

// for loop
for elem in arr {/*...*/}   // for loop; faster, does not do bounds checks when accessing the array element


//==================== Lifetimes
//---------- elision rules
// 1. A different lifetime parameter is assigned to each input ref. parameter
// 2. If there is exactly one input ref. parameter, all output lifetimes are assigned that input lifetime
// 3. If one of the input ref. params is &self or &mut self (i.e. it's a method) all output lifetimes are assigned the lifetime of &self.

//---------- lifetime annotations
&i32        // a reference
&'a i32     // a reference with an explicit lifetime
&'a mut i32 // a mutable reference with an explicit lifetime

//---------- lifetime in functions
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() { x } else { y }
}

//---------- lifetime in structs
struct Excerpt<'a> {    // this means that the excerpt cannot outlive the lifetime 'a
    part: &'a str,
}
impl<'a> Excerpt<'a> {
    fn level(&self) -> i32 {
        3
    }
}

//---------- static lifetime
let s: &'static str = "I live forever!";    // all string literals have static lifetime



//==================== Tests
pub fn add(a: i32, b: i32) -> i32 {/* ... */}   // fn to test

#[cfg(test)]
mod tests {
    use usper::*;                   // make everything from outsice available

    #[test]                         // indicates that next fn is a test
    fn test_add() {
        assert_eq!(add(2, 3), 5);
    }
    #[test]
    fn test_add2() -> Result<(), String> {          // test returns Result, allows to use ? operator
        if add(2, 2) == 4 {
            return OK(());                          // when test passes
        } else {
            return Err(String::from("err msg"));    // when test fails
        }
    }

    #[test]
    #[should_panic]                 // marks the test as panicking
    fn should_panic() { /* ... */}  // passes if the function panics

}

//---------- other test (module) annotations
#[cfg(opt)]                             // includes the annotated module only when configuration option opt is given
#[cfg(test)]                            // skips compiling tests except when cargo test is run
#[test]                                 // a test fn
#[ignore]                               // annotates a test that is ignored by default
#[should_panic]                         // a panicking fn
#[should_panic(expected = "substr")]    // as above + panick msg contains expected

//---------- other test macros
assert!(bool_var);
assert!(bool_var, "Failure msg {}.", 4);    // prints "Failure msg 4." when fail
assert_eq!(left, rigth);
assert_ne!(left, rigth);

//---------- unit tests
// live directly beside the code in tests module
// allow to test private functions

//---------- integration tests
// integration tests live in the <root>/tests/ directory
// each file in the tests dir is compiled into a separate crate, folders of tests folder are not considered
// common set-up fns can be placed in <root>/tests/common/mod.rs (the old convention)


//==================== Packages & Crates

// path         - an item, such as a struct, function, or module; call from:
//   <crate_name>::<module>::<submodule>::<item>;   - another crate
//   crate::<module>::<submodule>::<item>;          - from the same crate absolute path
//   <submodule>::<item>;                           - relative path from the current module
//   super::<submodule>::<item>;                    - relative path from the parent module
// (pub) use crate::<module>::<submodule>;          - allows <submodule>::<item>; can be combined with pub for re-exporting
// (pub) use crate::<module>::<submodule> as smod;  - allows smod::<item>; can be combined with pub for re-exporting
// (pub) use std::{cmp::Ordering, io};              - equivalent to use std::cmp::Ordering; use std::io;
// (pub) use std::io::{self, Write};                - equivalent to use std::io; use std::io::Write;
// (pub) use std::collections::*;                   - brings all public items from std::collections into scope

// module       - the organization, scope, and privacy of paths

// crates       - a tree of modules that produces a library or executable
//   binary     - a crate that produces an executable
//   library    - a crate that produces a library
//   crate root - the source file that the compiler starts from

// packages     - a bundle of one or more crates; can contain at most one library crate but multiple binary crates
//   src/main.rs- crate root for a binary crate with the same name as the project
//   src/lib.rs - crate root for a library crate with the same name as the project
//   src/bin    - directory containing additional binary crates

// crate root                   - can define modules
//   mod mod_name{/* */}        - inline definition
//   mod mod_name;              - searches first src/mod_name.rs, then src/mod_name/mod.rs

// other than the crate root    - can define submodule
//   mod submod_name{/* */}     - inline definition
//   mod submod_name;           - searches first src/mod_name/submod_name.rs, then src/mod_name/submod_name/mod.rs

// private vs. public           - items and modules are private by default; use pub to make them public (i.e. visible outside the module)
//                              - items in pub mod are private by default (i.e. visible only inside the module)



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