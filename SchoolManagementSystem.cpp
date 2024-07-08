#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "SchoolManagementSystem.h"
using namespace std;

const int default_count = 5;    //Number of students and courses that School Management System has
const int default_size_s = 1;   //default student pointer count 
const int default_size_c = 2;   //default course pointer count              

bool SMS::check_valid(char s)
{
    bool res;
    switch(s)
    {
        case '0':
            res = true;
            break;
        case '1':
            res = true;
            break;
        case '2':
            res = true;
            break;
        case '3':
            res = true;
            break;
        case '4':
            res = true;
            break;
        default:
            res = false;
            break;
    }
    cin.clear();
    cin.ignore(100, '\n');
    return res;
}

void SMS::main_menu()
{
    string temp_n;  //Temporary name string for course
    string temp_c;  //Temporary code string for course
    
    int e_list;     //Int variable to pick from available courses list
    
    int curr_size_c = default_size_c;
    int curr_size_s = default_size_s;
    
    int num_c = 0;      //Counts the number of courses that a student take
    
    int temp_s_indx[10]{-1};
    int temp_c_indx[10]{-1};
    int temp_indx;
    
    int count_c_arr=0;      //Counts for course array
    int count_s_arr=0;      //Counts for student array
    
    bool prev_occ = false;  // Checks if the courses has taken previously
    bool found = false;     // Represents Empty pointers that can point to a course 
    int prev_occ_c = 0;     // Counts the previously occured courses
    
    string temp;
    int c = 1;          //Variable to count as text
    
    int index{0};
    int cou_index_1{0};
    int cou_index_2{0};
    
    string inp;             //input to hold entry
    string c_inp_c;
    string c_inp_n;
    
    do
    {
        main_menu_text();
        cin >> e;
        while(check_valid(e) == false)
        {
            main_menu_text();
            cin >> e;
        }
        switch(e)
        {
            case '0':
                //Exit condition
                break;
            
            case '1':               
                do
                {
                    stu_menu();
                    sub_e = sup_pick_mech();
                    
                    if(sub_e == '1')
                    {
                        //Add student by entering Student name and ID
                        add_student();
                        
                    }
                    else if(sub_e == '2')
                    {
                        //Enter student name and ID to select student
                        getline(cin, inp);
                        if(compare_s(inp, index) == true)
                        {
                                select_student_menu();
                                cin >> sub_e;
                            
                                while(check_valid(sub_e) == false)
                                {
                                    select_student_menu();
                                    cin >> sub_e;
                                }
                        
                            if(sub_e == '1')
                            {
                                //Delete student
                                delete students[index]; 
                                students[index] = new Student();
                                sub_e = 'h'; // To keep iteration of student menu 
                            }
                            else if(sub_e == '3')
                            {
                                //add student to a course
                                //find student's index
                                //index variable holds it
                                //Increases the number of courses that has taken by selected student
                                 curr_size_c +=1;
                                 Course** temp = new Course*[curr_size_c];
                                 for(int k=0; k < curr_size_c; k++)
                                 {
                                     temp[k] = students[index]->c[k];
                                 }
                                 delete[] students[index]->c;
                                 students[index]->c = temp;
                                 
                                        for(int k=0; k < num_of_c;k++)
                                        {
                                            if(!(courses[k]->name == "None" && courses[k]->code == "0"))
                                            {
                                                
                                                for(int i=0; i < curr_size_c; i++)
                                                {
                                                    if(students[index]->c[i] == courses[k] && students[index]->c[i] != NULL)
                                                    {
                                                        prev_occ = true;
                                                        prev_occ_c++;
                                                    }
                                                    
                                                    if(students[index]->c[i] != courses[k] && students[index]->c[i] == NULL && prev_occ == false)
                                                    {
                                                            temp_indx = i; //Holds the first empty pointer for assingable courses
                                                            found = true;
                                                            i = curr_size_c;
                                                    }
                                                    
                                                }
                                            }
                                            if(found == true)
                                            {
                                                cout << c++ << " " << courses[k]->code << " " << courses[k]->name << endl;
                                                temp_c_indx[count_c_arr++] = k;
                                                found = false;
                                            }
                                            prev_occ = false;
                                        }
                                        c = 1;
                                        if(prev_occ_c != num_of_c || num_of_c != 0)
                                        {
                                            cin >> e_list;
                                        
                                            //index of student
                                            //course picked
                                            
                                            if(e_list > 0 && !(e_list > num_c))
                                            {
                                                students[index]->c[temp_indx] = courses[temp_c_indx[e_list-1]];
                                                
                                                for(int x=0; x < curr_size_s; x++)
                                                {
                                                    if(courses[temp_c_indx[e_list-1]]->s[x] == NULL)
                                                    {
                                                        //Increase the number of students that a course could include
                                                         curr_size_s +=1;
                                                         Student** temp = new Student*[curr_size_s];
                                                         for(int k=0; k < curr_size_s; k++)
                                                         {
                                                             temp[k] = courses[temp_c_indx[e_list-1]]->s[k];
                                                         }
                                                         delete[] courses[temp_c_indx[e_list-1]]->s;                    //Deletes the previous one
                                                         courses[temp_c_indx[e_list-1]]->s = temp;
                                                        
                                                        courses[temp_c_indx[e_list-1]]->s[x] = students[index];
                                                        x = curr_size_s;
                                                    }
                                                }
                                                
                                            }
                                            else
                                              sub_e = 'h';
                                        }
  
                                        c = 1;
                                        count_c_arr = 0;
                                        prev_occ = false;
                                        prev_occ_c = 0;
                            }
                            else if(sub_e == '4')               //Drop student
                            {
                                while(students[index]->c[c+1] != NULL && students[index]->c[c+1]->name !="None" && students[index]->c[c+1]->name !="0")
                                {
                                    num_c++;
                                }
                                num_c++;
                                c = 1;
                                
                                for(int f=0; f < num_c;f++)
                                {
                                    cout << c++ << " " << students[index]->c[f]->code << " " << students[index]->c[f]->name << endl;            //Finds the student
                                    temp_s_indx[count_s_arr++] = f; 
                                }
                                
                                cin >> e_list;
                                if(e_list > 0 && e_list <= num_c)
                                {
                                    for(int k=0; k < num_of_c;k++)
                                    {
                                        for(int m=0; m < curr_size_s; m++)
                                        {
                                            if(courses[k]->s[m] != NULL && courses[k]->s[m] != NULL)
                                            {
                                                if(courses[k]->name == students[index]->c[temp_s_indx[e_list-1]]->name && students[index]->c[temp_s_indx[e_list-1]]->code == courses[k]->code)
                                                {
                                                    cou_index_1 = k;            //Finds the course that selected
                                                    cou_index_2 = m;            //Finds the course that selected
                                                }
                                                if(courses[k]->s[m]->name == students[index]->name && students[index]->ID == courses[k]->s[m]->ID)
                                                {
                                                    cou_index_2 = m;
                                                }
                                            }
                                            
                                        }
                                        
                                    }
                                    students[index]->c[temp_s_indx[e_list-1]] = NULL;
                                    
                                    courses[cou_index_1]->s[cou_index_2] = NULL;
                                
                                }
                                else
                                {
                                   //Wrong input
                                   sub_e = 'h'; 
                                }
                                count_s_arr = 0;
                                c = 1;
                              
                            }

                        }
                        else if(check_list_s() == true)
                        {
                            //There are no students 
                        }
                        else
                        {
                            //No such student
                        }
                                
                    }
                    else
                    {
                        sub_e = ' ';
                        // 0 condition, go back to main menu    
                    }
                }while(sub_e == 'h');
                
                break;
            
            case '2':
            do
            {
                course_menu();
                sub_e = sup_pick_mech();
                    if(sub_e == '1')
                    {
                        //Add course by entering course name and code
                        add_course();
                    }
                    else if(sub_e == '2')
                    {
                        //Select course by entering course name and code
                        //Get the course code 
                        getline(cin, c_inp_c, ' ');
                        //Get the name of the course next
                        getline(cin, c_inp_n);
                        
                        
                        if(compare_c(c_inp_c, c_inp_n, index) == true)
                        {
                            select_course_menu();
                            cin >> sub_e;
                                
                                while(check_valid(sub_e) == false)
                                {
                                    select_course_menu();
                                    cin >> sub_e;
                                }
                                
                            if(sub_e == '1')
                            {
                                //delete course
                                delete courses[index];
                                courses[index] = new Course();
                                sub_e = 'h'; // To keep iteration of course menu
                            }
                            else if(sub_e == '2')
                            {
                                for(int y=0; y < curr_size_s; y++)
                                {
                                    
                                        if(courses[index]->s[y]->name != "None" && courses[index]->s[y]->ID != "0")
                                        {
                                            cout << c++ << " " << courses[index]->s[y]->name << " " << courses[index]->s[y]->ID << endl;
                                        }
                                    
                                }
                                c=1;
                            }
                        }
                        else if(check_list_c() == true)
                        {
                            //There are no course
                            sub_e = 'h'; 
                        }
                        else
                        {
                            //No such course
                            sub_e = 'h';
                        }
                        
                    }
                    else
                    {
                    sub_e = ' ';
                    // 0 condition should go back to main menu
                    }
            }while(sub_e == 'h');
                break;
            
            case '3':
            //List all STUDENTS
                if(check_list_s() == true && sub_e != '0')
                {
                    //No student
                }
                    list_students();
                break;
            
            case '4':
            //List all COURSES
                if(check_list_c() == true && sub_e != '0')
                {
                    //No course
                }
                    list_courses();
                break;
            
            default:
                //Unknown Error occurred!
                e = '0';
                break;
        }
    }while(e !='0');
    
}

