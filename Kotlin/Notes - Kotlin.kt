// ========== ToC ==========
// CORE LANGUAGE
//   Packages
//   Comments
//   Main Function
//   Variable Declaration
//   Types
//   Arrays
//   Strings
//   Operators
//   If Statement
//   When Statement
//   Loops
//   Returns and Jumps
//   Functions
//   Classes
//   Main
//
// MODULES
//   Miscelaneous
//   Collections
//   Ranges and Progressions
//   Sequences
//   Collection Operations

// TODO
//   I/O
//   Files
//   Exceptions



// ========== Packages ==========
package pkg.name                // package declaration; if not specified the file content belongs to the default package that has no name.
fun prt() {/*...*/}             // full name of the fct is pkg.name.printMessage() because of the package declaration

import pkg.name.prt             // makes printMessage accessible without pkg.name. prefix
import pkg.name.*               // makes everything in pkg.name accessible
import pkg.name.prt as print    // locally renames prt as print

// default imports, imported to every Kotlin file
kotlin.*
kotlin.annotation.*
kotlin.collections.*
kotlin.comparisons.*
kotlin.io.*
kotlin.ranges.*
kotlin.sequences.*
kotlin.text.*
// additional imports depending on target platform
java.lang.*                     // JVM
kotlin.jvm.*                    // JVM
kotlin.js.*                     // JS



// ========== Comments ==========
// single line comment
/* block comment, can also occupy multiple lines */



// ========== Main Function ==========
fun main(args: Array<String>) {
    println("Hello, World!")
}



// ========== Variable Declaration ==========
val readOnly: TYPE = VALUE      // read only variable declaration
var mutable: TYPE = VALUE       // mutable variable declaration



// ========== Types ==========
Any                             // infers the type automatically

Byte, Short, Int, Long  3       // 8, 16, 32, 64 bit; [-2^n , 2^n  - 1] where n = bit size - 1
Float   3.1f, 3.1F              // 32 bit
Double  3.14, 3.14e5            // 64 bit
    .toByte(), ..., .toDouble   // supported by all number types,
    .toChar(), .toString()      // toChar() uses ASCII, toString() as expected

Char    'a'                     // characters
    '\n', '\t', '\\', '\''      // special characters: new line, tab, backslash, quote
    '\u0A09'                    // unicode characters
String  "a"                     // string
Boolean true, false             // booleans



// ========== Arrays ==========
var a: Array<TYPE> = ...        // creates an array of the type TYPE, use 'Any' for mixed elements
    arrayOf(0, 'a', "b")        // returns an array [0, 'a', "b"] (i.e. Array<Any>);
    arrayOfNulls<TYPE>(N)       // returns an array of size N and with null elements of the type TYPE
    Array(N){FN}                // returns an array of size N with elements FN(i) with i in 1..N

// primitive type arrays, same set of methods and properties as Array class but no inheritance; i.e. no boxing overhead
ByteArray, byteArrayOf()
ShortArray, shortArrayOf()
IntArray, intArrayOf()

arr[N]                          // setter and getter method for the N-th element of the array arr
*arr                            // spread operator, it unpacks the array; used in functions with arbitrary number of arguments



// ========== Strings ==========
var str: String = "string"      // declares a string; strings are immutable
"escaped string"                // escaped strings may contain escaped characters
"""raw "s-s-s" string"""        // raw strings can contain newlines and arbitrary text; doesn't support backslash escaping
str[i]                          // returns i-th char
str1 + str2                     // concatenation of strings
str + 123                       // concatenation works with other types too...

    .trimMargin(">")            // removes leading white spaces of each line before ">" (incl ">"); default="|"; e.g. "   >txt" -> "txt"
    .length                     // returns length of string

"text ${EXPR}"                  // concatenates "text " and result of EXPR expression
"text $var"                     // concatenates "text " and variable content



