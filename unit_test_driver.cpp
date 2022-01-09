
/*
    unit_test_driver.cpp
    Matt Russell
    COMP15 2020 Summer
    Updated 12/16/2020

    This file is used by the unit_test script for automatic testing.

    Specifically, function headers for the tests and the 'tests' map
    will be auto-populated from the functions in the student's
    XX_tests.cpp file

    This file, while necessary for compilation / running of the
    automated tests, is created in the students working directory
    automatically, and is removed upon completion of the tests.
*/

#include <map>
#include <string>

typedef void (*FnPtr)();
void BST_default_constructor();
void BST_insert_constructor();
// Forward declarations of the testing functions will be inserted here


int main(int argc, char **argv) {

    // will be filled in by the unit_test script
    std::map<std::string, FnPtr> tests {
	{ "BST_default_constructor" , BST_default_constructor },
	{ "BST_insert_constructor" , BST_insert_constructor },

    };

    /*
     * 1st argument to main is the string of a function name -- extract the
     * associated function pointer from "tests", and run the test
     */
    FnPtr fn = tests[argv[1]];
    fn();
    
    (void)argc; // remove unused argc warning

    return 0;
}
