// ========================== Google Test
# include "gtest/gtest.h"



// ========================== Cmake SetUp
// NOTE: cmake comment starts with # not //

include(CTest)                                          // this has to be in the top-most (project) CMakeLists.txt

add_executable( test "test.cpp" )
set_target_properties( test PROPERTIES CXX_STANDARD 20 )
// ------ option one
find_package( GTest REQUIRED )                          // makes troubles if gtest was compiled with different compiler
target_link_libraries( test PUBLIC GTest::gtest )       // link one or the other more ...
target_link_libraries( test PUBLIC GTest::gtest_main )  //  ... in Invoking the Tests part
// ------ option two
include(FetchContent)                                   // fetches and compiles gtest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
target_link_libraries( test PUBLIC gtest )              // link one or the other more ...
target_link_libraries( test PUBLIC gtest_main )         //  ... in Invoking the Tests part
// ------ option end
include(GoogleTest)                                     // include some test
gtest_discover_tests(test)                              // automatic test discovery



// ========================== Invoking the Tests
//  - tests are registered automatically
//  - if linked with gtest_main a suitable entry point is defined automatically; i.e. a main function
//  - if linked with gtest one must write custom main function; use only if
//    - a customisation before the tests run is needed and cannot be expressed with fixtures and test suites alone

RUN_ALL_TESTS()     // returns 0 if all pass, 1 otherwise; the return value cannot be ignored

int main(int argc, char **argv) {               // basic main fct for testing
    ::testing::InitGoogleTest(&argc, argv);     // parses and removes all recognised command line flags
    return RUN_ALL_TESTS();
}



// ========================== Fixtures

class Fixture : public ::testing::Test {
 protected:
    // ussage of ctor/dtor or SetUp/TearDown: https://google.github.io/googletest/faq.html#CtorVsSetUp
    //   - ctor/dtor are preferred; both cannot use ASSERT_xxx
    //   - ctor can't use virtual fct calls with dynamic dispatch (instead uses the fct associated with the object)
    //   - dtor can't throw

    // remove any or all of the following functions if their bodies would be empty
    Fixture() {}                // you can do set-up work for each test here.
    ~Fixture() override {}      // you can do clean-up work that doesn't throw exceptions here.

    // if the constructor and destructor are not enough for setting up and cleaning up each test, you can define the following methods
    void SetUp() override {}    // will be called immediately after the constructor (right before each test)
    void TearDown() override {} // will be called immediately after each test (right before the destructor).

    // class members declared here can be used by all tests in the test suite
    T data;                     // accessible from the test cases
};



// ========================== Test Case
TEST(TestSuiteName, TestName) {         // standard test
    // test body
}

TEST_F(TestFixtureName, TestName) {     // test with a fixture
    // test body
}



// ========================== Assertions

// fatal failure     -> aborts the current test case imediately, possibly skipping clean-up (can cause mem leaks)
// non-fatal failure -> allows the current test case to continue running

MACRO() << "msg1" << "msg2";    // a custom failure message for all types of macro
ASSERT_*                    // generates a fatal failure
EXPECT_*                    // generates a non-fatal failure

// ------- Explicit Success and Failure
SUCCEED()                   // purely documentary (doesn’t generate any user-visible output)
FAIL()                      // fatal failure; can be used only in functions that return void
ADD_FAILURE()               // non-fatal failure
ADD_FAILURE_AT(file, line)  // non-fatal failure at the file path and line number specified

// ------- Generalized Assertion
    _THAT(value, matcher) // checks if value matches the matcher

// ------- Boolean Conditions
    _TRUE(cond)     // verifies that condition is true
    _FALSE(cond)    // verifies that condition is false
    _EQ(val1, val2) // verifies that val1 == val2; performs pointer equality on pointers (use nullptr instead of NULL)
    _NE(val1, val2) // verifies that val1 != val2; performs pointer inequality on pointers (use nullptr instead of NULL)
    _LT(val1, val2) // verifies that val1 <  val2;
    _LE(val1, val2) // verifies that val1 <= val2;
    _GT(val1, val2) // verifies that val1 >  val2;
    _GE(val1, val2) // verifies that val1 >= val2;