// ========== Operators ==========
+ - * / %                       // addition, subtraction, multiplication, division, modulo on numbers

shl, shr, ushr                  // signed shift left, right, unsigned shift right; e.g. 1 shl 2 (is equal to 4)
and, or, xor, inv()             // bitvise and, or, xor, bitwise inversion

==, !=, <, >, <=, >=,           // logical comparisons

a..b, x in a..b, x !in a..b     // range from a to b; x is in range a..b; x not in range a..b

||, &&, !                       // or, and, negation for booleans (true, false)



// ========== If Statement ==========
if (COND) BODY                  // traditional ussage
if (COND) {BODY} else {BODY}    // with else part
...= if (COND) a else b         // as expression; if COND assign a else assign b to the lhs; this ussage always has to have else part
...= if (COND) {...} else {...} // a and b can be blocks, i.e. {...} where the result of the last expression in the block is assigned



// ========== When Statement ==========
when (x) {                      // this is switch-case operator of C-like languages; can be used as expression as well (similar to if ussage)
    1    -> print("x == 1")     // if x == 1
    2, 3 -> print("x == 2or3")  // if x == 2 or x == 3
    EXPR -> print("something")  // arbitrary expressions can be used, .e.g 'in 4..5' or '!in 4..5' etc.
    else -> print("different")  // if x is none of the above
}

when (var x = fct()) {BODY}     // one can also capture the subject from fct()

when {                          // can be used as if-else-if-... chain when no argument is supplied
    COND1 -> EXPR1
    COND2 -> EXPR2
}



// ========== Loops ==========
for (item in ITERABLE) {...}    // for loop iterates over anything that provides iterator(), next(), and hasNext()
for (item: Int in ints) {...}   // another way
for (i in 1..10) {...}          // over ranges

for (i in arr.indices) {...}    // array or list with an index
for ((i, v) in arr.withIndex()) // as above, just gets both index i and value v

while (COND) {BODY}             // usual while loop
do {BODY} while (COND)          // usual do-while loop



// ========== Returns and Jumps ==========
return                          // returns from the nearest enclosing function or anonymous function; can be used with labels
break                           // breaks out of the nearest enclosing loop; can be used with labels
continue                        // proceeds to the next step of the nearest enclosing loop; can be used with labels

myLbl@ for (...){               // a label can be used to indicate which loop should be broken out of
    for (...){                  // break would normally break this loop
        if (...) break@lbl}}



// ========== Functions ==========
fun fct(x: TYPE1): TYPE2 {BODY}     // function declaration (always explicitely typed); takes argument of TYPE1 and returns TYPE2;
return Unit                         // return value for 'void' functions; it may be omitted, also in the declaration
fct(x)                              // function call

// Default Arguments
fun fct(x: TYPE, y: TYPE =0)...{}   // default value for an argument;
fct(a, b), fct(a)                   // calls fct(x=a, y=b), fct(x=a, y=0)
fun fct(x: TYPE =0, y: TYPE)...{}   // default value argument preceeds non-default value argument
fct(a, b), fct(y=b)                 // calls fct(x=a, y=b), fct(x=0, y=b)
fun fct(vararg x: TYPE)...{}        // variable number of arguments; x is visible as Array<TYPE> in the BODY

// Generic, Local, Tail-Recursive and Single-expression Functions
fun <T> fct(x: T): Array<T> {BODY}  // generic (template) function declaration
fun fn1(...) {fun fn2() {BODY} }    // local functions allowed, i.e. functions inside functions
tailrec fun fn(...): TYPE {BODY}    // tail recursive function declaration; the function must call itself as the last operation in the BODY
fun fct(x: TYPE): TYPE = 2 * x      // single-expression function; type can be inferred automatically, i.e. fun fct(x: Int) = 2 * x

