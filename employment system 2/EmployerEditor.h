
#ifndef EMPLOYEREDITOR_H
#define EMPLOYEREDITOR_H

#include "Employer.h"
#include <string>
#include <vector>

class EmployerEditor {
public:
    bool findEmployerById(int id);
    void displayEmployerDetails(const Employer& employer);
    bool updateEmployerDetails(Employer& employer);
    std::vector<std::string> split(const std::string& str, char delimiter);
    Employer parseEmployerDetails(const std::string& line);

private:
    void saveAllEmployers(const std::vector<Employer>& employers);
};

#endif // EMPLOYEREDITOR_H
