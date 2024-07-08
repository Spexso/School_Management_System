#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

const int default_num_s = 5;

Course::Course() : name{"None"}, code{"0"}{
    s = new Student*[default_num_s];
}

Course::Course(string n, string code){
    name = n;
    this->code = code;
}


void Course::print_course(){
    //cout << "Name of the course: " << this->name << endl;
    //cout << "Code of the course: " << this->code << endl << endl;
}

Course::~Course(){
    //cout << "Course object destructed" << endl;
}