// Lambda Functions
{PARAM: TYPE -> EXPR}               // simple lambda function; multiple parameters, multi-line expressions possible, last expression is the return
{PARAM -> EXPR}                     // parameter type is optional if it can be inferred
val fct: (TYPE, TYPE) -> TYPE = {   // full syntactic form of lambda expression
    x: TYPE, y: TYPE -> EXPR}

// Trailing Lambdas
fun fn(fct: (...) -> ...): ... {}   // declaration of a function taking function as an argument
fn(LAMBDA)                          // fn called normally
fn() {LAMBDA}                       // fn called with trailing lambda
fn {LAMBDA}                         // as above, the parentheses can be omitted if lambda is the only argument

// Anonymous Functions
fun(x: TYPE1): TYPE2 {BODY}         // anonymous function, similar to lambda but let's you specify the return type
fun(x): TYPE2 {BODY}                // parameter type can be omitted

// Callable reference to existing declaration can be passed as an argument
Double::toString
List<Int>::size

// Infix Functions
infix fun CLS.fn(x: CLS): CLS {}    // infix function, can have only one argument
x fn y                              // calling infix function on instances of CLS x and y; e.g. and operator on Boolean
x.fn(y)                             // equivalen to the above

// Inline Functions - too complicated



// ========== Classes ==========
// Primary Constructor
class Person constructor(name: String, age: Int) {      // class declaration with primary constructor
class Person(name: String, age: Int) {                  // 'constructor' can be omitted if it has no annotations or visibility modifiers
    val name: String = name                             // property initialiser                 executed as a part of
    var age: Int = age                                  // property initialiser                 the constructor in order
    init {INIT_BLOCK}                                   // initialiser block                    it is stated here in the body
}
class Person (val name: String, var age: Int) {         // class declaration as above
    init {INIT_BLOCK}                                   // initialiser block
}

// Secondary Constructor
class Person {                                                      // class declaration with only secondary constructor
    init {INIT_BLOCK}                                               // initialiser block, executed before secondary constructor is
    var children: MutableList<Person> = mutableListOf<Person>()
    constructor(parent: Person) { parent.children.add(this) }       // secondary constructor
}
class Person (val name: String, var age: Int) {                             // class declaration with primary and secondary constructor
    init {INIT_BLOCK}                                                       // initialiser block, executed as a part of primary constructor
    var children: MutableList<Person> = mutableListOf<Person>()
    constructor(name:String, age: Int, parent: Person): this(name, age) {   // secondary constructor must deledate to primary one
        parent.children.add(this)                                           // secondary constructor body executed after delegation finished
    }
}

var mama: Person = Person("mama", 38)                   // creating instance of a class using primary constructor
var son: Person = Person("son", 18, mama)               // creating instance of a class using secondary constructor

// Inheritance
Any                                         // a common superclass for classes, it has three methods: equals(), hashCode(), toString()
class NonBase {                             // a final class, can't be inherited by another class
}
open class Base(a: Int) {                   // open keyword makes class inheritable
    constructor(a: Int, b: Int): this(a)    // secondary constructor
}
class Deriv1(a: Int): Base(a) {             // class derived from base with primary constructor
}
class Deriv2: Base {                        // derived class without primary constructor can call
    constructor(a: Int): super(a)           // primary constructor of the base or
    constructor(a: Int, b: Int) super(a, b) // secondary constructor of the base
}

// Overriding Methods
open class Spape {                          // inheritable class
    open fun draw() {}                      // open signifies that the method can be overriden
    open fun foo(i: Int = 10) {}            // method with default parameter
}
class Circle: Shape() {
    override fun draw() {}                  // overrides the function draw, and makes draw open (in case Circle would be open)
    override fun foo(i: Int) {}             // no default value allowed when overriding a method with default arguments
}
open class Square: Shape() {
    final override fun draw() {}            // overrides the function draw, and makes it final (i.e. can't be overriden in subsequent subclasses)
}

// Overriding Properties
open class Shape {
    open val vertexCount: Int = 0                               // open to be overriden
}
class Rectangle: Shape() {
    override val vertexCount = 4                                // overrides vertexCount to 4 (still constant)
}
class Triangle(override val vertexCount: Int = 3): Shape() {    // another way to override
}
class Polygon: Shape {
    override var vertexCount: Int = 0                           // overriding constant to variable, opposit direction not possible
}

// Properties
var name: TYPE = INITIALISER        // initialiser is optional, property type is optional if it can be inferred from the initializer
    get() = GETTER_METHOD           // getter is optional
    set(value) = SETTER_METHOD      // setter is optional, convention name for the set parameter is 'value'

val name: TYPE = INITIALISER        // as for mutable, except that it has to be initialised in the constructor
    get() = GETTER_METHOD           // getter is optional, setter is not allowed

const val name: TYPE                // denotes compile time constant

// Interface
interface Name {                    // declaration of an interface, it can't store state; can be base for a class
    val PROP: TYPE                  // abstract property, can't be assigned or referenced
    fun fn () {}                    // member function
}

// Visibility Modifiers
// modifiers for classes, objects, interfaces, constructors, functions, properties and setters, getters have the same modifier as properties
// default modifier is public
// in packages, for functions, properties, classes, objects and intervaces
public                  // means visible everywhere
internal                // means visible everywhere in the same module
protected               // means not visible for top-level declarations
private                 // means visible inside the file containing the declarations
// in classes, for members
public                  // means visible for everyone                   who sees the declaring class
internal                // means visible for everyone inside the module who sees the declaring class
protected               // means visible inside the class and subclasses
private                 // means visible inside the class only

// Extension Functions
fun CLS.fct(x:TYPE) {}  // creates extension function for a class (possibly 3rd party class you can't modify)
// Extension Properties
val CLS.prop: TYPE      // declares extension property; initializers are not allowed, i.e. val CLS.prop: TYPE = VALUE is not possible
    get() = EXPR        // behaviour is defined by providing getters and setters


// Data Classes
// equals(), hashCode(), toString(), nomponentN() functions, copy() are automatically derived for properties defined in the primary constructor
data class User(val name: String, var age: Int) {   // declares a data class used to hold data
    var bDay: String = "0"                          // is omitted from equals(), hashCode(), toString(), nomponentN() functions, copy()
}

// Sealed Classes
// use the sealed modifier; sort of like enum class but subclass of a sealed class can have multiple instances which can contain state

// Generics
class Box<T>(t: T){                         // classes can have type parameter, i.e. being templates
    var v = T
}
val box: Box<Int> = Box(1)                  // instance of a template class
val box = Box(1)                            // type can be inferred

interface Source<out T> {                   // class declaration with a variance annotation - out modifier
    fun nextT(): T {}                       // the members of Source can only return (produce) T, not consume
}
interface Comparable<in T> {                // class declaration with a variance annotation - in modifier
    operator fun cmprTo(other: T): Int {}   // the members of Comparable can only consume T, not return
}

// Nested and Inner Classes
// inner class is a nested class (class inside a class) that can access the members of its outer class; it also carry a reference to an object of an outer class

// Enum Classes
enum class Direction {                      // declaration of an enum class
    NORTH, SOUTH, WEST, EAST                // the possible values of the Direction enum class
}
Direction.NORTH.ordinal                     // returns 0; every enum const has name and ordinal members

// Object Expressions and Declarations
val obj = object : MouseAdapter() {                         // create an anonymous object inheriting from MouseAdapter class and overriding
    override fun mouseClicked(e: MouseEvent) { /*...*/ }    // mouseClicked and
    override fun mouseEntered(e: MouseEvent) { /*...*/ }    // mouseEntered member functions
}

object DataProviderManager {                                // declares a singleton object, initialization is thread-safe and done at first access
    fun registerDataProvider(
        provider: DataProvider) {/*...*/}
    val allDataProviders: Collection<DataProvider>
        get() = myGet()
}
DataProviderManager.registerDataProvider(provider)          // use the objects name directly to refer to it
// an object declaration inside a class can be marked with the companion keyword



// ========== Main ==========

fun main() {
    println("Hello, World!")
}




// ####################### MODULES #######################

// ========== Miscelaneous ==========
Pair(a, b)                      // creates a pair of values
    .first                      // returns a
    .second                     // returns b



// ========== Collections ==========
import kotlin.collections.*         // default import, i.e. imported to every Kotlin file
// Inheritance Diagram:
// MutableIterable   ←  Iterable
//        ↓                 ↓
// MutableCollection ←  Collection
//        ↓          ↙  ←  ⤶⤷  →  ↘
//        ↓        List            Set         Map
//        ↓         ↓               ↓           ↓
//        ⤷ →     MutableList   MutableSet  MutableMap

// Iterator Members
    .hasNext()              // returns boolean
    .next()                 // returns the next element and moves the pointer to this element
    .asSequence()           // returns a sequence with all elements
    .forEach(lmbd(it))      // applies operation op to each element
    .iterator()             // returns itself (used in for-loops)
    .withIndex()            // returns Iterable<IndexedValue<T>>

// ListIterator Members
    .hasPrevious()          // returns boolean
    .nextIndex()            // returns index of the element that would be returned by .next()
    .previous()             // returns the element pointed to and moves the pointer backwards
    .previousIndex()        // returns index of the element that would be returned by .previous()

// MutableIterator Members
    .add(e)                 // adds the element between the currently pointed to and next
    .set(e)                 // sets the pointed element to e
    .remove()               // removes the element pointed to


// Iterable, MutableIterable
    .iterator()             // returns an iterator over the elements of the object


// Collection Members
    .size                   // returns size (#elem) of the collection
    .contains(e1)           // returns boolean
    .containsAll(col)       // returns boolean, checks if every element of a collection col is in the collection
    .isEmpty()              // returns boolean
    .indices                // returns IntRange of valid indices
    // creating new collections
    .toList()               // returns a deep copy as a list
    .toMutableList()        // returns a deep copy as a mutable list
    .toSet()                // returns a deep copy as a set
    // transformation operations
    .map {lmbd(it)}                 // applies lambda to elements and returns the result as a list
    .mapIndexed {lmbd(idx, value)}  // applies lambda to indices and elements and returns the result as a list


// MutableCollection Members
    .add(e)                 // adds e to the end of the list
    +, +=
    .addAll(col)            // adds all elements from col to the list
    .clear()                // deletes all elements
    .remove(e)              // removes e
    -=
    .removeAll(col)         // removes all elements in col from the list
    .retainAll(col)         // keeps only elements that are in col


// List (an ordered collection with access to elements by indices)
listOf(e1, e2, ...)         // returns [e1, e2, ...]
List(N, lmbd(it))           // creates N element list with elements given by the lambda fct
    [N]                     // returns N-th element
    .get(N)                 // returns N-th element
    .indexOf(e1)            // returns the index of the element e1
    .lastIndexOf(e1)        // returns the last index of e1 or -1
    .listIterator(idx)      // returns a list iterator starting at idx (default idx = 0)
    .sublist(frmIdx, toIdx) // returns a sublist from-to
    .lastIndex              // returns index of the last element of -1

// MutableList
mutableListOf(e1, e2, ...)  // returns mutable [e1, e2, ...]
mutableListOf<TYPE>()       // creates an empty mutable list of TYPE
    .add(idx, e)            // adds e to the idx position
    .removeAt(idx)          // removes element with idx
    .retainAll(col)         // keeps only elements that are in col
    .set(idx, e)            // replaces element at idx with e


// Set (a collection of unique elements)
setOf(e1, e2, ...)          // returns a set of the elements
// MutableSet
mutableSetOf(e1, e2, ...)   // returns a mutable set of the elements
mutableSetOf<TYPE>()        // creates an empty mutable set of TYPE


// Map (or dictionary) is a set of key-value pairs
Entry<out K, out V>         // a type representing key-value pair held by map
mapOf(k1 to v1, ...)        // returns a map of key-value pairs
    .entries                // returns a read-only set of entries of the map
    .keys                   // returns a read-only set of all keys of the map
    .values                 // returns a read-only collection of all values of this map
    .size                   // returns the number of key-value pairs in the map
    .containsKey(k)         // returns boolean
    .containsValue(v)       // returns boolean
    .get(k)                 // returns the value corresponding to the key k or returns null
    [k]                     // same as get
    .getOrDefault(k, dv)    // returns the value corresponding to the key k or returns the default value dv
    .isEmpty()              // returns boolean

// MutableMap
MutableEntry<out K, out V>  // a type representing key-value pair held by mutable map
mutableMapOf(k1 to v1, ...) // returns a mutable map of key-value pairs
mutableMapOf<TYPE, TYPE>()  // creates an empty mutable map with keys of the type TYPE and values of the type TYPE
    .entries                // returns a mutable set of entries of the map
    .keys                   // returns a mutable set of all keys of the map
    .values                 // returns a mutable collection of all values of this map
    .clear()                // deletes all key-value pairs
    .put(k, v)              // adds key-value pair k-v
    .putAll(map)            // updates the key-value paris with those from map
    .remove(k)              // removes the specified key and its value from the map, returns the value
    .remove(k, v)           // removes k-v pair only if k-v pair exists, returns boolean

// more efficient creation of mutable map than mutableMapOf(k1 to v1, ...)
mutableMapOf<TYPE, TYPE>().apply { this[k] = v; ... }



// ========== Ranges and Progressions ==========
import kotlin.ranges.*      // default import, i.e. imported to every Kotlin file

1..N                        // defines a range [1, N], e.g. for (i in 1..4) print(i) prints 1234
1.rangeTo(N)                // exactly as above
1..N step k                 // as above, just the step is k not 1, e.g. for (i in 1..8 step 2) print(i) prints 1357
N downTo 1                  // defines a range [N, 1], e.g. for (i in 4 downTo 1) print(i) prints 4321
N downTo 1 step k           // as above, just the step is k not 1, e.g. for (i in 8 downTo 1 step 2) print(i) prints 8642
1 until N                   // defines a range [1, N) (N is excluded), e.g. for (i in 1 until 4) print(i) prints 123
k in 1..N                   // returns boolean depending on

(1..10).filter{it % 2 == 0} // returns list [2, 4, 6, 8, 10]
(1..10).map{it % 2 == 0}    // returns list [false, true, false, true, false, true, false, true, false, true]



// ========== Sequences ==========
// This is something like python's generator. The elements are not calculated untill one calls them.
// I.e. sequence can be infinite and everything works as far as one doesn't call the whole sequence.
sequenceOf(e1, e1, ...)         // returns a sequence with e1, e2, etc...
iterable.asSequence()           // returns a sequence with elements from the iterable
generateSequence(lmbd(it))      // returns a sequence with elements generated by the lambda function ending when lambda returns null;
generateSequence(e0, lmbd(it))  // as above, but the first element is e0; in both cases 'it' represents the previous element;
sequence(lmbd(yield, yieldAll)) // python generator, yield takes a single element, yieldAll takes Iterable, Iterator, or Sequence and can be infinite
                                // e.g. {val start = 0; yield(start); yieldAll(1..5 step 2); yieldAll(generateSequence(8) { it * 3 })}
    .iterator()                 // returns iterator returning the elements of the sequence



// ========== Collection Operations (Extension Functions) ==========

// Transformations
    .map(lmbd(it))                  // applies lambda to every element and returns the transformed elements in a list
    .mapTo(dst, lmbd(it))           // applies lambda to every element and appends the result to dst
    .mapNotNull, .mapNotNullTo      // both as above, but discards null results of the lambda

