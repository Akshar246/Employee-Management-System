#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LoginSystem.h"

TEST_CASE("Email Validation", "[LoginSystem]") {
    LoginSystem loginSystem; // Create an object of LoginSystem
    REQUIRE(loginSystem.validateEmail("test@example.com") == true);
    REQUIRE(loginSystem.validateEmail("invalidemail") == false);
    REQUIRE(loginSystem.validateEmail("another@example") == false); 
}

TEST_CASE("Password Validation", "[LoginSystem]") {
    LoginSystem loginSystem; // Create an object of LoginSystem
    REQUIRE(loginSystem.validatePassword("Password123") == true);
    REQUIRE(loginSystem.validatePassword("short") == false);
    REQUIRE(loginSystem.validatePassword("alllowercase") == false);
}

TEST_CASE("Registration", "[LoginSystem]") {
    LoginSystem loginSystem; 
    // Register a new user
    REQUIRE(loginSystem.saveToCSV("Jimil", "Michael Kors", "mk@gmail.com", loginSystem.encryptPassword("Jimil@2208"), "1") == true);

    // Check if the new user is added to the CSV file
    std::ifstream inFile("company_details.csv");
    std::string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.find("mk@gmail.com") != std::string::npos) {
            found = true;
            break;
        }
    }
    REQUIRE(found == true);
}

TEST_CASE("Login", "[LoginSystem]") {
    LoginSystem loginSystem; 
    // Login with existing user credentials
    REQUIRE(loginSystem.credentialsMatch("h@gmail.com", loginSystem.encryptPassword("@yushJani217"), "10") == false);

    // Login with incorrect password
    REQUIRE(loginSystem.credentialsMatch("h@gmail.com", loginSystem.encryptPassword("wrongpassword"), "10") == false);

    // Login with non-existing user email
    REQUIRE(loginSystem.credentialsMatch("nonexistent@example.com", "password", "10") == false);
}
