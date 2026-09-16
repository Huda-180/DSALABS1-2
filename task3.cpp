#include<iostream>
using namespace std;

//defining class Student above main
class Student{
    public:
    //declaring the required 2 public data members
    int roll_number;
    int marks;
    //adding member function void display();
    void display(int roll_number, int m){
        //displaying roll number and marks of the student on separate lines with labels
        cout<<"Roll Number: "<<roll_number<<endl; //displaying roll number 
        cout<<"Marks: "<<marks<<endl; //displaying marks
    }
};

//main function:Entry Point

int main() {
    //creating  first object s1 of class Student
    Student s1;
    //creating second object s2 of class Student
    Student s2;

    //assigning values 1 and 75 to the data members of object s1
    s1.roll_number = 1;
    s1.marks = 75;
    //assigning values to the data members of object s2
    s2.roll_number = 2;
    s2.marks = 90;

    //calling display() function for object s1
    cout<<"Details of Student 1:"<<endl; //adding a label for the output of object s1
    s1.display(s1.roll_number, s1.marks);
    //calling display() function for object s2
    cout<<"Details of Student 2:"<<endl; //adding a label for the output of object s2
    s2.display(s2.roll_number, s2.marks); 
    
//changing the value of marks of object s1 to 80
    s1.marks = 80;

    cout<<"After changing marks of Student 1:"<<endl; //adding a label for the output after changing marks of object s1

    //displaying the objects again
    cout<<"Details of Student 1:"<<endl;
    s1.display(s1.roll_number, s1.marks);
    cout<<"Details of Student 2:"<<endl;
    s2.display(s2.roll_number, s2.marks);
    return 0;
}