void SMS::main_menu_text()
{
    cout << "0 exit" << endl;
    cout << "1 student" << endl;
    cout << "2 course" << endl;
    cout << "3 list-all-students" << endl;
    cout << "4 list-all-course" << endl;
}

void SMS::stu_menu(){
    cout << "O up" << endl;
    cout << "1 add_student" << endl;
    cout << "2 select_student" << endl;
}

void SMS::course_menu(){
    cout << "O up" << endl;
    cout << "1 add_course" << endl;
    cout << "2 select_course" << endl;
}

void SMS::select_student_menu(){
    cout << "O up" << endl;
    cout << "1 delete_student" << endl;
    cout << "3 add_selected _student_to_a_course" << endl;
    cout << "4 drop_selected_student_from_a_course" << endl;
}

void SMS::select_course_menu(){
    cout << "O up" << endl;
    cout << "1 delete_course" << endl;
    cout << "2 list_students_registered_to_the_selected_course" << endl;
}

char SMS::sup_pick_mech()
{
    char p;
    
    cin >> p;
    while(check_valid(p) == false)
    {
            stu_menu();
            cin >> p;
    }
    return p;
    
}

//Constructor for School Management System Class
SMS::SMS(){
    num_of_s = default_count;
    num_of_c = default_count;
    
    students = new Student*[num_of_s];
    courses = new Course*[num_of_c];
        
    set_default_s(0, num_of_s);
    set_default_c(0, num_of_c);
}

