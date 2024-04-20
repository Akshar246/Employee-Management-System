#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <string>

class Employer {
public:
    Employer(int id, const std::string& name, const std::string& email, const std::string& address, 
             const std::string& dob, const std::string& phone, const std::string& department, 
             const std::string& position, double salary);

    bool validateEmail() const;
    bool validatePhoneNumber() const;
    bool saveDetails() const;
    // Getters
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getAddress() const;
    std::string getDob() const;
    std::string getPhone() const;
    std::string getDepartment() const;
    std::string getPosition() const;
    double getSalary() const;

    // Setters
    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setAddress(const std::string& address);
    void setDob(const std::string& dob);
    void setPhone(const std::string& phone);
    void setDepartment(const std::string& department);
    void setPosition(const std::string& position);
    void setSalary(double salary);


private:
    int id;
    std::string name;
    std::string email;
    std::string address;
    std::string dob;
    std::string phone;
    std::string department;
    std::string position;
    double salary;
};

#endif
