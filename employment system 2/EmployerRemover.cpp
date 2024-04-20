#include "EmployerRemover.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "utility.h" 




bool EmployerRemover::removeEmployerById(int id) {
    std::ifstream file("employers.csv");
    std::vector<std::string> lines;
    std::string line;
    bool found = false;

    while (std::getline(file, line)) {
        std::vector<std::string> data = Utility::split(line, ',');
        if (std::stoi(data[0]) != id) {
            lines.push_back(line);
        } else {
            found = true; // Mark as found but do not add to the new lines vector
        }
    }
    file.close();
  

    if (!found) {
        std::cout << "Invalid ID, no employer found.\n";
        return false;
    }

    // Rewrite the file without the removed employer
    std::ofstream outfile("employers.csv", std::ios::trunc);
    for (const auto& new_line : lines) {
        outfile << new_line << std::endl;
    }
    outfile.close();
    std::cout << "Employer removed successfully.\n";
    return true;
}