/*Destructor for School Management System class*/ 
SMS::~SMS(){
    //End of the program everything destroyed
}

void SMS::store_student(Student *address){
    bool found = false;     //Bool variable to control assigning process correctly
    int prev_c = num_of_s; //Current number of spaces for Student Data
    
    //look for empty spot in student array of pointers
    for(int i=0;i<num_of_s;i++)
    {

        if(students[i]->name == "None" && students[i]->ID == "0")
        {
            found = true;
            address->c = students[i]->c; // CARE HERE
            students[i] = address;
            break;
        }
    }
    //if there is no empty space then create it 
        if(found == false)
        {
            num_of_s += 10;
            Student** temp = new Student*[num_of_s];
            for(int k=0; k < prev_c; k++)
            {
                temp[k] = students[k];
            }
            delete[] students;
            students = temp;
            
            set_default_s(prev_c, num_of_s);
            
            for(int l=prev_c;l < num_of_s;l++)
            {
                if(students[l]->name == "None" && students[l]->ID == "0")
                {
                    students[l] = address;
                    break;
                }
            }
        }
}

void SMS::store_course(Course *address){
    bool found = false;     //Bool variable to control assigning process correctly
    int prev_c = num_of_c; //Current number of spaces for Course Data
    
    //look for empty spot in course array of pointers
    for(int i=0;i<num_of_c;i++)
    {
        if(courses[i]->name == "None" && courses[i]->code == "0")
        {
            found = true;
            address->s = courses[i]->s;
            courses[i] = address;
            break;
        }
    }
    //If there is empty space then create it 
        if(found == false)
        {
            num_of_c += 5;
            Course** temp = new Course*[num_of_c];
            for(int k=0; k < prev_c; k++)
            {
                temp[k] = courses[k];
            }
            delete[] courses;
            courses = temp;
            
            set_default_c(prev_c, num_of_c);
            
            for(int l=prev_c;l < num_of_c;l++)
            {
                if(courses[l]->name == "None" && courses[l]->code == "0")
                {
                    courses[l] = address;
                    break;
                }
            }
        }
}

