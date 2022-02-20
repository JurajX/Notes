//==================== C++ Standard Library

// ITERATORS & CONTAINERS
//      iterator
//      ranges
//      initializer_list
//   Sequential containers
//      bitset
//      span
//      array
//      vector
//      valarray
//      deque
//      forward_list
//      list
//   Container Adapters
//      queue
//      priority_queue
//      stack
//   Ordered Associative Containers
//      map
//      multimap
//      set
//      multiset
//   Unrdered Associative Containers (Hash Tables)
//      unordered_map
//      unordered_multimap
//      unordered_set
//      unordered_multiset
// ALGORITHMS
//      algorithm
//      numeric
//      execution
// STRINGS
//      string
//      cstring
//      string_view
//      charconv
//      format
//      regex
// STREAMS
//      iostream
//      ostream
//      istream
//      iomanip
//      ios
//      sstream
//      fstream
// ERRORS & LOGGING
//      filesystem
//      exception
//      stdexcept
//      source_location
// TYPE & TYPE CHECKS
//      concepts
//      type_traits
//      typeinfo
// MEMORY
//      memory
//      new
//      memory_resource
// MISC
//      random
//      chrono
//      utility
//      functional
//      optional
//      variant
//      any
//      bit
//      compare
//      cmath
// CONSTANTS
//      numbers
//      limits
//      cstddef
//      ratio
// MULTI-THREADED PROGRAMS
//      thread
//      mutex
//      future




//################################################## ITERATORS & CONTAINERS

// containers:                                                                (best/worst)  Insert              Delete              Lookup
//  vector              <vector>                                                            O(1)/O(N)           O(1)/O(N)           O(1)
//  array               <array>                 (fixed size)                                n/a                 n/a                 O(1)
//  span                <span>                                                              O(1)/O(N)           O(1)/O(N)           O(1)/O(N)
//  list                <list>                  (doubly linked list)                        O(1)                O(1)                O(N)
//  forward_list        <forward_list>          (singly linked list)                        O(1)                O(1)                O(N)
//  deque               <deque>                 (double-ended queue)                        O(1)/O(N)           O(1)/O(N)           O(1)
//  queue               <queue>                 (FIFO)                                      O(1)                O(1)                n/a
//  priority_queue      <queue>                 (elements are removed in priority order)    O(logN)             O(logN)             n/a
//  stack               <stack>                 (FILO)                                      O(1)                O(1)                n/a
//  set                 <set>                   (unique elements)                           O(logN)             O(logN)             O(logN)
//  multiset            <set>                   (non-unique elements)                       O(logN)             O(logN)             O(logN)
//  unordered_set       <unordered_set>         (hash set, unique elements)                 O(1)/O(N)           O(1)/O(N)           O(1)/O(N)
//  unordered_multiset  <unordered_set>         (hash set, non-unique elements)             O(1)/O(N)           O(1)/O(N)           O(1)/O(N)
//  map                 <map>                   (unique keys)                               O(logN)             O(logN)             O(logN)
//  multimap            <map>                   (non-unique keys)                           O(logN)             O(logN)             O(logN)
//  unordered_map       <unordered_map>         (hash table, unique keys)                   O(1)/O(N)           O(1)/O(N)           O(1)/O(N)
//  unordered_multimap  <unordered_map>         (hash table, non-unique keys)               O(1)/O(N)           O(1)/O(N)           O(1)/O(N)
//  bitset              <bitset>                (boolean container usefull for flags)       n/a                 n/a                 O(1)


// iterators:
// Input:           read-only access, forward only (no operator--); iters can be assigned, copied, and compared for equality.
//      operator++, operator*, operator->, copy constructor, operator=, operator==, operator!=
// Output:          write-only access, forward only; iters can be assigned, but cannot be compared for equality; one can do *iter = value
//      both operator++, operator*, copy constructor, operator=
// Forward:         read-only access, forward only; iters can be assigned, copied, and compared for equality
//      operator++, operator*, operator->, copy constructor, default constructor, operator=, operator==, operator!=
// Bidirectional:   read-only access; iters can be assigned, copied, and compared for equality
//      operator++, both operator--, operator*, operator->, copy constructor, default constructor, operator=, operator==, operator!=
// Random access:   equivalent to raw pointers: support pointer arithmetic, array index syntax, and all forms of comparison
//      operator++, both operator--, operator*, operator->, copy constructor, default constructor, operator=, operator==, operator!=,
//      operator+, operator-, operator+=, operator-=, operator<, operator>, operator<=, operator>=, operator[]
// Contiguous:      random-access capability and logically adjacent elements of the container must be physically adjacent in memory
//      operator++, both operator--, operator*, operator->, copy constructor, default constructor, operator=, operator==, operator!=,
//      operator+, operator-, operator+=, operator-=, operator<, operator>, operator<=, operator>=, operator[]


// iterators provided by containers:
// .begin(), .end(), .cbegin(), .cend(), .rbegin(), .rend(), .crbegin(), .crend()       // [begin, end); non-const, const, reverse, const reverse


//==================== iterator
#include <iterator>

begin(), end();         // [begin, end); non-const; iter points to the first/one-past-last element; op++ moves forward
cbegin(), cend();       // [begin, end); const; iter points to the first/one-past-last element; op++ moves forward
rbegin(), rend();       // [begin, end); reverse; iter points to the last/one-before-first element; op++ moves backwards
crbegin(), crend();     // [begin, end); const reverse; iter points to the last/one-before-first element; op++ moves backwards
distance();             // returns the distance between two iterators

inserter()              // returns insert_iterator of the passed container
back_inserter()         // returns back_insert_iterator of the passed container
front_inserter()        // returns front_insert_iterator of the passed container

make_move_iterator()    // returns move_iterator of the passed container


template <typename ItType> void f(ItType it) {
    typename iterator_traits<ItType>::value_type val;           // variable of type reffered to by it
    typename iterator_traits<ItType>::difference_type diff;     // variable of type capable representing diff of two iterators
    typename iterator_traits<ItType>::iterator_category cat;    // variable of type that is the same as the type of the iterator
    typename iterator_traits<ItType>::pointer prt;              // variable of type of the pointer to an element
    typename iterator_traits<ItType>::reference ref;            // variable of type reference to an element
}

ostream_iterator;                           // an output stream iterator
istream_iterator;                           // an input stream iterator
ostream_iterator<int> o_beg { cout, " " }   // can be used to print ints of a vector
istream_iterator<int> i_beg { cin };        // can be used to read ints from a console
istream_iterator<int> i_end;                // the end iterator

// iterator adapters
insert_iterator                 // uses insert(pos, elem) to insert elements into a container
back_insert_iterator            // uses push_back(elem) to insert elements into a container
front_insert_iterator           // uses push_front(elem) to insert elements into a container
reverse_iterator                // reverse the iteration order of another iterator
move_iterator                   // the dereferencing operator for a move_iterator converts the value to an rvalue ref, so it can be moved from

copy(cbegin(v), cend(v), back_insert_iterator {v2} );   // appends elements of v to v2


// reverse iterators
reverse_iterator                // iterates in the reverse direction; op++ moves backwards
.base()                         // returns one-past-current element; *reverse_iterator == *(reverse_iterator.base() - 1)



//==================== ranges
#include <ranges>

ranges::begin(), ranges::end();                     // return iterators, also and c-, r- and cr- versions; functions as in iterators
ranges::empty(), ranges::data(), ranges::cdata();   //
ranges::size();                                     // returns # of elems for O(1) size-query containers; else use std::distance()

// range-based algorithms can be accessed via std::ranges::alg_name()
std::ranges::sort(vec);             // sorts the elements in vec
std::ranges::sort(vec, op, f);      // sorts the elements in vec using op as comparison operator and applies function f to every element

// Similar to iterators, there are input-, output-, forward-, bidirectional-, random- access-, and contiguous ranges,
// with corresponding concepts such as ranges::contiguous_range, ranges::random_access_range, and so on.

// Views, views:: is actually std::ranges::views::
views::all;                         // Creates a view that includes all elements of a range.
filter_view, views::filter;         // Filters the elements of a range based on a given predicate.
transform_view, views::transform;   // Applies a callback to each element of a range to transform the element to some other value.
take_view, views::take;             // Creates a view of the first N elements of a range.
take_while_view views::take_while;  // Creates a view of the initial elements of a range until the first false returned by the predicate.
drop_view, views::drop;             // Creates a view by dropping the first N elements of a range.
drop_while_view, views::drop_while; // Creates a view by dropping all initial elements of a range until the first false returned by the predicate.
reverse_view, views::reverse;       // Creates a view that iterates over the elements of a range in reverse order; must be a bidirectional range.
elements_view, views::elements;     // Requires a range of tuple-like elements, creates a view of the Nth elements of the tuple-like elements.
keys_view, views::keys;             // Requires a range of pair-like elements, creates a view of the first element of each pair.
values_view, views::values;         // Requires a range of pair-like elements, creates a view of the second element of each pair.
common_view, views::common;         // Depending on the type of range, begin() and end() might return different types.

