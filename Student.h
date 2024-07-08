//Student Class
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Course.h"

using namespace std;

class Course;

class Student{
    private:
        Course **c;
        friend class SMS;
        string name;
        string ID;
    public:
        //Overloaded constructors
        Student();
        Student(string,string);
        void print_student();
        ~Student();
};

#endif