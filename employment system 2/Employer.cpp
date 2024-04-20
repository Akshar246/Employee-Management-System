
#include "Employer.h"


#include <fstream>
#include <regex>

Employer::Employer(int id, const std::string& name, const std::string& email, const std::string& address, 
const std::string& dob, const std::string& phone, const std::string& department, 
const std::string& position, double salary) 
    : id(id), name(name), email(email), address(address), dob(dob), phone(phone), department(department), position(position), salary(salary) {}

bool Employer::validateEmail() const {
    std::regex pattern(R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)");
    return std::regex_match(email, pattern);
}

bool Employer::validatePhoneNumber() const {
    std::regex pattern(R"(^\+?\d{10,15}$)");  // Validates international phone numbers with optional +
    return std::regex_match(phone, pattern);
}

bool Employer::saveDetails() const {
    std::ofstream file("employers.csv", std::ios::app);
    if (!file) return false;
    file << id << "," << name << "," << email << "," << address << "," << dob << "," 
         << phone << "," << department << "," << position << "," << salary << "\n";
    file.close();
    return true;
}
// Getters
int Employer::getId() const { return id; }
std::string Employer::getName() const { return name; }
std::string Employer::getEmail() const { return email; }
std::string Employer::getAddress() const { return address; }
std::string Employer::getDob() const { return dob; }
std::string Employer::getPhone() const { return phone; }
std::string Employer::getDepartment() const { return department; }
std::string Employer::getPosition() const { return position; }
double Employer::getSalary() const { return salary; }

// Setters
void Employer::setName(const std::string& newName) { name = newName; }
void Employer::setEmail(const std::string& newEmail) { email = newEmail; }
void Employer::setAddress(const std::string& newAddress) { address = newAddress; }
void Employer::setDob(const std::string& newDob) { dob = newDob; }
void Employer::setPhone(const std::string& newPhone) { phone = newPhone; }
void Employer::setDepartment(const std::string& newDepartment) { department = newDepartment; }
void Employer::setPosition(const std::string& newPosition) { position = newPosition; }
void Employer::setSalary(double newSalary) { salary = newSalary; }