// ussage of ranges; even1 and even2 show two different ways
vector values { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
auto even1 { values | std::ranges::views::filter( [](const auto& value) { return value % 2 == 0; }) };
auto even2 { ranges::filter_view { values, [](const auto& value) { return value % 2 == 0; } } };
// views can be chained using op|
auto v { range | view1 | view2 | view3 };

// Factories, lazily evaluated ranges
empty_view;                         // Creates an empty view
single_view;                        // Creates a view with a single given element
iota_view;                          // Creates an infinite/bounded view as follows {init, init+1, init+2, ...}
basic_istream_view, istream_view;   // Creates a view containing elements retrieved by calling operator>> on an input stream
// ussage
std::ranges::iota_view { 10 };
std::ranges::views::iota(10);



//==================== initializer_list
#include <initializer_list>

int fct(std::initializer_list<int> vals);   // declares a fct taking initialiser_list as an argument
int a { fct({ 10, 20, 30, 40, 50, 60 }) }   // defines a with the result of the fct; variable number of args can be passed



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± Sequential containers


//==================== bitset
#include <bitset>

bitset<10> b;       // the b[0] is the rightmost bit (intuition from numbers with base 2)
b[3];
b.set(3);
b.test(3);
b.flip(3);



//==================== span c++20
#include <span>          // allows for writing functions accepting vectors, arrays and c-stype arrays, views, subviews



//==================== array
#include <array>
array<int, n> arr                   // creates n-element array with uninitialised elements (vector always initialises elements)
array<int, n> arr { 9, 8, 7 }       // initialises a n-element array and sets first 3 elements; n must be a constexpr
array arr { 9, 8, 7 }               // initialises a 3-element thanks to compatible with CTAD (class template argument deduction)
arr.size()                          // returns the number of elements of the array
size(arr)                           // returns the number of elements; works on stack based arrays as well
get<i>(arr);                        // returns i-th element; i needs to be constexpr; compile-time bound check as opposed to op[]

arr.swap(other);                    // runs in O(n) time (for vector it's O(1)); move is also O(n) complexity



//==================== vector
#include <vector>                                        // template <class T, class Allocator = std::allocator<T>> class vector;
vector<int> v1 {1,2,3};                                 // vec initialisation; compatible with CTAD (class template argument deduction)
vector<int> v2(11);                                     // size 11, all elements equal to 0
vector<int*> v2(11);                                    // size 11, all elements equal to nullptr
vector<double> v3(12, 9.9);                             // size 12, all elements equal to 9.9
vec[i];                                                 // does not throw an error if i >= vec.size()

vec.assign(count, elem);                                // replaces all elements with count copies of elem
vec.assign(beg, end);                                   // replaces all elements with elements from given range of iterators
vec.assign(init_list);                                  // replaces all elements with the elements from the given initialiser list
vec.swap(other);                                        // swaps the contents
vec.push_back(elem);                                    // adds elem at the end of vec
vec.pop_back();                                         // removes the last element of vec; the element is not returned
vec.insert(posIt, elem);                                // inserts elem at posIt and shifts all subsequent element
vec.insert(posIt, count, elem);                         // inserts count copies of elem at posIt and shifts all subsequent element
vec.erase(posIt);                                       // removes the element at posIt
vec.erase(posIt_f, posIt_l);                            // removes the elements at [posIt_f, posIt_l)

vec.emplace_back(args);                                 // same as push_back(T(args)); where args can be multiple entries
vec.emplace(posIt, args);                               // same as insert(posIt, T(args)); where args can be multiple entries

vec.size();                                             // returns the number of elements
vec.capacity();                                         // returns the number of elements that can be held in currently allocated storage
vec.empty();                                            // checks whether the container is empty
vec.reserve(cap);                                       // reserves storage to cap; if cap < vec.capacity() do nothing
vec.resize(count);                                      // changes the number of elements stored
vec.resize(count, val);                                 // changes the number of elements stored

erase(vec, val);                                        // erases all val elements from vec
erase_if(vec, pred);                                    // erases all elements for which pred(elem) == True

vec.begin(), vec.end();                                 // return iterators; also and c-, r- and cr- versions;

vector names { "John", "Sam", "Joe" };                  // deduces template type as vector<const char*>
vector names { "John"s, "Sam"s, "Joe"s };               // deduces template type as vector<string>

vector<int>::iterator, vector<int>::const_iterator;     // type (const) iterator for vector<int>



//==================== valarray
#include <valarray>      // similar to the vector class but is more optimized for high-performance numerical applications



//==================== deque
#include <deque>                 // similar functionality as vector (but not contiguous in memory, no reserve or capacity fcts)

// additional functions
deq.push_front(elem);           // adds elem to the front of deq
deq.emplace_front(args);        // same as push_front(T(args)); where args can be multiple entries
deq.pop_front();                // removes the first element of deq; the element is not returned



//==================== forward_list
#include <forward_list>  // a singly-linked list; no way to go to the previous elem -> modifying ops need open range (one-before-first, one-past-last)

flst.before_begin();    // returns an iterator pointing to an imaginary element before  the beginning of the list;



//==================== list
#include <list>                                          // a doubly-linked list; similar functions as vector
lst.begin(); lst.end();                                 // returns an iterator to the first element/one-past-last element

lst.front();                                            // access the first element
lst.back();                                             // access the last element

lst.begin(), lst.end();                                 // return iterators; also and c-, r- and cr- versions;

lst.insert(it, element);                                // adds an element before the element referred by the it
lst.erase(it);                                          // removes the element referred by the it



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± Container Adapters

//==================== queue
#include <queue>                 // template <class T, class Container = deque<T>> class queue; deque can be swapped for list

q.push(), q.emplace();          // add new elements to the tail
q.front(), q.back();            // returns reference to the first/last element
q.pop();                        // removed the head element; the element is not returned
q.size(); q.empty(); q.swap();


//==================== priority_queue
#include <priority_queue>        // template <class T, class Container = vector<T>, class Compare = less<T>>; (simplified)

q.push(), q.emplace();          // add new elements to the tail
q.pop();                        // removed the head element; the element is not returned
q.top();                        // returns ref to const
q.size(); q.empty(); q.swap();



//==================== stack
#include <stack>                 // template <class T, class Container = deque<T>> class stack; Container can be vector, list, or deque

s.push(), s.emplace();          // add new elements to the top
s.pop();                        // removed the top element; the element is not returned
s.top();                        // returns ref to the top element
s.size(); s.empty(); s.swap();



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± Ordered Associative Containers

//==================== map
#include <map>       // template<class Key, class T, class Compare=less<Key>, class Allocator=allocator<pair<const Key, T> >> class map;

map<string, int> m;                         // creates a map (or dictionary) (usually red-black tree); keys must be unique
map<string, int> m { {"a", 1}, {"b", 2} };  // as above
map m { pair{"a"s, 1}, pair{"b"s, 2} };     // as above

m[key];                         // returns the corresponding value or creates new key with a default value (for the type); is not const
m.at(key);                      // returns val; if key does not exist out_of_range is thrown
m.find(key);                    // returns the corresponding iterator or end(m) iter if key does not exist
m.count(key);                   // returns int; 0 or 1 depending if key is in the map
m.contains(key);                // returns bool;

m[key] = val;                   // assignes new value to m[key] or creates a new pair
m.insert({key, val});           // returns pair(it, bool) where it points to m[key]; does not overwrite existing key in which case bool == false
m.insert_or_assign(key,val);    // as above, the ret.second==true if inserted, ==false if overwritten
m.emplace(args);                // constructs element in-place, if key does not exist (val might be constructed, in later case imediately destroyed)
m.try_emplace(args);            // inserts in-place if the key does not exist, does nothing if the key exists

m.erase(it); m.erase(key);      // erases the element pointed to by it/having the specified key
m.erase(it_b, it_e);            // erases the elements in the range [it_b, it_e)

m1.insert(m2.extract(key));     // moved node corresponding to key from m2 to m1
m1.merge(m2);                   // moves all nodes from m2 to m1; nodes that would cause duplication stay in m2



//==================== multimap
#include <multimap>      // as map, but does not provide op[], .at(), insert_or_assign(), try_emplace()
insert()                // returns just the iter
lower_bound(key);       // returns an iter to the first element not less than the given key; if key does not exist it equals to upper_bound
upper_bound(key);       // returns an iter to the first element greater than the given key; if key does not exist it equals to lower_bound
equal_range(key);       // returns (a pair) a range of elements matching a specific key



//==================== set
#include <set>           // as map, but does not provide op[], insert_or_assign(), try_emplace()

//==================== multiset
#include <multiset>      // a multiset is to a set what a multimap is to a map



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± Unrdered Associative Containers (Hash Tables)

// Hash fcts are provided for: primitive data types: bool, char, int, float, double, ...
// Hash fcts are provided for: error_code, error_ condition, optional, variant, bitset,
//                             unique_ptr, shared_ptr, type_index, string, string_ view, vector<bool>, and thread::id

// user def. hash fct for a class myCls; it forwards the call to built in hash fct for ints and applies it to the int data member of myCls
namespace std {
    template<> struct hash<myCls> {
        size_t operator()(const myCls& x) const { return std::hash<int>{}(x.intMember); }
    };
}


//==================== unordered_map
#include <unordered_map>
// template <class Key, class T, class Hash=hash<Key>, class Pred=equal_to<Key>, class Alloc=allocator<pair<const Key, T>>> class unordered_map;

unordered_map<string, int> my_Umap;                     // creates a unsorted map (using hashed lookup)

//==================== unordered_multimap
#include <unordered_multimap>    // similar to unordered_map, differences are similar to those between map and multimap

//==================== unordered_set
#include <unordered_set>         // similar to set;

//==================== unordered_multiset
#include <unordered_multiset>    // similar to multiset;



//################################################## ALGORITHMS

//==================== algorithm
#include <algorithm>

// Non-modifying sequence operations
find(it_b, it_e, val);              // returns the first elem s.t. elem == val in range [it_b, it_e); if not found it_e is returned
find_if(it_b, it_e, pred);          // as above, but pred(elem) == ture
find_if_not(it_b, it_e, pred);      // as above, but pred(elem) == false
n = count(it_b, it_e, val);         // n is the number of elem == val in range [it_b, it_e)
n = count_if(it_b, it_e, pred);     // n is the number of pred(elem) == true in range [it_b, it_e)

//----- Functions (accepting iterators) and Funciton-like entities (accepting ranges)
// Modifying sequence operations
// Partitioning operations
// Sorting operations
// Binary search operations (on sorted ranges)
// Other operations on sorted ranges
// Set operations (on sorted ranges)
// Heap operations
// Minimum/maximum operations
// Comparison operations
// Permutation operations



//==================== numeric
#include <numeric>

accumulate(it_b, it_e, init)        // sums up a range of elements
accumulate(it_b, it_e, init, op)    // sums up a range of elements



//==================== execution
#include <execution>

// EXECUTION POLICY TYPE        GLOBAL INSTANCE     DESCRIPTION
//  sequenced_policy             seq                 not allowed to parallelize or vectorize its execution
//  parallel_policy              par                 allowed to parallelize but not vectorize its execution
//  parallel_unsequenced_policy  par_unseq           allowed to parallelize and vectorize its execution; and to migrate its execution across threads
//  unsequenced_policy           unseq               allowed to vectorize but not parallelize its execution




//################################################## STRINGS

//==================== strings
// string literals are stored in read only memory; one should always assign them to const variables
#include <string>

string str{"Text"};             // defines a string
"a string", 'c'                 // examples of a string and a character, note the quotes

auto str { "Hello World" };     // str is const char*
auto str { "Hello World"s };    // str is std::string

toupper(str);                   // retruns an upper-case copy of str
getline(source, var);           // reads a whole line incl. terminating newline char from source to var
+, +=, [], ==, <=>              // concatenate, append, select, compare, 3-way compare c++20

//---------- member fcts
str.substr(i, j);               // returns a copy of substr of length j starting at i-th position
str1.replace(i, j, str2);       // replaces substr(i, j) of str1 by str2
str1.compare(str2);             // analog of strcmp(cstr1, cstr2);
str.c_str();                    // returns a const char* pointing to the string data, invalid when str realocates memory (e.g. due to size)
str.data();                     // returns char* when called on a non-const string
str1.find(str2);                // finds str2 in str1 and returns its position (string::npos if not found)
str1.starts_with(str2);         // boolean depending on if the str1 starts with str2
str1.ends_with(str2);           // boolean depending on if the str1 ends with str2

//---------- helper fcts
to_string(T val);               // converts numerical value into a string
stoi(str, idx, base);           // converts str to int;                 idx of the first non-converted char (ignored if nullptr); base dflt is 10
stol(str, idx, base);           // converts str to long;                idx of the first non-converted char (ignored if nullptr); base dflt is 10
stoul(str, idx, base);          // converts str to unsigned long;       idx of the first non-converted char (ignored if nullptr); base dflt is 10
stoll(str, idx, base);          // converts str to long long;           idx of the first non-converted char (ignored if nullptr); base dflt is 10
stoull(str, idx, base);         // converts str to unsigned long long;  idx of the first non-converted char (ignored if nullptr); base dflt is 10
stof(str, idx);                 // converts str to float;               idx of the first non-converted char (ignored if nullptr)
stod(str, idx);                 // converts str to double;              idx of the first non-converted char (ignored if nullptr)
stold(str, idx);                // converts str to long double;         idx of the first non-converted char (ignored if nullptr)



//==================== c-strings
#include <cstring>
strcpy(trgt, src)       // brute-force copy src to trgt; doesn't check for sizes
strcpy_s()              // as above but  secure
strcat(trgt, src)       // brute-force append src to trgt; doesn't check for sizes
strcat_s()              // as above but secure
strlen(str)             // length of a string ('\0' not included)
strcmp(a, b)            // three-way compares two c-strings 'a' and 'b'; returns int, ==0 if a == b



//==================== string_view
#include <string_view>
// Use an string_view instead of const string& or const char* whenever a function requires a read-only string as one of its parameters
"Hello World!"sv;       // string_view literal



//==================== charconv
#include <charconv>     // converts character sequences to integral of floation values and vice versa
from_chars_result from_chars(f, l, val, base=10);  // [f, l) converted and saved in 'val'; conversion not possible 'val' is unchanged



//==================== format
#include <format>
// Use to format strings
format("Read {} bytes from {}", n, "file1.txt");    // emits "Read 5 bytes from file1.txt"
format("Read {0} bytes from {1}", n, "file1.txt");  // same as above



//==================== regex
#include <regex>

bool regex_match(InputSequence[, MatchResults], RegEx[, Flags]);
bool regex_search(InputSequence[, MatchResults], RegEx[, Flags]);
string regex_replace(InputSequence, RegEx, FormatString[, Flags]);

//---------- ECMAScript
// special characters, to match them one needs to escape them (e.g. \^); all other characters match themselves;
^ $     // anchors; matche the position (immediately following/of) a line termination char; ^test$ -> matches exactly "test\n"
.       // wildcard; matches any one char;
|       // alternation; a|b -> matches a or b
()      // capture groups; (.)(ab|cd)(.) on 1cd4 returns these groups 1cd4, 1, cd, 4; (?: ) doesn't capture, used for precedence

// repeatitions are greedy: find the longest match while still matching the remainder of the regular expression; to make them non-greedy
// add ? beghind; e.g. on "aaabbb" (a+)(ab)*(b+) gives "aaa" "" "bbb", (a+?)(ab)*(b+) gives "aa" "ab" "bb"
*       // repetition; matches the preceeding part zero or more times; a*b matches b, ab, aab, ...
+       // repetition; matches the preceeding part one or more times; a+b matches ab, aab, ...
?       // repetition; matches the preceeding part zero or one times; a?b matches b, ab
{}      // bounded repeat; a{n}, a{n, }, a{n, m} matches a repeated n times, n or more times, between [n, m]-times, not [n,m)!

[]      // or; ab[cde] matches "abc", "abd", "abe"; ^ plays a role of negation: ab[^cde] matches "abp" etc. but not any of "abc", "abd", "abe"
        // [a-zA-Z] matches any of the standard letters; [0-9] matches any number

\b      // match a word boundary
\B      // match anything but \b
\n      // back reference; refs n-th caputred group n > 0



//################################################## STREAMS

//==================== iostream, ostream, istream
#include <iostream>
#include <ostream>
#include <istream>

 cin;  cout;  cerr;  clog;          // character      input, output, un-buffered error and buffered error streams, use  char
wcin; wcout; wcerr; wclog;          // wide character input, output, un-buffered error and buffered error streams, use wchar_t

cout << "Some string or " << var;   // prints strings or variables (of built-in types) to the console
<<;                                 // overloaded to print integer, float, double, strings and pointer values
cin >> var1 >> var2;                // takes the keyboard input and stores it in the var; input is tokenised on whitespace chars
>>;                                 // saves the entered text into var based on the type of var and the entered text

"\n, \f, \r , \t, \v, \\, \" "      // new line, new page, carriage return, horizontal tab, vertical tab, backslash, quote

//---------- iostream
iostrm.good();                      // returns true if stream is "good", i.e. is in normal usable state; same as (!iostrm.fail() && !iostrm.eof())
iostrm.bad();                       // returns true if a fatal error has occured; e.g. non-fatal condition is end of file
iostrm.fail();                      // returns ture if the most recent operation failed; doesn't say anything about the next operation
iostrm.clear();                     // resets the error state of cout

//---------- ostream
ostrm.write("Hello\n", 6);          // raw output method, accepts character array
ostrm.put('c');                     // raw output method, accepts a single character
ostrm.fluch();                      // flushed the buffer
ostrm.precision(N);                 // sets precision of the stram to N; returns the old value
(!ostrm)                            // conversion to bool, same as ostrm.fail()

//---------- istream
istrm.get();                        // raw input method, returns the next character
istrm.get(char);                    // raw input method, returns the stream, stores next character in char
istrm.unget();                      // puts the last received character back on the stream
istrm.putback(char);                // puts char back on the stream
istrm.peek();                       // looks at the next character, but doesn't remove it from the stream
istrm.getline(buffer, N);           // reads N-1 chars (or until eol) from the stream to buffer, terminates the read with '\0'; eol is removed
(!istrm)                            // conversion to bool, same as istrm.fail()

//---------- manipulators
endl;                               // inserts a '\n' into the output sequence and flushes it



//==================== iomanip
#include <iomanip>

//---------- manipulators
setbase(int N);                     // sets the base for numbers
setfill(char c);                    // fills the empty spaces with character c
setprecision(int N);                // sets the precision to N
setw(int N);                        // sets the width parameter to N
put_money; put_time;                // formats and outputs a monetary value; formats and outputs a date/time value according to the specified format
get_money; get_time;                // parses a monetary value; parses a date/time value of specified format



//==================== ios
#include <ios>

//---------- manipulators
boolalpha; noboolalpha;             // switches between textual and numeric representation of booleans; true (false); 1 (0); dflt is noboolalpha
hex, oct, dec;                      // changes the base used for integer I/O
showpoint; noshowpoint;             // controls whether decimal point is always included in floating-point representation
skipws, noskipws;                   // controls whether leading whitespace is skipped on input



//==================== sstream
#include <sstream>

ostringstream o_stream;
o_stream << "text " << "text";      // ussage as o streams
istringstream i_stream;
i_stream >> var1 >> var2;           // ussage as i streams



//==================== fstream
#include <fstream>
ofstream o_file {"path/to/file", MODE };
ifstream i_file {"path/to/file", MODE };
fstream io_file {"paht/to/file", MODE };

i_file.tie(&o_file);                // links the output stream to the input stream; calls to one causes the other to flush
i_file.tie(nullptr);                // unlinks the streams

//---------- MODES, can be combined with bitwise or (|)
ios_base::app;                      // go to the end before each write operation
ios_base::ate;                      // go to the end once immediately after opening
ios_base::binary;                   // input and output in binary more as opposed to text mode
ios_base::in;                       // open for input, start at the beginning
ios_base::out;                      // open for output, start writing at the beginning (overwriting existing data)
ios_base::trunc;                    // open for output, delete all existing data

seekg(POS), seekg(OFFSET, POS);     // setting read positions
seekp(POS), seekg(OFFSET, POS);     // setting write positions
tellg(), tellp();                   // returns streampos the current read, write location of the stream

//---------- POS (streampos)
ios_base::beg;                      // beginning of the stream
ios_base::end;                      // end of the stream
ios_base::cur;                      // current position in the stream



//==================== syncstream c++20
#include <syncstream>
osyncstream syncCout { cout };      // creates a synced cout stream; guarantees thread safe behaviour (no interleaved outputs)
syncCout << "message" << endl;      // ussage as cout; all text is outputed at once at the time of destruction of syncCout


//################################################## ERRORS & LOGGING

//==================== filesystem
#include <filesystem>
// using namespace std::filesystem;
path p1 { R"(D:\Foo\Bar)" };        // absolute path on windows, uses raw string literal to deal with slashes
path p2 { "lib/X11" };              // relative path on unix based systems
p1.c_str(), p1.native();            // convert path to the native format
p1 /= p2, p1.append(p2);            // appends p2 to p1, adds path separators
p1 += p2, p1.concat(p2);            // appends p2 to p1, does not add path separators

for (const auto &comp : path) {};   // iterates over the components of the path

//---------- path
path p { "/dir1/dir2/data.txt" };
p.root_name();                      // returns the root name; string before the first path separator
p.parent_path();                    // path before the last path separator
p.filename();                       // returns the file name; the string after the last path separator
p.replace_filename(file);           // replaces the file name
p.remove_filename();                // removes the file name; filename returns ""
p.stem();                           // returns the stem of the file name
p.extension();                      // returns the extension of the file name
p.replace_extension("txt");         // replaces extension of file to txt; if filename is "" it still appends the new extension
p.has_extension();                  // bool
p.is_absolute();                    // bool
p.is_relative();                    // bool

//---------- directory entry
directory_entry de { p };           // constructs directory entry from path
de.exists();                        // bool if de exists in the system
de.is_directory();                  // bool if de is a directory
de.is_regular_file();               // bool if de is a file
de.file_size();                     // returns de file size
de.last_write_time();               // returns last write time

create_directory(p), create_directories(p);     // creates dir in path
remove(p), remove_all(p);                       // removes a file or empty directory; removes a file or the whole content of a directory

recursive_directory_iterator begin { p }, end { };  // defines recursive iterators
for (auto iter { begin }; iter != end; ++iter) {};  // iterates over all files and subdirectories of path p



//==================== exception
#include <exception>

//---------- overview
logic_error                             // in <stdexcept>                       indicates violations of logical preconditions or class invariants
    invalid_argument                    // in <stdexcept>                       reports invalid arguments
    domain_error                        // in <stdexcept>                       reports domain errors
    length_error                        // in <stdexcept>                       reports attempts to exceed maximum allowed size
    out_of_range                        // in <stdexcept>                       reports arguments outside of expected range
    future_error                        // in <future>          (C++11)
bad_optional_access                     // in <optional>        (C++17)
runtime_error                           // in <stdexcept>                       indicates conditions only detectable at run time
    range_error                         // in <stdexcept>                       reports range errors in internal computations
    overflow_error                      // in <stdexcept>                       reports arithmetic overflows
    underflow_error                     // in <stdexcept>                       reports arithmetic underflows
    regex_error                         // in <regex>           (C++11)
    system_error                        // in <system_error>    (C++11)
        ios_base::failure               // in <ios>             (C++11)
        filesystem::filesystem_error    // in <filesystem>      (C++17)
    tx_exception                        // in <stdexcept>       (TM TS)
    nonexistent_local_time              // in <chrono>          (C++20)
    ambiguous_local_time                // in <chrono>          (C++20)
    format_error                        // in <format>          (C++20)
bad_typeid                              // in <typeinfo>
bad_cast                                // in <typeinfo>
    bad_any_cast                        // in <any>             (C++17)
bad_weak_ptr                            // in <memory>          (C++11)
bad_function_call                       // in <functinal>       (C++11)
bad_alloc                               // in <new>
    bad_array_new_length                // in <new>             (C++11)
bad_exception                           // in <exception>
bad_variant_access                      // in <variant>         (C++17)


//---------- functions
current_exception();                    // captures the current exception in a std::exception_ptr   (C++11)
rethrow_exception();                    // throws the exception from an std::exception_ptr          (C++11)
throw_with_nested();                    // throws its argument with std::nested_exception mixed in  (C++11)
rethrow_if_nested();                    // throws the exception from a std::nested_exception        (C++11)
terminate();                            // function called when exception handling fails
get_terminate();                        // obtains the current terminate_handler                    (C++11)
set_terminate();                        // changes the function to be called by std::terminate


//---------- exception handling in multi-threaded applications
void doSomeWork() {
    cout << "throwing" << endl;
    throw runtime_error { "excep from thread" };
}
void threadFunc(exception_ptr& err) {
    try { doSomeWork(); }
    catch (...) {
        cout << "caught excep" << endl;
        err = current_exception();
    }
}
void doWorkInThread() {
    exception_ptr error;
    thread t { threadFunc, ref(error) };
    t.join();
    if (error) { cout << "exception in main" << endl; rethrow_exception(error); }
    else { cout << "no exception in main." << endl; }
}
int main() {
    try { doWorkInThread(); }
    catch (const exception& e) { cout << "Main function caught: '" << e.what() << "'" << endl;}
}



//==================== stdexcept
#include <stdexcept>
invalid_argument ex { "Some reason" };      // creates an invalid argument exception
ex.what()                                   // returns "Some reason"



//==================== source_location
#include <source_location>

std::source_location srcl = std::source_location::current();    // creates source_location based on the position where it is called

srcl.line()                 // returns the line number represented by srcl
srcl.column()               // returns the column number represented by srcl
srcl.file_name()            // returns the file name represented by srcl
srcl.function_name()        // returns the name of the function represented by srcl, if any



//################################################## TYPE & TYPE CHECKS

//==================== concepts c++20
// see also "Notes - C++.cpp" -> Templates -> Concepts c++20
#include <concepts>
same_as, derived_from, convertible_to, integral, floating_point, copy_constructible     // core language concepts
equality_comparable, totally_ordered                                                    // comparison concepts
movable, copyable                                                                       // object concepts
invocable, predicate                                                                    // callable concepts

template <typename T> concept IsDerivedFromFoo = derived_from<T, Foo>;
template <typename T> concept IsConvertibleToBool = convertible_to<T, bool>;
template <typename T> concept DefaultAndCopyConstructible = default_initializable<T> && copy_constructible<T>;



//==================== type_traits
#include <type_traits>

// Primary type categories
is_integral<T>;                 // checks if T is an integral type
is_floating_point<T>;           // checks if T is a floating-point type
is_enum<T>;                     // checks if T is an enumeration type
is_union<T>;                    // checks if T is an union type
is_class<T>;                    // checks if T is a non-union class type
is_function<T>;                 // checks if T is a function type
is_lvalue_reference<T>;         // checks if T is a lvalue reference
is_rvalue_reference<T>;         // checks if T is a rvalue reference
// Composite type categorie
is_fundamental<T>;              // checks if T is a fundamental type
is_arithmetic<T>;               // checks if T is an arithmetic type
is_scalar<T>;                   // checks if T is a scalar type
// Type properties
is_const<T>;                    // checks if T is const-qualified
is_trivially_copyable<T>;       // checks if T is trivially copyable
is_polymorphic<T>;              // checks if T is a polymorphic class type
is_abstract<T>;                 // checks if T is an abstract class type
is_final<T>;                    // checks if T is a final class type
is_signed<T>;                   // checks if T is a signed arithmetic type
is_unsigned<T>;                 // checks if T is an unsigned arithmetic type
// Supported operations
// Property queries
// Type relationships
is_same<T>;                     // checks if two types are the same
is_base_of<T> ;                 // checks if a type is derived from the other type
// Const-volatility specifiers
// References
// Pointers
// Sign modifiers
// Arrays
// Miscellaneous transformations
conditional<B, T, F>;           // chooses one type or another based on compile-time boolean B
// Operations on traits


// ussage
template <class T> T f(T i) { static_assert(std::is_integral<T>::value, "Integral required."); return i; }  // checks if T is integral


//==================== typeinfo
#include <typeinfo>
std::typeid(CLS)                            // returns type ID of a class, only for classes with vtable; (at least one virtual method)
typeid(CLS1).name();                        // returns name of the class (compiler dependent); usual ussage is logging
if (typeid(CLS1) == typeid(CLS2)) {...;}    // possible ussage, but not recommended!



//################################################## MEMORY

//==================== memory
#include <memory>
std::uninitialized_copy(srcPtrFirst, srcPtrLast, dstPtrFirst);  // copies [srcPtrFirst, srcPtrLast) to an uninitialised memory at dstPtrFirst

//---------- unique pointer
unique_ptr<T> u_ptr{ new T{ args } };               // unique_ptr is moved when returned by a fct, and is destroyed when going out of scope
auto u_ptr { make_unique<T>(args) };                // preferred way of the above, allocates memory and stores it in u_ptr
auto u_ptr { make_unique_for_overwrite<T>(args) };  // as above, but primitive types are not initialised and objects are default constructed

u_ptr.reset()               // frees resource and sets to nullptr
u_ptr.reset(new T{ args })  // frees resource and sets to the new T instance
u_ptr.get()                 // returns the underlying pointer
u_ptr.release()             // returns the underlying pointer and looses ownership of it (needs to be stored and deleted manually)

// unique_ptr can be set to use custom allocation and deallocation functions (instead of new and delete); usefull for a file closing
int * alloc_fct(int);
void free_fct(int *);
unique_ptr<int, decltype(&free_fct)> u_ptr { alloc_fct(42), free_fct };


//---------- shared pointer
shared_ptr<T> s_ptr{ new T{ args } };               // shared_ptr is copied when returned by a fct; makes 2 heap allocations (for object and ptr)
auto s_ptr { make_shared<T>(args) };                // preferred way of the above, allocates memory and stores it in s_ptr; only 1 heap allocation
auto s_ptr { make_shared_for_overwrite<T>(args) };  // as above, but primitive types are not initialised and objects are default constructed
auto s_ptr1 { shared_ptr<int> { s_ptr, &foo->m_ } };// aliasing, s_ptr1 also owns object owned by s_ptr, but points to a member of that object

s_ptr.reset()               // sets to nullptr (and frees resource only when the last shared pointer is destroyed)
s_ptr.reset(new T{ args })  // sets to the new T instance (and frees resource only when the last shared pointer is destroyed)
s_ptr.get()                 // returns the underlying pointer
s_ptr.use_count()           // returns the reference count of shared_ptr data
s_ptr.release()             // not supported

// shared_ptr can be set to use custom allocation and deallocation functions (instead of new and delete); usefull for a file closing
int * alloc_fct(int);
void free_fct(int *);
shared_ptr<int> s_ptr { alloc_fct(42), free_fct };

atomic<std::shared_ptr<T>>; // calling non-const methods on the shared pointer is thread safe; calling non-const methods of T is not thread safe

//---------- casting
// shared_ptr casting
const_pointer_cast()            // used to cast away (remove) constness or volatility
static_pointer_cast()           // compile-time checked conversion, reversing a well-def implicit conversion
reinterpret_pointer_cast()      // unchecked conversion, changing the meaning of bit patterns
dynamic_pointer_cast()          // run-time checked conversion, class hierarchy navigation

//---------- weak pointer
weak_ptr<T> w_ptr { ptr };      // definition of a weak pointer; constructor needs the 'ptr' to be a shared_ptr<T> or another weak_ptr<T>
w_ptr.lock()                    // returns shared_ptr or nullptr

//---------- allocator
allocator<T> alloc;             // constructs a default allocator
auto mem alloc.allocate(1);     // allocates (uninit) memory for 1 object of type T and returns a pointer to the memory
new(mem) T{};                   // placement new op construct the object
destroy_at(mem);                // destroys the object
alloc.deallocate(mem, 1);       // deallocates the memory
mem = nullptr;



//==================== new
#include <new>

void myHandler() {};                                    // has to free some memory or throw; else infinite loop (p.524 professional c++, 5th edition)
new_handler oldHandler { set_new_handler(myHandler) };  // sets a handler for mem alloc errors from new and stores the old one

hardware_destructive_interference_size; // const specifying the min offset between two concurrently accessed objects to avoid cache line sharing


//==================== memory_resource
#include <memory_resource>      // if tow containters have different allocators, they are a different classes and can't be assigned to each other

pmr::polymorphic_allocator;     // makes possible to make common allocators so the above problem is solved



//################################################## MISC

//==================== random
#include <random>

//---------- engines; the SW engines have a lot of parameters; std provides a couple of predefined engines
random_device;                  // hardware engine; requires a device generating random nums; if no device found uses a software engine (unspecified)
linear_congruential_engine;     // takes min amount of memory; not good for high-quality rand num sequences
mersenne_twister_engine;        // takes a lot of memory (e.g. 2.5kB); highest-quality rand num sequences; one of the fastest engines
subtract_with_carry_engine;     // takes about 100B of memory; slower and of worse quality than mersenne_twister_engine

//---------- engine adapters
discard_block_engine(eng, p, r);    // uses eng to generate p nums, discards p-r of them and returns r nums
independent_bits_engine(eng, w, i); // generates rand nums of w-bit size by combining rand nums from eng
shuffle_order_engine(eng, k);       // has k number table generated by eng and returns a rand selected num from the table

//---------- predefined engines and adapters
minstd_rand0;       // engine; linear_congruential_engine
minstd_rand;        // engine; linear_congruential_engine
mt19937;            // engine; mersenne_twister_engine
mt19937_64;         // engine; mersenne_twister_engine
ranlux24_base;          // adapter; subtract_with_carry_engine
ranlux48_base;          // adapter; subtract_with_carry_engine
ranlux24;               // adapter; discard_block_engine
ranlux48;               // adapter; discard_block_engine
knuth_b;                // adapter; shuffle_order_engine
default_random_engine;  // adapter; implementation-defined

//---------- distributions (Uniform, Bernoulli, Poisson, Normal, Sampling)
uniform_int_distribution(min, max);
uniform_real_distribution(min, max);
bernoulli_distribution(p);
binomial_distribution(n, p);
poisson_distribution(mean);
exponential_distribution(lambda);
gamma_distribution(alpha, beta);
normal_distribution(mean, stddev);

//---------- examples
eng.entropy();                  // returns 0.0 for SW engine and non-zero num for HW engine
eng.min(); eng.max();           // returns min and max
eng();                          // returns a random number

// with distribution
random_device tmp;                                          // random_device to generate a seed
const auto seed { tmp.entropy() ? tmp() : time(nullptr) };  // seed; if random_device has no entropy if HW generator is not found/connected
mt19937 eng { static_cast<mt19937::result_type>(seed) };    // defines an engine with seed
uniform_int_distribution<int> distr { 1, 99 };              // defines a distribution
distr(eng);                                                 // returns a random number from a distribution
auto gen { std::bind(distribution, engine) };               // simplifies the above call; type is unknown, use template or std::function<int()>
gen();                                                      // same as 2 lines above



//==================== chrono
#include <chrono>
// using namespace std::chrono

//---------- Durations - represented as # of ticks and tick period (time in seconds it the ratio from <ratio>)
template <class Rep, class Period = ratio<1>> class duration;   // Rep is integras (# of ticks); Period is ratio (tick period);
Rep count() const                   // method; returns the duration value as the number of ticks
static duration zero()              // method; returns a duration with a duration value equivalent to zero
static duration min(), max();       // method; returns a duration with the minimum/maximum possible duration value representable by the Rep

// pre-defined duration types: nanoseconds, microseconds, milliseconds, seconds, minutes, hours; (rest c++20) days, weeks, months, years

duration<long long, milli> d4;      // defines a duration where each tick period is 1ms
duration<long, ratio<60>> d2 { 5 }; // defines a duration where each tick period is 60s and number of tics is 5
minutes d9 { 10 };                  // sames as above thanks to pre-defined duration types

duration<long> d7 { 30 };                                   // seconds
duration<double, ratio<60>> d8 { d7 };                      // minutes; can't be long because of result is non-integral (compiler error)
auto d8 { duration_cast<duration<long, ratio<60>>>(d7) };   // minutes; this one works

// std::literals::chrono_literals is an inlined namespace
auto myDur { 42min };   // works if one of "using namespace std/std::literals/std::chrono/std::chrono_literals/std::literals::chrono_literals" is used

//---------- Clocks
system_clock                                    // wall clock time from the system-wide real-time clock; can be adjusted backwards
steady_clock                                    // guarantees it's time never decreases
high_resolution_clock                           // never use; usually alias for one of the two above ones
utc_clock, tai_clock, gps_clock, file_clock     // c++20

std::chrono::system_clock::now()                // returns the current time as a time_point

//---------- Time points - represent a point in time relative to epoch (origin of time, unix 1.1.1970); always associated with a sertain clock;
// operations between time_point and duration: tp + d = tp,   tp – d = tp,   d + tp = tp,   tp – tp = d,   tp += d,   tp -= d

duration_cast<milliseconds>(t1-t0).count();     // converts units of t1-t0 to milliseconds

//---------- Dates (C++20)
// CLASS                    DESCRIPTION
//  year                     year with range [-32767, 32767]; has a method called is_leap(); min()/max() static methods return the min/max year
//  month                    month with range [1, 12]; there are 12 named constants, e.g. std::chrono::January
//  day                      day with range [1, 31]
//  weekday                  day of the week in the range [0, 6], where 0 means Sunday; there are six named constants, e.g. std::chrono::Sunday
// weekday_indexed           first,..., fifth weekday of a month; constructed from a weekday, e.g. Monday[2] is the second Monday of a month
// weekday_last              the last weekday of some month
// month_day                 specific month and day
// month_day_last            last day of a specific month
// month_weekday             nth weekday of a specific month
// month_weekday_last        last weekday of a specific month
// year_month                specific year and month
// year_month_day            specific year, month, and day
// year_month_day_last       last day of a specific year and month
// year_month_weekday        nth weekday of a specific year and month
// year_month_weekday_last   last weekday of a specific year and month

//---------- Time zones (C++20)
std::chrono::get_tzdb()     // returns ref-to-const of Internet Assigned Numbers Authority (IANA) time zone database

auto* brussels { locate_zone("Europe/Brussels") };                                      // creates time zone based on tzdb
zoned_time<hours> brusselsTime{ brussels, local_days { 2020y / June / 22d } + 9h };     // creates a local time/date
zoned_time<hours> newYorkTime { "America/New_York", brusselsTime };                     // converts the created local time to New York time



//==================== utility
#include <utility>

//---------- pair
pair<double, int> myPair { 1.23, 5 };   // defines a pair; compatible with CTAD (class template argument deduction)
auto myPair { make_pair(1.23, 5) };     // as above; not necessary thanks to CTAD
pair myPair { 1.23, 5 };                // as above (thanks to class template argument deduction - CTAD)
pair myPair;                            // does not compile
myPair.first; myPair.second;            // accesses the first and second data members

//---------- tuple
// can be used to implement lexicographical compare for classes: auto op<=>(const T& rhs) { return tie(m_1, m_2) <=> tie(rhs.m_1, rhs.m_2); }
tuple<T, E, R> tup;                     // declaration of a tuple storing 3 different types; iterating over the values is not easy
tuple tup { 1, 1.1, "srt"s };           // defines a tuple<int, double, string> using CTAD (class template argument deduction)
auto tup { make_tuple(1, 1.1, "srt"s) };// as above; not necessary thanks to CTAD
tuple tup { 1, ref(i), cref(i) };       // defines a tuple<int, int&, const int&>; i is an int; ref(), cref() in <functional>
auto tup { tuple_cat(t1, t2) };         // concatinates two tuples t1 and t2 into one tuple tup

auto [i, d, str] { tup };               // structured bindings; decomposes tup into the components (copy is made)
auto& [i, d, str] { tup };              // structured bindings; decomposes tup into the components (references - changing i/d/srt changes tup)

int i; double d; string str;
tie(i, d, str) = tup;                   // same as auto [i, d, str] { tup }, but i, d, str must be declared
tie(i, ignore, str) = tup;              // as above, but d is ignored/assigned (doesn't have to be declared)

get<i>(tup);                            // returns the i-th element (zero-indexed) of the tuple
get<T>(tup);                            // returns the element of type T; compiler error if tup has multiple elements of type T
apply(fct, tup);                        // applies fct (fct, fct obj, lambda) to the tup elements as arguments

make_from_tuple<T>(tup);                // creates an instance of T with tup elements passed to the T's constructor
tuple_element<2, tuple<T, E, R>>::type; // returns the type of the second (zero-indexed) template; kinda useless -> takes tuple type, not instance
tuple_element<2, decltype(tup)>::type;  // as above, but with decltype
tuple_size<tuple<T, E, R>>::value;      // returns the size of the tuple; kinda useless -> takes tuple type, not instance
tuple_size<decltype(tup)>::value;       // as above, but with decltype

//---------- fcts
forward(param);                         // forwards a function argument; forwards lvalues as either lvalues or as rvalues, depending on the type
swap(a, b);                             // exchanges the given values
as_const(param)                         // returns a reference-to-const version of its reference parameter
move(a);                                // indicates that an object a may be "moved from"; equivalent to a static_cast to an rvalue reference
exchange(a, b);                         // returns a and stores b in a; usefull in move assignment

//---------- comparisons; safe to use on mixed signed and unsigned comparisons
cmp_equal(), cmp_not_equal()
cmp_less(), cmp_less_equal()
cmp_greater(), cmp_greater_equal()



//==================== functional
#include <functional>       // implements functin objects for std algorithms (e.g. compareisoins, or plus, multiplies)

reference_wrapper<type>         // used to store references in containers
ref(obj); cref(obj);            // returns reference_wrapper<type_of_obj> to obj;
// example
vector<reference_wrapper<string>> vec{ ref(str1) };
vec.push_back(ref(str2));
vec[1].get() += "somethig";     // actually modifies the str2

std::invoke(fct, arg);          // same as fct(arg); usefull for generic template code where one needs to call an arbitrary callable object

// just use lambda expressions for the stuff below
function<R(ArgTypes...)>;               // R is the return type, ArgTypes is a comma-sep list of param types for the fct
bool f(function<bool(int, int)> myfct); // creates a fct f taking another function (taking 2 ints and returning bool) as an argument

plus<int> myPlus;           // defines plus function object
int res { myPlus(1, 2.2) }; // res is 3
plus<> myPlus;              // transparent operator function object; does not loose precision; more performant
int res { myPlus(1, 2.2) }; // res is 3.2

void f(int, string);                                        // declares f
auto f1 { bind(f, placeholders::_1, "hello"s) };            // creates f1(int) that actually is f(int, "hello")
auto f2 { bind(f, placeholders::_2, placeholders::_1) };    // creates f2(string, int) that actually is f(int, string)

mem_fn(&T::mem_fn);         // creates a function object out of a pointer to a member



//==================== optional
#include <optional>
optional<int> fct(bool giveIt);             // optional return statement for a function (can return int or std::nullopt)
optional<int> res { fct(true) };            // assigns the result of fct to a res variable
res.has_value()                             // returns true or false
res.value()                                 // returns value stored in res or an exception
res.value_or(STH)                           // returns value stored in res or STH
if (res) {...;}                             // same as if (res.has_value()) {...;}



//==================== variant
#include <variant>                  // can hold any of the types provided as template arguments;

monostate;                          // unit type intended for use as a well-behaved empty alternative in variant

variant<type1, type2> v;            // default constructs the first type; it type1 doesn't have default constructor (it won't compile)
variant<monostate, type1> v;        // use monostate to be able to default construct
v.index();                          // returns the (zero-based) index of the currently stored type

holds_alternative<type1>(v);        // returns bool based on if v currently holds type1
get<type1>(v); get<idx>(v);         // returns the variable of type1/at index; throws std::bad_variant_access if variant holds other type/index
get_if<type1>(&v); get_if<idx>(&v); // returns a pointer to the value of type1/at index; returns nullptr if variant holds other type/index
visit(vis, v);                      // calls the fct obj vis (callable on all types of v) with the arguments held by v



//==================== any
#include <any>                  // can hold any type of value

any a, a1 { 3 }, a2 {"str"s};   // creates vars of type any
a.has_value();                  // boolean
a.type()                        // returns type_info; i.e. typeid(val)/typeid(void) for non-empty/empty; call .name() on type_info

any_cast<type>(a);              // casts a to type; if a is not of type throws bad_any_cast



//==================== bit
#include <bit>                      // bit manipulations of unsigned ints
std::bit_cast<new_type>(expr);      // c++20, requires sizeof(src) == sizeof(target) and both are trivially copyable, for
                                    //  ...copying bits of source obj to a target obj and interpreting the copied bits as a target object

// all have uint as the firts argument
has_single_bit()                // returns true if a given value contains only a single bit; i.e. is an integral power of two
bit_ceil()                      // returns the smallest integral power of two greater than or equal to a given value
bit_floor()                     // returns the largest integral power of two smaller than or equal to a given value
bit_width()                     // returns the number of bits needed to store a given value
rotl(), rotr()                  // rotates the bits of a given value to the left/right over a given number of positions; rotl(0b101, 1) = 0b011
countl_zero(), countl_one()     // returns the number of consecutive zero/one bits in a given value starting from the left (most-significant bit)
countr_zero(), countr_one()     // returns the number of consecutive zero/one bits in a given value starting from the right (least-significant bit)
popcount()                      // returns the number of one bits in a given value



//==================== compare
#include <compare>

strong_ordering::less;
strong_ordering::greater;
strong_ordering::equal;

partial_ordering::less;
partial_ordering::greater;
partial_ordering::equivalent;
partial_ordering::unordered;

weak_ordering::less;
weak_ordering::greater;
weak_ordering::equal;



//==================== cmath
#include <cmath>
std::isnan()
std::isinf()



//################################################## CONSTANTS

//==================== numbers c++20
#include <numbers>
// the names without _v indicate double precision, e.g. numbers::e = numbers::e_v<double>
numbers::e_v<T>;            // e
numbers::log2e_v<T>;        // log_2(e)
numbers::log10e_v<T>;       // log_10(e)
numbers::pi_v<T>;           // pi
numbers::inv_pi_v<T>;       // 1/pi
numbers::inv_sqrtpi_v<T>;   // 1/sqrt(pi)
numbers::ln2_v<T>;          // ln(2)
numbers::ln10_v<T>;         // ln(10)
numbers::sqrt2_v<T>;        // sqrt(2)
numbers::sqrt3_v<T>;        // sqrt(3)
numbers::inv_sqrt3_v<T>;    // 1/sqrt(3)
numbers::egamma_v<T>;       // Euler–Mascheroni constant
numbers::phi_v<T>;          // the golden ratio



//==================== limits
#include <limits>

numeric_limits<TYPE>::max();        // largest representable value
numeric_limits<TYPE>::lowest();     // smallest representable value
numeric_limits<TYPE>::min();        // depending on type, smallest (positive) representable value

numeric_limits<TYPE>::has_infinity  // bool based on Type having infinity
numeric_limits<TYPE>::infinity()    // positive infinity



//==================== cstddef
#include <cstddef>
//---------- macros
NULL;                   // implementation-defined null pointer constant
offsetof;               // byte offset from the beginning of a standard-layout type to specified member
//---------- types
size_t;                 // unsigned integer type returned by the sizeof operator
ptrdiff_t;              // signed integer type returned when subtracting two pointers
nullptr_t;              // the type of the null pointer literal nullptr
max_align_t;            // trivial type with alignment requirement as great as any other scalar type
byte;                   // the byte type



//==================== ratio
#include <ratio>    // compile-time usable rational numbers

using r1 = ratio<1, 60>;                // definition of a rational compile-time constant representing the fraction 1/60
intmax_t num { r1::num };               // numerator
intmax_t den { r1::den };               // denominator
using r1 = ratio<n, d>;                 // error; if n and d are const then it's okay

using r2 = ratio<1, 30>;                // defines another ratio
using result = ratio_add<r1, r2>::type; // defines a result of r1 + r2 and normalises it; e.g. result is 1/20

// SI constants are defined:
//  yocto, zepto, atto, femto, pico, nano, micro, milli, centi, deci,
//  deca, hecto, kilo, mega, giga, tera, peta, exa, zetta, yotta



//################################################## MULTI-THREADED PROGRAMS

//==================== thread
#include <thread>

//---------- thread
// destruction of a joinable thread terminates the application
// to cancell running threads, use jthread or a shared variable that is periodically checked;
thread t {f}, t {f, a1, a2};    // f()/f(a1, a2) runs in another thread; can be fct, fctobj, lambda; all args/fctobj are copied; use ref() or cref()
thread t { &Cls::met, &inst };  // executes inst.met() in another thread; data races possible as no copy is made
t.join();                       // blocks the current thread until '*this' finishes; concurrent call (on same thread) is a data race (undef behavior)
t.detach();                     // separates '*this' from the current thread, execution continues independently; after *this no longer owns any thread

t.id;                       // represents the id of the thread
t.joinable();               // checks whether the t is joinable, i.e. potentially running in parallel context
t.get_id();                 // returns the id of t
t.native_handle();          // returns the underlying implementation-defined t handle
t.hardware_concurrency();   // static fct; returns the number of concurrent threads supported by the implementation

thread_local type var;      // either global or function static variable; each thread has a unique copy of it; initialised once per thread;


//---------- jthread c++20
// everything as thread; additionally joins at destruction, supports cooperative cancellation
jt.get_stop_source();       // returns a stop_source object associated with the shared stop state of the thread
jt.get_stop_token();        // returns a stop_token associated with the shared stop state of the thread
jt.request_stop();          // requests execution stop via the shared stop state of the thread

jthread jt { [](stop_token token) { while (!token.stop_requested()) {/* code */} } };   // possible ussage
jt.request_stop();          // stops the thread

//---------- functions in std::this_thread namespace
yield();                    // suggests that the implementation reschedule execution of threads, allowing other threads to run
get_id();                   // returns the thread id of the current thread
sleep_for(rel_time);        // stops the execution of the current thread for a specified time duration
sleep_until(abs_time);      // stops the execution of the current thread until a specified time point



//==================== stop_token
#include <stop_token>

stop_token st;          // an interface for querying if a std::jthread cancellation request has been made; class
st.stop_requested();    // checks whether the associated stop-state has been requested to stop
st.stop_possible();     // checks whether associated stop-state can be requested to stop

stop_source ss;         // a class representing a request to stop one or more std::jthreads
ss.request_stop();      // makes a stop request for the associated stop-state, if any
ss.get_token();         // returns a stop_token for the associated stop-state
ss.stop_requested();    // checks whether the associated stop-state has been requested to stop
ss.stop_possible();     // checks whether associated stop-state can be requested to stop

stop_callback;          // an interface for registering callbacks on std::jthread cancellation; class template
nostopstate_t;          // placeholder type for use in stop_source constructor; class



//==================== atomic
#include <atomic>

//---------- atomic
atomic<T>::is_always_lock_free;             // static bool const representing if atomic<T> is lock free
atomic<T> a;                                // declares an atomic variable of type T; T must be trivially copyable
a.is_lock_free();                           // checks if a is lock-free
a.store(arg);                               // atomically replaces the value of a with a non-atomic argument
a.load();                                   // atomically obtains the value of a
a.exchange(arg);                            // atomically replaces the value of a and obtains the value held previously
a.compare_exchange_weak(exp, des);          // atomically compares the value of a with non-atomic argument and
a.compare_exchange_strong(exp, des);        //  ...performs atomic exchange if equal or atomic load if not
a.fetch_add(arg);                           // atomically adds the arg to the value stored in a and obtains the value held previously
fetch_sub; fetch_and; fetch_or; fetch_xor;  // as above

a.wait(old);                                // blocks the thread until notified and the atomic value changes (i.e. a != old); c++20
a.notify_one();                             // notifies at least one thread waiting on the atomic object; c++20
a.notify_all();                             // notifies all threads blocked waiting on the atomic object; c++20

atomic_ref<T> ar { obj };                   // ref to an obj; interface as atomic<T>; one is not allowed to touch obj as far as an atomic_ref exists

//---------- atomic_flag
atomic_flag af = ATOMIC_FLAG_INIT;  // uniform initialisation is not allowed here

af.clear();                         // atomically sets flag to false
af.test_and_set();                  // atomically sets the flag to true and obtains its previous value
af.test();                          // atomically returns the value of the flag
af.wait();                          // blocks the thread until notified and the atomic value changes
af.notify_one();                    // notifies at least one thread waiting on the atomic object
af.notify_all();                    // notifies all threads blocked waiting on the atomic object



//==================== mutex
#include <mutex>

//---------- mutex
mutex m;                        // mutual exclusion object
m.lock();                       // locks the mutex, blocks if the mutex is not available; owning thread is not allowed to call thisa again
m.try_lock();                   // tries to lock the mutex, returns if the mutex is not available; owning thread is not allowed to call this again
m.unlock();                     // unlocks the mutex

//---------- timed mutex
timed_mutex tm;                 // timed mutual exclusion object
lock; try_lock; unlock;         // as in mutex
tm.try_lock_for(rel_time);      // tries to lock the mutex, returns if the mutex has been unavailable for the specified timeout duration
tm.try_lock_until(abs_time);    // tries to lock the mutex, returns if the mutex has been unavailable until specified time point has been reached

//---------- recursive mutex
recursive_mutex rm;             // recursive mutual exclusion object; multiple locks possible
lock; try_lock; unlock;         // as in mutex; lock/try_lock can be called multiple times, must be paired with equal amount of unlocks

//---------- recursive timed mutex
recursive_timed_mutex rtm;      // recursive timed mutual exclusion object; mix of recursive and timed mutex
lock; try_lock; unlock;         // as in recursive mutex
try_lock_for; try_lock_until;   // as in timed mutex; plus multiple calls allowed

//---------- lock guard; constructors below
explicit lock_guard(mutex_type& m);         // effectively calls m.lock(); undef behaviour for multiple locks on non-recursive mutex
lock_guard(mutex_type& m, adopt_lock_t t);  // acquires ownership of m without attempting to lock it; undef behaviour if m hasn't been locked

//---------- scoped lock; constructors below
explicit scoped_lock( MutexTypes&... m );           // as in lock guard but for multiple mutexes
scoped_lock( adopt_lock_t t, MutexTypes&... m );    // as in lock guard but for multiple mutexes

//---------- unique lock - allows defer lock acquisition; constructors below
explicit unique_lock( mutex_type& m );                  // as in lock guard
unique_lock(mutex_type& m, defer_lock_t t);             // does not immediately try to obtain a lock
unique_lock(mutex_type& m, try_to_lock_t t);            // tries to obtain a lock, if fail does not block, lock can be obtained later
unique_lock(mutex_type& m, adopt_lock_t t);             // as in lock guard
unique_lock(mutex_type& m, const chrono& abs_time);     // tries to obtain a lock, until abs_time
unique_lock(mutex_type& m, const chrono& rel_time);     // tries to obtain a lock, for rel_time
lock(); try_lock(); try_lock_for(); try_lock_until(); unlock();     // member fcts; work as in mutexes

//---------- functions
try_lock();     // attempts to obtain ownership of mutexes via repeated calls to try_lock; call on locks not mutexes
lock();         // locks specified mutexes, blocks if any are unavailable; call on locks not mutexes
call_once();    // invokes a function only once even if called from multiple threads
once_flag of;   // helper object to ensure that call_once invokes the function only once

//---------- ussage
mutex m;                                                // mutual exclusion object
unique_lock<mutex> lck{m};                              // acquisition of mutex object

mutex m1, m2;
unique_lock<mutex> lck1 {m1, defer_lock};               // defer_lock dictates not to axquire the mutex right away
unique_lock<mutex> lck2 {m2, defer_lock};               // defer_lock dictates not to axquire the mutex right away
lock(lck1, lck2);                                       // proceed only after acquiring all the locks



//==================== shared_mutex
#include <shared_mutex>

//---------- shared mutex
shared_mutex sm;                                // shared mutual exclusion object; supports read/write locks
lock; try_lock; unlock;                         // as in mutex; these are for exclusive ownership (write locks)
lock_shared; try_lock_shared; unlock_shared;    // as above; these are for shared ownership (read locks)

//---------- shared timed mutex
shared_timed_mutex stm;                         // shared timed mutual exclusion object; supports read/write locks
lock; try_lock; unlock;                         // as in shared mutex
lock_shared; try_lock_shared; unlock_shared;    // as in shared mutex
try_lock_for; try_lock_until;                   // as in timed mutex
try_lock_shared_for; try_lock_shared_until;     // as in timed mutex, but shared version

//---------- shared lock - allows defer lock acquisition
// constructors as in unique lock
// use unique_lock to obtain exclusive rather than shared locks
lock(); try_lock(); try_lock_for(); try_lock_until(); unlock(); // acquire shared instead of exclusive locks; i.e. lock_shared is called on the mutex


//==================== condition_variable
#include <condition_variable>

condition_variable cv;              // provides a condition variable associated with a std::unique_lock
condition_variable_any cv;          // provides a condition variable associated with any lock type

cv.notify_one();                    // notifies one waiting thread
cv.notify_all();                    // notifies all waiting threads

cv.wait(lck, [p]);                  // blocks until the cv is woken up; predicate p is used to control spurious wake-ups: while (!p()) {wait(lock);}
cv.wait_for(lck, rel_time, [p]);    // blocks until the cv is woken up or after the specified timeout duration; p as above
cv.wait_until(lck, abs_time, [p]);  // blocks until the cv is woken up or until specified time point has been reached; p as above

notify_all_at_thread_exit(cv, lck); // schedules a call to notify_all to be invoked when this thread is completely finished

//---------- ussage

std::mutex m;
std::condition_variable cv;
bool ready = false;

void worker_thread() {
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return ready;});
    // Send data back to main()
    processed = true;
    // Manual unlocking is done before notifying, to avoid waking up the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

