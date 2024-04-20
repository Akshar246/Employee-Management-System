#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include <string>
#include <iostream>

class LoginSystem {
public:
    bool validateEmail(const std::string& email);
    bool validatePassword(const std::string& password);
    bool saveToCSV(const std::string& ownerName, const std::string& companyName, 
                   const std::string& email, const std::string& encryptedPassword, const std::string& securityCode);
    bool credentialsMatch(const std::string& email, const std::string& password, const std::string& securityCode);
    std::string encryptPassword(const std::string& password);
    void registerUser();
    bool loginUser();
};

#endif
