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
TEST(TestSuiteName, TestName) {
    // test body
}

TEST_F(TestFixtureName, TestName) {
    // test body
}



// ========================== Assertions Reference

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



// ========================== Assertion Result

testing::AssertionResult IsEven(int n) {
  if ((n % 2) == 0) return testing::AssertionSuccess();         // test should succees
  else return testing::AssertionFailure() << n << " is odd";    // test should fail
}
EXPECT_TRUE(IsEven(3));                                         // will fail with a nice message


// ========================== Matchers
#include "gmock/gmock.h"

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

// ------- Wildcard

using ::testing::AllOf;
using ::testing::Gt;
using ::testing::Lt;
using ::testing::StartsWith;

EXPECT_THAT(value1, StartsWith("Hello"));
ASSERT_THAT(value3, AllOf(Gt(5), Lt(10)));
