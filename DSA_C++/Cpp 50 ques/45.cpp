#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int marks;

    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void saveToFile() {
        ofstream file("student_marks.txt");
        if (file.is_open()) {
            file << "Name: " << name << endl;
            file << "Marks: " << marks << endl;
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

int main() {
    Student student;
    student.getData();
    student.saveToFile();
    cout << "Data saved to student_marks.txt" << endl;
    return 0;
}
