

#include "LoginSystem.h"
#include "Employer.h"
#include "EmployerEditor.h"
#include "EmployerRemover.h"
#include "SearchSystem.h"
#include "DataDisplaySystem.h"

#include <iostream>
#include <string>


void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayWelcome() {
    clearScreen();
    std::cout << "========================================\n";
    std::cout << "     Welcome to Employment Management    \n";
}

void displayMenu() {
    std::cout << "========================================\n";
    std::cout << "1. Add New Employer\n";
    std::cout << "2. Edit Employer Details\n";
    std::cout << "3. Remove Employer\n";
    std::cout << "4. See All Details\n";
    std::cout << "5. Search\n";
    std::cout << "6. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Choose an option:";
}


void addNewEmployer() {
    int id;
    std::string name, email, address, dob, phone, department, position;
    double salary;

    std::cout << "Enter Employer ID: ";
    std::cin >> id;
    std::cin.ignore();  // Ignore leftover newline
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Email: ";
    std::getline(std::cin, email);
    std::cout << "Enter Address: ";
    std::getline(std::cin, address);
    std::cout << "Enter Date of Birth (YYYY-MM-DD): ";
    std::getline(std::cin, dob);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter Department: ";
    std::getline(std::cin, department);
    std::cout << "Enter Position: ";
    std::getline(std::cin, position);
    std::cout << "Enter Salary: ";
    std::cin >> salary;
    std::cin.ignore();

    Employer employer(id, name, email, address, dob, phone, department, position, salary);
    if (employer.validateEmail() && employer.validatePhoneNumber()) {
        if (employer.saveDetails()) {
            std::cout << "Employer added successfully.\n";
        } else {
            std::cout << "Failed to save employer details.\n";
        }
    } else {
        std::cout << "Invalid email or phone number. Please try again.\n";
    }
}
void editEmployerDetails() {
    EmployerEditor editor;
    int id;
    std::cout << "Enter Employer ID to edit: ";
    std::cin >> id;
    std::cin.ignore();  // Ignore leftover newline
    if (!editor.findEmployerById(id)) {
        std::cout << "Employer not found with ID: " << id << "\n";
    }
}

void removeEmployer() {
    EmployerRemover remover;
    int id;
    std::cout << "Enter Employer ID to remove: ";
    std::cin >> id;
    std::cin.ignore();  // Ignore leftover newline
    if (!remover.removeEmployerById(id)) {
        std::cout << "Employer not found with ID: " << id << "\n";
    }
}


int main() {
    LoginSystem ls;
     SearchSystem searchSystem; 
      DataDisplaySystem dataDisplay;
    std::string input;
    std::cout << "Welcome to the Employment Management System\n";
    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
        std::getline(std::cin, input);
        int choice;
        try {
            choice = std::stoi(input);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input, please enter a number.\n";
            continue; // Repeat the loop, asking for input again
        } catch (const std::out_of_range& e) {
            std::cout << "Input is out of range.\n";
            continue;
        }
        switch (choice) {
            case 1:
                ls.registerUser();
                break;
            case 2:
               if (ls.loginUser()) {
    displayWelcome();
    while (true) {
        displayMenu();
        std::getline(std::cin, input);
        int menuChoice;
        try {
            menuChoice = std::stoi(input);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input, please enter a number.\n";
            continue; // Skip the current iteration to ask for input again
        } catch (const std::out_of_range& e) {
            std::cout << "Input is out of range.\n";
            continue;
        }

                        switch (menuChoice) {
                            case 1:
                                addNewEmployer();
                                break;
                            case 2:
                                editEmployerDetails();
                                break;
                            case 3:
                                removeEmployer();
                                break;
                            case 4:
                                 dataDisplay.displayAllEmployers();
                                break;
                            case 5:
                           searchSystem.searchMenu();
                           break;
                            case 6:
                                std::cout << "Exiting...\n";
                                return 0;
                        }
                    }
                } else {
                    std::cout << "Login failed. Please try again or register.\n";
                }
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid option selected. Please try again.\n";
        }
    }
    return 0;
}
