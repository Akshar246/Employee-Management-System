#include <iostream>
#include "login.h"

int main() {
    std::string username, password;
    int loginAttempts = 0;
    
    displayWelcome(); // Show welcome message

    while (loginAttempts < 3) {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        if (checkLogin(username, password)) {
            displayBigWelcome(); 
            std::cout << "\nLogin successful. Welcome to the system!" << std::endl;
            // Place the rest of your application logic here.
            break; // Exit the loop if login is successful
        } else {
            std::cout << "Login failed. Please try again." << std::endl;
            loginAttempts++;
            if (loginAttempts == 3) {
                std::cout << "Maximum login attempts exceeded. Access denied." << std::endl;
            }
        }
    }

    return 0;
}
