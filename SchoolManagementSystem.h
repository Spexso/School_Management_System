//School Management System Class
#ifndef SCHOOL_MANAGEMENT_SYSTEM_H
#define SCHOOL_MANAGEMENT_SYSTEM_H
#include <iostream>
#include "Student.h"
#include "Course.h"

using namespace std;

class SMS{
    private:
        Student **students; // Student type pointer array
        Course **courses;   // Course type pointer array
        
        int num_of_s = 0; // Number of Students
        int num_of_c = 0; // Number of Courses
        
        int size_s = 5;    //Number of students that a course include as default
        int size_c = 2;   //Number of courses that a student has as default
        
        void store_student(Student*);
        void store_course(Course*);
        
        char e; //Entry for running menu
        char sub_e; // Entry for inner menus
    public:
        SMS();
        ~SMS();
        void main_menu_text();
        void main_menu();
        
        void stu_menu();
        void course_menu();
        
        void select_student_menu();
        void select_course_menu();
        
        void add_student();
        void add_course();
        
        void set_default_s(int, int);
        void set_default_c(int, int);
        
        void list_students();
        void list_courses();
        
        bool check_list_s();
        bool check_list_c();
        
        bool compare_s(string,int&);
        bool compare_c(string,string,int&);
        
        char sup_pick_mech();
        bool check_valid(char s);
};

#endif