// ------- C String Comparison
    _STREQ(str1, str2)      // verifies that the two C strings str1 and str2 have the same contents
    _STRNE(str1, str2)      // verifies that the two C strings str1 and str2 have different contents
    _STRCASEEQ(str1, str2)  // verifies that the two C strings str1 and str2 have the same contents, ignoring case
    _STRCASENE(str1, str2)  // verifies that the two C strings str1 and str2 have different contents, ignoring case

// ------- Floating-Point Comparison
// ULP stands for Unit in the last place; it represents the smallest distance from a number in the discrete floating-point space
    _FLOAT_EQ(val1, val2)           // verifies that val1 and val2 are approximately equal, to within 4 ULPs from each other
    _DOUBLE_EQ(val1, val2)          // verifies that val1 and val2 are approximately equal, to within 4 ULPs from each other
    _NEAR(val1, val2, abs_error)    // verifies that abs(val1 - val2) < max(val1, val2) * abs_error

    _PRED_FORMAT2(::testing::FloatLE, val1, val2)       // verifies that val1 <= val2 (approximately equal)
    _PRED_FORMAT2(::testing::DoubleLE, val1, val2)      // verifies that val1 <= val2 (approximately equal)

// ------- Exception Assertions
    _THROW(stmnt, except_type)      // verifies that statement throws an exception of type exception_type
    _ANY_THROW(stmnt)               // verifies that statement throws an exception of any type
    _NO_THROW(stmnt)                // verifies that statement does not throw any exception

// ------- Predicate Assertions
// for overloaded predicates or a function template predicates explicitly specify the type of the function
    _PRED1(pred, val1)              // verifies that pred(val1) == ture
    _PRED5(pred, val1, ..., val5)   // verifies that pred(val1, val2, ..., val5) == ture
    _PRED_FORMAT1(pred_frmtr, val1) // see https://google.github.io/googletest/reference/assertions.html#EXPECT_PRED_FORMAT

// ------- Death Assertions
    // complicated, see https://google.github.io/googletest/reference/assertions.html#death
    _DEATH(stmnt, matcher)
    _DEATH_IF_SUPPORTED(stmnt, matcher)
    _DEBUG_DEATH(stmnt, matcher)
    _EXIT(stmnt, pred, matcher)

// ------- Assertion Result
testing::AssertionResult IsEven(int n) {
  if ((n % 2) == 0) return testing::AssertionSuccess();         // test should succees
  else return testing::AssertionFailure() << n << " is odd";    // test should fail
}
EXPECT_TRUE(IsEven(3));                                         // will fail with a nice message

// ------- Type Assertions
::testing::StaticAssertTypeEq<T1, T2>() // generates compile time error if T1 and T2 are different; used inside template code



// ========================== Matchers
#include "gmock/gmock.h"
// all matchers are in the ::testing:: namespace

_THAT(arg, matcher) // arg will be referred to below

// ------- Wildcard
_                   // arg can be any value of the correct type
A<T>() or An<T>()   // arg can be any value of type type

// ------- Generic Comparison
Eq(val)             // arg == val
Ge(val)             // arg >= val
Gt(val)             // arg > val
Le(val)             // arg <= val
Lt(val)             // arg < val
Ne(val)             // arg != val
IsFalse()           // arg evaluates to false in a Boolean context
IsTrue()            // arg evaluates to true in a Boolean context
IsNull()            // arg is a NULL pointer (raw or smart)
NotNull()           // arg is a non-null pointer (raw or smart)
Optional(m)         // arg is optional<> that contains a value matching m
VariantWith<T>(m)   // arg is variant<> that holds the alternative of type T with a value matching m
Ref(variable)       // arg is a reference to variable
TypedEq<T>(val)     // arg has type type and is equal to val

// ------- Floating-Point Matchers
DoubleEq(val)               // arg is a double, approximately equal to val, treating two NaNs as unequal
FloatEq(val)                // arg is a float, approximately equal to val, treating two NaNs as unequal
NanSensitiveDoubleEq(val)   // arg is a double, approximately equal to val, treating two NaNs as equal
NanSensitiveFloatEq(val)    // arg is a float, approximately equal to val, treating two NaNs as equal
IsNan()                     // arg is any floating-point type with a NaN value

