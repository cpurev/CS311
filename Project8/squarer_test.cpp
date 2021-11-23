// squarer_test.cpp  SKELETON
// Glenn G. Chappell
// 2021-11-19
//
// For CS 311 Fall 2021
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
    "class Squarer"
    " - CS 311 Proj 8, Ex B";


// *********************************************************************
// Test Cases
// *********************************************************************

TEST_CASE("Squarer: const & non-const object"){
    int arg = 2;
    int result = 4;

    SUBCASE("Const test"){
        const Squarer sq;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Non-const test"){
        Squarer sq;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}


TEST_CASE("Squarer: wide range of values"){
    Squarer sq;
    int arg;
    int result;

    SUBCASE("Square of 5"){
        arg = 5;
        result = 25;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of 10"){
        arg = 10;
        result = 100;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of 10000"){
        arg = 10000;
        result = 100000000;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of 999"){
        arg = 999;
        result = 998001;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of 43543"){
        arg = 43543;
        result = 1895992849;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}


TEST_CASE("Squarer: negative ints")
{
    Squarer sq;
    int arg;
    int result;

    SUBCASE("Square of -5"){
        arg = -5;
        result = 25;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of -10"){
        arg = -10;
        result = 100;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of -10000"){
        arg = -10000;
        result = 100000000;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of -999"){
        arg = -999;
        result = 998001;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of -43543"){
        arg = -43543;
        result = 1895992849;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}


TEST_CASE("Squarer: floating-points"){
    Squarer sq;
    double arg;
    double result;

    SUBCASE("Square of pi"){
        arg = 3.14159265359;
        result = 9.8696044011;
        INFO(arg << " squared is " << doctest::Approx(result));
        REQUIRE(sq(arg) == doctest::Approx(result));
    }

    SUBCASE("Square of 1.1"){
        arg = 1.1;
        result = 1.21;
        INFO(arg << " squared is " << doctest::Approx(result));
        REQUIRE(sq(arg) == doctest::Approx(result));
    }

    SUBCASE("Square of 0.5"){
        arg = 0.5;
        result = 0.25;
        INFO(arg << " squared is " << doctest::Approx(result));
        REQUIRE(sq(arg) == doctest::Approx(result));
    }

    SUBCASE("Square of 1284.234"){
        arg = 1284.234;
        result = 1649256.96676;
        INFO(arg << " squared is " << doctest::Approx(result));
        REQUIRE(sq(arg) == doctest::Approx(result));
    }
}


TEST_CASE("Squarer: SPECIAL CASES"){
    Squarer sq;
    int arg;
    int result;

    SUBCASE("Square of 0"){
        arg = 0;
        result = 0;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of 1"){
        arg = 1;
        result = 1;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }

    SUBCASE("Square of -1"){
        arg = -1;
        result = 1;
        INFO(arg << " squared is " << result);
        REQUIRE(sq(arg) == result);
    }
}
// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}
