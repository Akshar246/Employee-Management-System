#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "EmployerEditor.h"

TEST_CASE("split method splits string correctly", "[split]") {
    EmployerEditor editor;
    std::string testStr = "1,John Doe,CEO,Company,Email";
    char delimiter = ',';
    std::vector<std::string> result = editor.split(testStr, delimiter);
    REQUIRE(result.size() == 5);
    REQUIRE(result[0] == "1");
    REQUIRE(result[1] == "John Doe");
    REQUIRE(result[2] == "CEO");
    REQUIRE(result[3] == "Company");
    REQUIRE(result[4] == "Email");
}

TEST_CASE("parseEmployerDetails creates correct Employer object", "[parseEmployerDetails]") {
    EmployerEditor editor;
    std::string line = "1,John Doe,CEO,Company,Email";
    Employer employer = editor.parseEmployerDetails(line);
    REQUIRE(employer.getId() == 1);
    REQUIRE(employer.getName() == "John Doe");
    REQUIRE(employer.getTitle() == "CEO");
    REQUIRE(employer.getCompany() == "Company");
    REQUIRE(employer.getEmail() == "Email");
}

TEST_CASE("findEmployerById finds correct Employer", "[findEmployerById]") {
    EmployerEditor editor;
    // Assuming addEmployer function exists to add employers for testing
    editor.addEmployer(Employer(1, "John Doe", "CEO", "Company", "Email"));
    bool found = editor.findEmployerById(1);
    REQUIRE(found == true);
}

TEST_CASE("updateEmployerDetails updates details correctly", "[updateEmployerDetails]") {
    EmployerEditor editor;
    Employer employer(1, "John Doe", "CEO", "Company", "Email");
    employer.setName("Jane Doe");
    bool updated = editor.updateEmployerDetails(employer);
    REQUIRE(updated == true);
    REQUIRE(employer.getName() == "Jane Doe");
}

// Example test for displayEmployerDetails, might need to adjust for actual implementation details
TEST_CASE("displayEmployerDetails outputs correctly", "[displayEmployerDetails]") {
    EmployerEditor editor;
    Employer employer(1, "John Doe", "CEO", "Company", "Email");
    // Capture std::cout output to a string and check if it contains expected details
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    
    editor.displayEmployerDetails(employer);

    std::cout.rdbuf(old); // Reset std::cout to original buffer
    std::string output = buffer.str();
    REQUIRE(output.find("John Doe") != std::string::npos);
    REQUIRE(output.find("CEO") != std::string::npos);
    REQUIRE(output.find("Company") != std::string::npos);
    REQUIRE(output.find("Email") != std::string::npos);
}