    .mapIndexed(lmbd(i, v))         // applies lambda to every element and its index and returns the transformed elements in a list
    .mapIndexedTo(dst, lmbd(i, v))  // applies lambda to every element and its index and appends the result to dst
    .mapIndexedNotNull, .mapIndexedNotNullTo

    .mapKeys(lmbd(E<k,v>))          // returns a new map with keys being the result of lambda and values unchanged; lambda argument is Entry
    .mapValues(lmbd(E<k,v>))        // as above, but alters values and keys stay unchanged
    .mapKeysTo, .mapValuesTo        // appends the result into an existing map (dst argument)

    .zip(col)                       // returns list of Pairs where first is from receiver and second from col
    .zip(col, lmbd(a,b))            // returns list of elements created by applying zip and then lambda on the resulting pairs
    .unzip()                        // returns a pair of lists containing the first and second elements, respectively

    .associate(lmbd(it))            // returns a map with keys and values being the first and second element of a pair returned by the lambda
    .associateWith(lmbd(it))        // returns a map with keys being elements of the receiver and values the returns of the lambda
    .associateBy(lmbd(it))          // returns a map with keys being the returns of the lambda and values the elements of the receiver
    .associateTo, .associateWithTo, .associateByTo

    .flatten()                      // applied on collection of collections, returns list of all elements (leaves)
    .flatMap(lmbd(it))              // behaves as .flatten().map(lmbd(it))

