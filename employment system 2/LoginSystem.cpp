#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <locale>

#include "LoginSystem.h"

// Helper function to trim whitespace from both ends of a string
static inline std::string trim(const std::string &s) {
    auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c) {return std::isspace(c); });
    auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) {return std::isspace(c); }).base();
    return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

bool LoginSystem::validateEmail(const std::string& email) {
std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, pattern);
}

bool LoginSystem::validatePassword(const std::string& password) {
    return password.length() >= 8 && std::any_of(password.begin(), password.end(), ::isdigit) &&
           std::any_of(password.begin(), password.end(), ::isupper);
}

std::string LoginSystem::encryptPassword(const std::string& password) {
    // Simple hash for demonstration (not secure)
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}

bool LoginSystem::saveToCSV(const std::string& ownerName, const std::string& companyName, 
                            const std::string& email, const std::string& encryptedPassword, const std::string& securityCode) {
    std::ofstream file("company_details.csv", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open company_details.csv for writing.\n";
        return false;
    }
    file << ownerName << "," << companyName << "," << email << "," << encryptedPassword << "," << securityCode << "\n";
    if (file.fail()) {
        std::cerr << "Error: Failed to write data to company_details.csv.\n";
        return false;
    }
    file.close();
    if (file.fail()) {
        std::cerr << "Error: Failed to close company_details.csv.\n";
        return false;
    }
    return true;
}

bool LoginSystem::credentialsMatch(const std::string& email, const std::string& password, const std::string& securityCode) {
    std::ifstream file("company_details.csv");
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string ownerName, companyName, storedEmail, storedPassword, storedSecurityCode;
        std::getline(iss, ownerName, ',');
        std::getline(iss, companyName, ',');
        std::getline(iss, storedEmail, ',');
        std::getline(iss, storedPassword, ',');
        std::getline(iss, storedSecurityCode, ',');

        if (storedEmail == email && encryptPassword(password) == storedPassword && storedSecurityCode == securityCode) {
            return true;
        }
    }
    file.close();
    return false;
}


void LoginSystem::registerUser() {
    std::string ownerName, companyName, email, password, confirmPassword, securityCode;
    std::cout << "Enter owner name: ";
    std::getline(std::cin, ownerName);
    ownerName = trim(ownerName);
    
    std::cout << "Enter company name: ";
    std::getline(std::cin, companyName);
    companyName = trim(companyName);
    
    std::cout << "Enter company email: ";
    std::getline(std::cin, email);
    email = trim(email);
    
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    password = trim(password);
    
    std::cout << "Confirm password: ";
    std::getline(std::cin, confirmPassword);
    confirmPassword = trim(confirmPassword);
    
    std::cout << "Enter security code: ";
    std::getline(std::cin, securityCode);
    securityCode = trim(securityCode);

    if (!validateEmail(email)) {
        std::cout << "Invalid email format.\n";
        return;
    }
    if (password != confirmPassword) {
        std::cout << "Passwords do not match.\n";
        return;
    }
    if (!validatePassword(password)) {
        std::cout << "Password must be at least 8 characters long, include one uppercase letter and one number.\n";
        return;
    }

    std::string encryptedPassword = encryptPassword(password);
    if (saveToCSV(ownerName, companyName, email, encryptedPassword, securityCode)) {
        std::cout << "Registration successful.\n";
    } else {
        std::cout << "Error saving data.\n";
    }
}

bool LoginSystem::loginUser() {
    std::string email, password, securityCode;
    std::cout << "Enter company email: ";
    std::getline(std::cin, email);
    email = trim(email);
    
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    password = trim(password);
    
    std::cout << "Enter security code: ";
    std::getline(std::cin, securityCode);
    securityCode = trim(securityCode);
    

    if (credentialsMatch(email, password, securityCode)) {
        return true;
    }
    std::cout << "Invalid credentials or user does not exist.\n";
    return false;
}