int main() {
    std::thread worker(worker_thread);

    // set the data
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
    }   // lock is released
    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }   // lock is released

    worker.join();
}

//==================== latch
#include <latch>

latch l { N };              // single-use thread barrier, N is a positive integer; no data races on concurrent incocations of mem fcts

l.count_down(n=1);          // decrements the counter by n in a non-blocking manner; dflt n is 1
l.try_wait();               // tests if the internal counter equals zero; may spuriously return false even if counter == 0
l.wait();                   // blocks until the counter reaches zero
l.arrive_and_wait(n=1);     // decrements the counter by n and blocks until it reaches zero; dflt n is 1



//==================== barrier
#include <barrier>

barrier b {N, f};           // reusable thread barrier; N is number of threads to wait for; f is a fct called each time n is decremented to 0

b.arrive(n=1);              // arrives at barrier and decrements the expected count by n; dflt n is 1; returns arrival_token
b.wait(arrival_token);      // blocks at the phase synchronization point until its phase completion step is run
b.arrive_and_wait();        // arrives at barrier and decrements the expected count by 1, then blocks until current phase completes; wait(arrive())
b.arrive_and_drop();        // decrements both the initial expected count for subsequent phases and the expected count for current phase by one



//==================== semaphore
#include <semaphore>

counting_semaphore cs;          // semaphore that models a non-negative resource count
binary_semaphore bs;            // semaphore that has only two states