    .joinToString(...)              // returns a string from all the elements separated using separator; prefix, postfix,etc. possible
    .joinTo(dst, ...)               // appends every element as a string to dst; prefix, postfix, etc. possible

// Filtering                        // here predicate (prdc) is a lambda function returning boolean
    .filter(prdc(it))               // returns a list with elements for the predicate is true
    .filter(prdc(E<k,v>))           // retutns a map with entries for which the predicate is true
    .filterIndexed(prdc(idx, it))   // returns a list with elements for which the predicate is true
    .filterNot(prdc(it))            // opposite of filter, returns elements for which the predicate is false
    .filterIsInstance<T>()          // returns a list with elements of the type T
    .filterNotNull()                // returns a list without null elements

    .partition(prdc(it))            // returns a pair of lists, the first containing elements that return true, the second contains the rest

    .any(prdc(it))                  // returns boolean depending on if any of the elements return true
    .any()                          // returns boolean depending on if the collection is non-empty, oppeosite of none()
    .none(prdc(it))                 // returns boolean depending on if none of the elements return true
    .none()                         // returns boolean depending on if the collection is empty, opposite of any()
    .all(prdc(it))                  // returns boolean depending on if all of the elements return true

// plus and minus operators
    a+b                             // returns a read-only collection of type a with the collection (or element) b appended to the collection a
    a-b                             // returns a read-only collection of type a with all occurances of elements from b removed from a
                                    //                                       or with the first occurance of the element b removed from a

// Grouping                         // here keySelector (kSle) and valueTransform (vTra) are lambda functions
    .groupBy(kSle(it))              // returns a map with elements E<kSle(it), listOf(it)>
    .groupBy(kSle(it), vTra(it))    // returns a map with elements E<kSle(it), listOf( vTra(it) )>

// Retrieving collection parts
    .slice(a..b)                    // returns a list of collection elements in the range a..b
    .slice(lisfOf(1,3,5,0))         // returns a list of collection elements with indices 1, 3, 5, 0