void SMS::add_student(){
    size_t i;
    string inp;
    string name;
    string ID;
        
        getline(cin, inp);
        
        for(i = 0; i < inp.length();i++)
        {
            if(inp[i] >= 48 && inp[i] <= 57)
            {
                break;
                //start of Student's ID
            }
        }
    ID = inp.substr(i);   //Student's ID copied to a string variable
    name = inp.substr(0, i);    //Student's name copied to a string variable
    
    Student *temp = new Student(name, ID);
    store_student(temp);
    
}

void SMS::add_course(){

    string inp_code;
    string inp_name;
    string code;
    string name;
    
        //Get the course code 
        getline(cin, inp_code, ' ');
        //Get the name of the course next
        getline(cin, inp_name);
        
    code = inp_code;   //Course's CODE copied to a string variable
    name = inp_name;    //Course's NAME copied to a string variable

    Course *temp = new Course(name, code);
    store_course(temp);
}

void SMS::set_default_s(int start,int end){
    //Set students to default 
    for(;start < end;start++)
    {
        students[start] = new Student();
    }
    
}

void SMS::set_default_c(int start,int end){
    //Set courses to default 
    for(;start < end;start++)
    {
        courses[start] = new Course();
    }
    
}

void SMS::list_students(){
        for(int i=0; i < num_of_s;i++)
        {
            if(students[i]->name != "None" && students[i]->ID != "0")
            {
                        cout << students[i]->name;
                        cout << students[i]->ID << endl;
            }
        }
}

void SMS::list_courses(){
    for(int i=0; i < num_of_c;i++)
    {
        if(courses[i]->name != "None" && courses[i]->code != "0")
        {
            cout << courses[i]->code;
            cout << " " << courses[i]->name << endl;
            
        }
    }
}

bool SMS::check_list_s(){
    bool res = true;
        
        for(int i=0; i < num_of_s;i++)
        {
            if(!(students[i]->name =="None" && students[i]->ID =="0"))
            {
                res = false;
                break;
            }
        }
        cout << "test" << endl;
        return res;
}

bool SMS::check_list_c(){
    bool res = true;
        
        for(int i=0; i < num_of_c;i++)
        {
            if(!(courses[i]->name =="None" && courses[i]->code =="0"))
            {
                res = false;
                break;
            }
        }
        
        return res;
}

bool SMS::compare_s(string input,int &ind){
    bool res = false;
    string inp_n;
    string inp_ID;
    size_t i;
    int k;
    
    for(i = 0; i < input.length();i++)
    {
            if(input[i] >= 48 && input[i] <= 57)
            {
                break;
                //start of Student's ID
            }
    }
    inp_ID = input.substr(i);   //Student's ID copied to a string variable
    inp_n = input.substr(0, i);    //Student's name copied to a string variable
        
        for(k=0;k < num_of_s;k++)
        {
            if(students[k]->name == inp_n && students[k]->ID == inp_ID)
            {
                ind = k;
                res = true;
            }
        }
    
        return res;
}

bool SMS::compare_c(string inp_code, string inp_name, int &ind){
    bool res = false;
    int k;
    
        for(k=0;k < num_of_c;k++)
        {
            if(courses[k]->name == inp_name && courses[k]->code == inp_code)
            {
                ind = k;
                res = true;
            }
        }
        return res;
}
