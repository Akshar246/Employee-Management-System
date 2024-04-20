// DataDisplaySystem.cpp
#include "DataDisplaySystem.h"
#include "utility.h"
#include <fstream>
#include <iostream>
#include <algorithm> // For std::sort
#include <iomanip>

void DataDisplaySystem::displayAllEmployers() {
    auto employers = loadAndSortEmployers();
    displayTableHeader();
    for (const auto& employer : employers) {
        displayEmployer(employer);
    }
    displayFooter(employers.size());
}

std::vector<Employer> DataDisplaySystem::loadAndSortEmployers() {
    std::vector<Employer> employers;
    std::ifstream file("employers.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> data = Utility::split(line, ',');
        employers.emplace_back(std::stoi(data[0]), data[1], data[2], data[3], data[4],
                                data[5], data[6], data[7], std::stod(data[8]));
    }
    file.close();

    // Sort employers by ID in ascending order
    std::sort(employers.begin(), employers.end(), 
              [](const Employer& a, const Employer& b) { 
                  return a.getId() < b.getId(); 
              });

    return employers;
}

void DataDisplaySystem::displayTableHeader() {
    std::cout << std::endl; // Adds an extra line break for spacing after choosing an option
    std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(5) << "ID" << std::setw(20) << "Name" << std::setw(30) << "Email"
              << std::setw(15) << "Phone" << std::setw(20) << "Department" << std::setw(15) << "Position" 
              << std::setw(10) << "Salary" << "\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
}


void DataDisplaySystem::displayEmployer(const Employer& employer) {
    std::cout << std::setw(5) << employer.getId()
              << std::setw(20) << employer.getName()
              << std::setw(30) << employer.getEmail()
              << std::setw(15) << employer.getPhone()
              << std::setw(20) << employer.getDepartment()
              << std::setw(15) << employer.getPosition()
              << std::setw(10) << std::fixed << std::setprecision(2) << employer.getSalary() << "\n";
}

void DataDisplaySystem::displayFooter(int totalEmployers) {
    std::cout << "-------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "Total Employers: " << totalEmployers << "\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------\n\n"; // Adds an additional line for separation after the total
}
