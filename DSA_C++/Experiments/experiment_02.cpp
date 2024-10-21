/*2.  Write a C++ Program to display Names, Roll No., and grades of 3 students who have
appeared in the examination. Declare the class of name, Roll No. and grade.
Create an array of class objects. Read and display the contents of the array. 
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    char grade;

public:
    void readData() {
        cout << "Enter name: ";
        cin.ignore();  // Clear the input buffer before reading the name
        getline(cin, name);  // Use getline to read full name
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter grade: ";
        cin >> grade;
        cin.ignore();  // Clear the input buffer after reading the grade
    }

    void displayData() const {
        cout << "Name: " << name << "\nRoll No.: " << rollNo << "\nGrade: " << grade << "\n";
    }
};

int main() {
    const int numStudents = 3;
    Student students[numStudents];
    cout << "Enter details of " << numStudents << " students:\n";
    
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\n";
        students[i].readData();
        cout << "\n";  // Add a newline for separation between input prompts for each student
    }

    cout << "Displaying student details:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\n";
        students[i].displayData();
        cout << "\n";  // Add a newline for separation between details of each student
    }

    return 0;
}