    .take(N)                        // returns a list of first N elements
    .takeLast(N)                    // returns a list of last N elements
    .drop(N)                        // returns a list of all elements except the first N
    .dropLast(N)                    // returns a list of all elements except the last N

    .takeWhile(prdc(it))            // returns a list of all consecutive first elementd for which prdc(it) is true
    .takeLastWhile(prdc(it))        // returns a list of all consecutive last elements for which prdc(it) is true
    .dropWhile(prdc(it))            // returns a list of elements starting at first element such that prdc(it) is false till the end
    .dropLastWhile(prdc(it))        // returns a list of elements from the beginning till all remining elements return true from prdc(it)

    .chunked(N)                     // returns a list of N-sized lists of elements
    .chunked(N, lmbd(chunk))        // returns a list of lmbd(chunk) elements, where chunk is the N-sized lists of elements
    .windowed(N, step)              // returns a list of N-sized windows, i.e. windowed(3,s) wound give [[1,2,3], [1+s,2+s,3+s], ...]
    .windowed(N, step, lmbd(w))     // returns a list of lmbd(window)
    .zipWithNext()                  // returns a list of all pairs of adjucent elements [1,2,3,4] -> [[1,2],[2,3],[3,4]]

// Retrieving single elements
    .elementAt(N)                   // returns the (N+1)th element, similar to [N] on lists, throws
    .elementAtOrNull(N)             // as above, if out of bounds returns null
    .elementAtOrElse(N, lmbd(idx))  // as above, if out of bounds returns lmbd(N)