// for both counting and binary semaphores
s.release(n=1);                 // increments the internal counter by n and unblocks acquirers
s.acquire();                    // decrements the internal counter or blocks until it can
s.try_acquire();                // tries to decrement the internal counter without blocking; returns true if counter was decremented
s.try_acquire_for(rel_time);    // tries to decrement the internal counter, blocking for up to a time duration
s.try_acquire_until(abs_time);  // tries to decrement the internal counter, blocking until a point in time



//==================== future
#include <future>

//---------- future
future<T> fut;              // used to pass a value between threads; T needs to be move-constructable
fut.valid();                // checks if the future has a shared state
fut.wait();                 // waits for the result to become available
fut.wait_for(rel_time);     // waits for the result, returns if it is not available for the specified timeout duration
fut.wait_until(abs_time);   // waits for the result, returns if it is not available until specified time point has been reached
fut.get();                  // returns a value from future, wait for it if necessary
fut.share();                // transfers the shared state from *this to a shared_future and returns it

//---------- shared future
// as future, but is copyable; multiple shared future objects may refer to / are allowed to wait for the same shared state
shared_future<T> sfut { move(fut) };    // similar to future; T needs to be copy-constructable

//---------- promise
promise<T> pro;                             // constructs a promise
pro.get_future();                           // returns a future associated with the promised result
pro.set_value(val);                         // sets the result to specific value
pro.set_value_at_thread_exit(val);          // sets the result to specific value while delivering the notification only at thread exit
pro.set_exception(e_ptr);                   // sets the result to indicate an exception
pro.set_exception_at_thread_exit(e_ptr);    // sets the result to indicate an exception while delivering the notification only at thread exit

//---------- ussage of future and promise
promise<int> prom;
auto fut { prom.get_future() };
thread t { doWork, move(prom) };            // promise is not copyable
int result { fut.get() };
t.join();

//---------- packaged task
packaged_task pt;
pt.valid();                         // checks if the task object has a valid function
pt.get_future();                    // returns a future associated with the promised result
pt.operator()(args);                // executes the function
pt.make_ready_at_thread_exit(args); // executes the function ensuring that the result is ready only once the current thread exits
pt.reset()                          // resets the state abandoning any stored results of previous executions

//---------- ussage of packaged task
T f(R, S);
packaged_task<T(R, S)> pt { f };    // creates a packaged task to run the function f
auto tur { pt.get_future() };       // returns the future for the result of the pt
thread t { move(pt), arg1, arg2 };  // creates a thread, moves pt into it, and executes pt with arg1 and arg2
int result { theFuture.get() };     // gets the result
t.join();

//---------- functions
async([policy], f, arg1, arg2, ...);    // runs f asynchronously (potentially in a new thread); returns a std::future that will hold the result
                                        //   policy is launch::async, launch::deferred, or launch::async | launch::deferred (dflt behaviour)
