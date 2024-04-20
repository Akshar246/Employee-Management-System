// SearchSystem.h
#ifndef SEARCHSYSTEM_H
#define SEARCHSYSTEM_H

#include "Employer.h"
#include <string>
#include <vector>

class SearchSystem {
public:
    void searchMenu();
    void searchById();
    void searchByDepartment();
    std::vector<Employer> loadEmployersFromCSV();
    void displayEmployerDetails(const Employer& employer);
};

#endif // SEARCHSYSTEM_H
