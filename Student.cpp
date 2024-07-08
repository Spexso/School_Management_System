#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

const int default_num_c = 2;

Student::Student(): name{"None"}, ID{"0"}{
    c = new Course*[default_num_c];
}

Student::Student(string n, string ID){
    name = n;
    this->ID = ID;
}

void Student::print_student(){
    //cout <<"Name of the student: " << this->name << endl;
    //cout << "And number of student: " << this->ID << endl << endl;
}

Student::~Student(){
    //cout << "Student object destructed" << endl;
}