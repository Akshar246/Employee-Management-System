#include "login.h"
#include <iostream>

// Assuming these are the correct credentials.
const std::string correctUsername = "admin";
const std::string correctPassword = "password123";

bool checkLogin(const std::string& username, const std::string& password) {
    return username == correctUsername && password == correctPassword;
}

void displayWelcome() {
    // Display a welcome message with a simple design
    std::cout << "========================================\n";
    std::cout << " Welcome to the Employment System\n";
    std::cout << "========================================\n";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayBigWelcome() {
    clearScreen(); // Clear the screen after successful login
    std::cout << "\n\n========================================\n";
    std::cout << "      Employment Management System      \n";
    std::cout << "========================================\n\n";
}