DoubleNear(val, max_abs_error)              // arg is a double, close to val (abs error <= max_abs_error); two NaNs are unequal
FloatNear(val, max_abs_error)               // arg is a float, close to val (abs error <= max_abs_error); two NaNs are unequal
NanSensitiveDoubleNear(val, max_abs_error)  // arg is a double, close to val (abs error <= max_abs_error); two NaNs are equal
NanSensitiveFloatNear(val, max_abs_error)   // arg is a float, close to val (abs error <= max_abs_error); two NaNs are equal

// ------- String Matchers
// regex syntax: https://google.github.io/googletest/advanced.html#regular-expression-syntax
ContainsRegex(string)   // arg matches the given regex
EndsWith(suffix)        // arg ends with string suffix
HasSubstr(string)       // arg contains string as a sub-string
IsEmpty()               // arg is an empty string
MatchesRegex(string)    // arg matches the given regex (match from the first to the last char)
StartsWith(prefix)      // arg starts with string prefix
StrCaseEq(string)       // arg is equal to string, ignoring case
StrCaseNe(string)       // arg is not equal to string, ignoring case
StrEq(string)           // arg is equal to string
StrNe(string)           // arg is not equal to string
WhenBase64Unescaped(m)  // arg is a base-64 escaped string whose unescaped string matches m

// ------- Container Matchers
BeginEndDistanceIs(m)           // arg is a container end() - begin() conforms with matcher m; e.g. m is Lt(2); see also SizeIs(m)
IsEmpty()                       // arg is an empty container
SizeIs(m)                       // arg.size() conforms to the matcher m

ContainerEq(cont)               // same as Eq(cont) with the failure message including which elements differ
Contains(e)                     // arg contains an element that matches e (a value or a matcher)
Contains(e).Times(n)            // as above and the number of matches is n (a value or a matcher); allows e.g. Contains(e).Times(0)
Each(e)                         // arg is a container where every element matches e (a value or a matcher)

Pointwise(m, cont)                  // arg.size == cont.size(), and for all i m(std::tuple(arg_i, cont_i)) returns true
Pointwise(m, {e0, ..., en})         // as above, but use m(std::tuple(arg_i, e_i))
UnorderedPointwise(m, container)    // same as Pointwise(m, container), but ignores the order of elements
UnorderedPointwise(m, {e0, ..., en})// same as above

WhenSorted(m)                   // arg is sorted using the < operator, it matches container matcher m
WhenSortedBy(comparator, m)     // same as above with a given comparator

ElementsAre(e0, ..., en)        // arg has n + 1 elements, where the i-th element matches ei (a value or a matcher)
ElementsAreArray({e0, ..., en}) // same as above except element values/matchers come from an initializer list ...
ElementsAreArray(a_container)   // ... STL-style container ...
ElementsAreArray(beg, end)      // ... iterator range ...
ElementsAreArray(array)         // ... C-style array ...
ElementsAreArray(array, count)  // ... C-style array

UnorderedElementsAre(e0, ..., en)           // arg has n + 1 elems; exists bijective map between elems and  ei's (a value or a matcher)
UnorderedElementsAreArray({e0, ..., en})    // same as above except element values/matchers come from an initializer list ...
UnorderedElementsAreArray(a_container)      // ... STL-style container ...
UnorderedElementsAreArray(begin, end)       // ... iterator range ...
UnorderedElementsAreArray(array)            // ... C-style array ...
UnorderedElementsAreArray(array, count)     // ... C-style array

IsSubsetOf({e0, ..., en})       // arg matches UnorderedElementsAre(x0, x1, ..., xk) where {x0, x1, ..., xk} ⊆ {e0, ..., en}
IsSubsetOf(a_container)
IsSubsetOf(begin, end)
IsSubsetOf(array)
IsSubsetOf(array, count)

IsSupersetOf({e0, ..., en})     // Some subset of arg matches UnorderedElementsAre({e0, ..., en})
IsSupersetOf(a_container)
IsSupersetOf(begin, end)
IsSupersetOf(array)
IsSupersetOf(array, count)

