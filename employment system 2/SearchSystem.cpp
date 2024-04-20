// SearchSystem.cpp
#include "SearchSystem.h"
#include "utility.h"
#include <fstream>
#include <iostream>
#include <sstream>

void SearchSystem::searchMenu() {
    std::string input;
    int choice;
    while (true) {
        std::cout << "Search Menu:\n";
        std::cout << "1. Search by Employer ID\n";
        std::cout << "2. Search by Department\n";
        std::cout << "3. Back\n";
        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid input, please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                searchById();
                break;
            case 2:
                searchByDepartment();
                break;
            case 3:
                return; // Exits the search menu
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }
}

void SearchSystem::searchById() {
    int id;
    std::string input;
    std::cout << "Enter Employer ID to search: ";
    std::getline(std::cin, input);
    try {
        id = std::stoi(input);
    } catch (...) {
        std::cout << "Invalid input, please enter a valid number.\n";
        return;
    }

    auto employers = loadEmployersFromCSV();
    bool found = false;
    for (const auto& employer : employers) {
        if (employer.getId() == id) {
            displayEmployerDetails(employer);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Invalid ID, no employer found.\n";
    }
}

void SearchSystem::searchByDepartment() {
    std::string department;
    std::cout << "Enter Department to search: ";
    std::getline(std::cin, department);

    auto employers = loadEmployersFromCSV();
    bool found = false;
    for (const auto& employer : employers) {
        if (employer.getDepartment() == department) {
            displayEmployerDetails(employer);
            found = true;
        }
    }
    if (!found) {
        std::cout << "No employers found in this department.\n";
    }
}

std::vector<Employer> SearchSystem::loadEmployersFromCSV() {
    std::vector<Employer> employers;
    std::ifstream file("employers.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> data = Utility::split(line, ',');
        employers.push_back(Employer(std::stoi(data[0]), data[1], data[2], data[3], data[4],
                                     data[5], data[6], data[7], std::stod(data[8])));
    }
    file.close();
    return employers;
}

void SearchSystem::displayEmployerDetails(const Employer& employer) {
    std::cout << "\n-------------------------------------------------\n";
    std::cout << "Employer Details:\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "ID: " << employer.getId() << "\n\n";
    std::cout << "Name: " << employer.getName() << "\n\n";
    std::cout << "Email: " << employer.getEmail() << "\n\n";
    std::cout << "Address: " << employer.getAddress() << "\n\n";
    std::cout << "DOB: " << employer.getDob() << "\n\n";
    std::cout << "Phone: " << employer.getPhone() << "\n\n";
    std::cout << "Department: " << employer.getDepartment() << "\n\n";
    std::cout << "Position: " << employer.getPosition() << "\n\n";
    std::cout << "Salary: $" << employer.getSalary() << "\n";
    std::cout << "-------------------------------------------------\n\n";
}
