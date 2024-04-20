#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "SearchSystem.h"


TEST_CASE("Search by ID") {
    SearchSystem searchSystem;

    
    std::stringstream input;
    input << "1\n"; // Simulate the user entering "1" to search by ID also you can change it 
    std::cin.rdbuf(input.rdbuf()); 
    REQUIRE_NOTHROW(searchSystem.searchById());
}


TEST_CASE("Search by Department") {
    SearchSystem searchSystem;
    std::stringstream input;
    input << "it\n";
    std::cin.rdbuf(input.rdbuf()); 
    REQUIRE_NOTHROW(searchSystem.searchByDepartment()); 
}