// ------- Member Matchers
// for more on FieldsAre, see: https://google.github.io/googletest/reference/matchers.html#member-matchers
Field(&class::field, m)             // arg.field (or arg->field) matches matcher m, where arg is an instance of class
Field(field_name, &class::field, m) // same as above with a better error message
Key(e)                              // arg.first matches e (a value or a matcher)
Pair(m1, m2)                        // arg is an std::pair; first and second matche m1 and m2
FieldsAre(m...)                     // arg is a compatible object where each field matches piecewise with the matchers m...
Property(&class::property, m)       // arg.property() const (or arg->property()) matches matcher m, where arg is an instance of class
Property(prp_name, &class::prp, m)  // same as above with a better error message

// ------- Matching the Result of a Function, Functor, or Callback
ResultOf(f, m)                      // f(arg) matches matcher m, where f is a function or functor

// ------- Pointer Matchers
// for more on Pointer and Pointee, see: https://google.github.io/googletest/reference/matchers.html#pointer-matchers
Address(m)              // the result of std::addressof(arg) matches m
Pointee(m)              // arg (smart pointer or raw pointer) points to a value that matches matcher m
Pointer(m)              // arg (smart pointer or raw pointer) contains a pointer that matches m
WhenDynamicCastTo<T>(m) // when arg is passed through dynamic_cast<T>(), it matches matcher m

// ------- Multi-argument Matchers
Eq()                        // x == y
Ge()                        // x >= y
Gt()                        // x > y
Le()                        // x <= y
Lt()                        // x < y
Ne()                        // x != y
AllArgs(m)                  // equivalent to m; useful as syntactic sugar in .With(AllArgs(m))
Args<N1, N2, ..., Nk>(m)    // tuple of the k selected (0-based indices) arguments matches m, e.g. Args<1, 2>(Eq())

// ------- Composite Matchers
AllOf(m1, m2, ..., mn)      // argument matches all of the matchers m1 to mn.
AllOfArray({m0, ..., mn})   // same as AllOf() except that the matchers come from an initializer list ...
AllOfArray(a_container)     // ... STL-style container ...
AllOfArray(begin, end)      // ... iterator range ...
AllOfArray(array)           // ... C-style array ...
AllOfArray(array, count)    // ... C-style array

AnyOf(m1, m2, ..., mn)      // argument matches at least one of the matchers m1 to mn.
AnyOfArray({m0, ..., mn})   // The same as AnyOf() except that the matchers come from an initializer list ...
AnyOfArray(a_container)     // ... STL-style container ...
AnyOfArray(begin, end)      // ... iterator range ...
AnyOfArray(array)           // ... C-style array ...
AnyOfArray(array, count)    // ... C-style array

Not(m)                      // argument doesn’t match matcher m
Conditional(cond, m1, m2)   // matches matcher m1 if cond evaluates to true, else matches m2

// ------- Adapters for Matchers
MatcherCast<T>(m)       // casts matcher m to type Matcher<T>
SafeMatcherCast<T>(m)   // safely casts matcher m to type Matcher<T>
Truly(predicate)        // predicate(argument) returns something considered by C++ to be true; predicate is a function or functor


// ------- Using Matchers as Predicates
Matches(m)(val)                             // evaluates to true if val matches m; Matches(m) can be used alone as a unary functor
ExplainMatchResult(m, val, result_listener) // evaluates to true if val matches m, explaining the result to result_listener
Value(val, m)                               // evaluates to true if val matches m

// ------- Defining Matchers
MATCHER(IsEven, "") {       // defines a matcher IsEven() to match an even number
    return (arg % 2) == 0;
}
MATCHER_P(IsDivisibleBy, n, "") {                                   // Defines a matcher IsDivisibleBy(n) to match a number divisible by n
    *result_listener << "where the remainder is " << (arg % n);
    return (arg % n) == 0;
}
MATCHER_P2(IsBetween, a, b, absl::StrCat(       // defines a matcher IsBetween(a, b) to match a value in the range [a, b]
    negation ? "isn't" : "is", " between ", PrintToString(a), " and ", PrintToString(b)
)) {
    return a <= arg && arg <= b;
}
