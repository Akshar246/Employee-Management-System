// DataDisplaySystem.h
#ifndef DATADISPLAYSYSTEM_H
#define DATADISPLAYSYSTEM_H

#include "Employer.h"
#include <vector>
#include <string>

class DataDisplaySystem {
public:
    void displayAllEmployers();
    void displayFooter(int totalEmployers); 
private:
    std::vector<Employer> loadAndSortEmployers();
    void displayTableHeader();
    void displayEmployer(const Employer& employer);
};

#endif // DATADISPLAYSYSTEM_H
