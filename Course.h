//Course Class
#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Student;

class Course{
    private:
        Student **s;
        friend class SMS;
        string name;
        string code;
    public:
        //Overloaded constructors
        Course();
        Course(string,string);
        void print_course();
        ~Course();
};

#endif