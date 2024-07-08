# Variables
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11
CXXFLAGS = -Wall -Wextra -std=c++11

# Target and its dependencies
all: SchoolManagementSystem

SchoolManagementSystem: main.cpp Course.cpp Student.cpp SchoolManagementSystem.cpp   
	$(CXX) $(CXXFLAGS) -o SchoolManagementSystem main.cpp Course.cpp Student.cpp SchoolManagementSystem.cpp 

# Clean target to remove all compiled files
clean:
	rm -f SchoolManagementSystem
	rm -f *.o

