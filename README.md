# Employee Management System (EMS)

## Overview
The Employee Management System (EMS) is a C++ application designed to help organizations manage their employee records. With functionalities such as adding, editing, searching, and removing employee details, the EMS simplifies the task of maintaining up-to-date information for HR departments.

## Features
- **Registration and Login**: Secure access control for administrators.
- **Employee Record Management**: Add, edit, and remove employee records.
- **Search Functionality**: Locate employee details using IDs or department names.
- **Data Storage**: Employee information is stored in CSV format for persistence and ease of access.
- **Automated HR Operations**: Automated features reduce manual HR tasks.

## Technologies Used
- C++ for core backend development.
- Cygwin as a Linux-like environment for Windows.
- Visual Studio Code as an integrated development environment (IDE).
- Git for version control, with GitHub as the remote repository.
- Makefile and CMake for build automation.
- Catch2 for unit testing.

## Getting Started

### Prerequisites
- Ensure you have a C++ compiler installed, such as `g++` or `clang`.
- Install Cygwin (for Windows users) or ensure you have a terminal available (for Linux/macOS users).
- Install Visual Studio Code or your preferred IDE that supports C++ development.
- Install Git to clone the repository.

### Installation
1. Clone the repository using Git:

git clone https://github.com/yourusername/EMS.git

2. Navigate to the cloned repository:


### Building the Application
Run the following command in the root directory of the project to build the EMS application:

make all

./employee_system

### For Testing
make test