    .first()                        // returns the first element
    .first(lmbd(it))                // returns the first element for which lmbd is true, throws
    .firstOrNull(lmbd(it))          // as above, but for no match return null

    .last()                         // returns the last element
    .last(lmbd(it))                 // returns the last element for which lmbd is true, throws
    .lastOrNull(lmbd(it))           // as above, but for no match returns null

    .random()                       // returns a random element

    .contains(e)                    // returns boolean
    .containsAll(col)               // returns boolean
    e in col                        // returns boolean
    .isEmpty()                      // returns boolean
    .isNotEmpty()                   // returns boolean

// Ordering                         // cmp is a comparator, slct is a selector function returning comparable object, e.g. basic type
    .compareBy(slct(it),...)        // creates a comparator, uses a sequence of lambdas (selectors) to calculate a result of comparison
    .sorted()                       // returns a list with elements sorted in ascending order
    .sortedDescending()             // returns a list with elements sorted in descending order
    .sortedWith(cmp(it))            // returns a list with elements sorted in ascending order based on the provided comparator
    .sortedWithDescending(cmp(it))  // returns a list with elements sorted in descending order based on the provided comparator
    .sortedBy(slct(it))             // returns a list with elements sorted in ascending order based on the provided selector function
    .sortedByDescending(slct(it))   // returns a list with elements sorted in descending order based on the provided selector function
    .reversed()                     // returns a list with elements in reversed order
    .asReversed()                   // returns a reversed read-only view of the original collection
    .shuffled()                     // returns a list with elements in random order

// Aggregate operations
    .min(), .max()                  //
    .minWith(cmp), .maxWith(cmp)    // return minimum and maximum element based on the provided comparator
    .minBy(slct), .maxBy(slct)      // return minimum and maximum element based on the provided selector function
    .average()                      //
    .sum()                          //
    .sumBy(fct), .sumByDouble(fct)  // sums the elements after applying fct which returns int and double, respectively
    .count()                        //

    .reduce(lmbd(acc, it))          // returns acc after performing acc = lmbd(acc, it) on each element
    .reduceRight(lmbd(acc, it))     // as above, but runs in the oposite direction
    .reduceIndexed(lmbd(idx,acc,it) // as above, but lmbd takes also index as an argument
    .reduceIndexedRight(...)        // as above, but runs in the oposite direction and lmbd takes index as an argumet
    .fold(sum, lmnd(acc, it))       // returns acc after perfotming acc = lmbd(acc, it) on each element, with initial sum
    .folcRight(...)                 // as above, but runs in the oposite direction
    .foldIndexed(lmbd(idx,acc,it))  // as above, but lmbd takes also index as an argument
    .foldIndexedRight(...)          // as above, but runs in the oposite direction and lmbd takes index as an argumet
