#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DataDisplaySystem.h"


// Define test case for displaying all employers
TEST_CASE("Display all employers") {
   // Create an instance of the DataDisplaySystem class
    DataDisplaySystem dataDisplaySystem;

     // Call the displayAllEmployers() function
    REQUIRE_NOTHROW(dataDisplaySystem.displayAllEmployers()); 
}
