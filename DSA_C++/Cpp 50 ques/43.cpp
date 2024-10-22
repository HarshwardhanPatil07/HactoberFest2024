#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int roll;

    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
    }

    void saveToFile() {
        ofstream file("student.txt");
        if (file.is_open()) {
            file << "Name: " << name << endl;
            file << "Roll number: " << roll << endl;
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
    cout << "Data saved to student.txt" << endl;
    return 0;
}
