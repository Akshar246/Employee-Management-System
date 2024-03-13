#ifndef LOGIN_H
#define LOGIN_H

#include <string>

bool checkLogin(const std::string& username, const std::string& password);
void displayWelcome();
void clearScreen();
void displayBigWelcome();

#endif // LOGIN_H
