# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source files and output executable
SOURCES = DataDisplaySystem.cpp EmployerEditor.cpp EmployerRemover.cpp \
		LoginSystem.cpp SearchSystem.cpp Employer.cpp utility.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = employment_system

# Test sources and executables
TEST_SOURCES = LoginSystemTest.cpp DataDisplaySystemTest.cpp SearchSystemTest.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_EXECUTABLES = $(TEST_SOURCES:.cpp=TestExecutable)

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

# Compile object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Explicit rule for Utility.o
Utility.o: Utility.cpp
	$(CXX) $(CXXFLAGS) -c Utility.cpp -o Utility.o

# Test targets
login_test: LoginSystemTest.o LoginSystem.o Utility.o
	$(CXX) $(LDFLAGS) -o loginTestExecutable LoginSystemTest.o LoginSystem.o Utility.o

data_display_test: DataDisplaySystemTest.o DataDisplaySystem.o Employer.o Utility.o
	$(CXX) $(LDFLAGS) -o dataDisplayTestExecutable DataDisplaySystemTest.o DataDisplaySystem.o Employer.o Utility.o

search_system_test: SearchSystemTest.o SearchSystem.o Employer.o Utility.o
	$(CXX) $(LDFLAGS) -o searchSystemTestExecutable SearchSystemTest.o SearchSystem.o Employer.o Utility.o

# Clean up
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(addsuffix TestExecutable, $(TEST_EXECUTABLES))

.PHONY: all clean login_test data_display_test search_system_test
