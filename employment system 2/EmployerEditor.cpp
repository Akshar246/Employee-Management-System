// EmployerEditor.cpp
#include "EmployerEditor.h"
#include "utility.h"

#include <fstream>
#include <iomanip>
#include <iostream>

std::vector<std::string> EmployerEditor::split(const std::string& str, char delimiter) {
    return Utility::split(str, delimiter);
}

Employer EmployerEditor::parseEmployerDetails(const std::string& line) {
    std::vector<std::string> tokens = split(line, ',');
    return Employer(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3], tokens[4],
                    tokens[5], tokens[6], tokens[7], std::stod(tokens[8]));
}

bool EmployerEditor::findEmployerById(int id) {
    std::ifstream file("employers.csv");
    std::string line;
    std::vector<Employer> employers;
    bool found = false;

    while (std::getline(file, line)) {
        Employer employer = parseEmployerDetails(line);
        if (employer.getId() == id) {
            displayEmployerDetails(employer);
            updateEmployerDetails(employer);
            found = true;
        }
        employers.push_back(employer);
    }
    file.close();

    if (!found) {
        std::cout << "Invalid ID, no employer found.\n";
        return false;
    }
    saveAllEmployers(employers);
    return true;
}

void EmployerEditor::displayEmployerDetails(const Employer& employer) {
    std::cout << "========================================\n";
    std::cout << "Employer Details:\n";
    std::cout << "========================================\n";
    std::cout << std::left << std::setw(15) << "ID: " << employer.getId() << "\n";
    std::cout << std::left << std::setw(15) << "Name: " << employer.getName() << "\n";
    std::cout << std::left << std::setw(15) << "Email: " << employer.getEmail() << "\n";
    std::cout << std::left << std::setw(15) << "Address: " << employer.getAddress() << "\n";
    std::cout << std::left << std::setw(15) << "DOB: " << employer.getDob() << "\n";
    std::cout << std::left << std::setw(15) << "Phone: " << employer.getPhone() << "\n";
    std::cout << std::left << std::setw(15) << "Department: " << employer.getDepartment() << "\n";
    std::cout << std::left << std::setw(15) << "Position: " << employer.getPosition() << "\n";
    std::cout << std::left << std::setw(15) << "Salary: $" << employer.getSalary() << "\n";
    std::cout << "========================================\n";
    std::cout << "Select detail to edit (1-Name, 2-Email, 3-Address, 4-DOB, 5-Phone, 6-Department, 7-Position, 8-Salary): ";
}

bool EmployerEditor::updateEmployerDetails(Employer& employer) {
    int choice;
    std::cin >> choice;
    std::cin.ignore();  // To consume the leftover newline character
    std::string input;
    double newSalary;
    
    switch (choice) {
        case 1:
            std::cout << "Enter new Name: ";
            std::getline(std::cin, input);
            employer.setName(input);
            break;
        case 2:
            std::cout << "Enter new Email: ";
            std::getline(std::cin, input);
            employer.setEmail(input);
            break;
        case 3:
            std::cout << "Enter new Address: ";
            std::getline(std::cin, input);
            employer.setAddress(input);
            break;
        case 4:
            std::cout << "Enter new DOB (YYYY-MM-DD): ";
            std::getline(std::cin, input);
            employer.setDob(input);
            break;
        case 5:
            std::cout << "Enter new Phone: ";
            std::getline(std::cin, input);
            employer.setPhone(input);
            break;
        case 6:
            std::cout << "Enter new Department: ";
            std::getline(std::cin, input);
            employer.setDepartment(input);
            break;
        case 7:
            std::cout << "Enter new Position: ";
            std::getline(std::cin, input);
            employer.setPosition(input);
            break;
        case 8:
            std::cout << "Enter new Salary: ";
            std::cin >> newSalary;
            employer.setSalary(newSalary);
            break;
        default:
            std::cout << "Invalid option.\n";
            return false;
    }
    return true;
}

void EmployerEditor::saveAllEmployers(const std::vector<Employer>& employers) {
    std::ofstream file("employers.csv", std::ios::trunc);
    for (const Employer& employer : employers) {
        file << employer.getId() << "," << employer.getName() << "," << employer.getEmail() << ","
             << employer.getAddress() << "," << employer.getDob() << "," << employer.getPhone() << ","
             << employer.getDepartment() << "," << employer.getPosition() << "," << employer.getSalary() << "\n";
    }
    file.close();
}
