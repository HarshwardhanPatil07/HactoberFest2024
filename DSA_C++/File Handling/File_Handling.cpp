// #include <iostream>
// #include <fstream>  // For file handling
// using namespace std;

// int main() {
//     char arr[100];  // Array to hold name and age
    
//     // Input name and age from the user
//     cout << "Enter your name and age: ";
//     cin.getline(arr , 100);  // Get the input (name and age)

//     // Writing to a file using fstream
//     fstream myfile("xyz.txt", ios::out | ios::app);  // Open file in append mode
//     if (myfile.is_open()) {
//         myfile << arr << endl;  // Write the data to file
//         myfile.close();  // Close the file
//         cout << "File write operation performed successfully." << endl;
//     } else {
//         cout << "Error opening file for writing." << endl;
//     }

//     // Reading from the file
//     cout << "READING FROM FILE OPERATION started" << endl;
//     char arr1[100];  // Array to hold file content
//     ifstream obj("xyz.txt");  // Open the file for reading
//     if (obj.is_open()) {
//         obj.getline(arr1, 100);  // Read content from the file
//         cout << "Array content: " << arr1 << endl;  // Display content
//         obj.close();  // Close the file
//         cout << "File read operation completed." << endl;
//     } else {
//         cout << "Error opening file for reading." << endl;
//     }

//     return 0;
// }




// #include<iostream>
// #include<fstream>
// using namespace std;

// int main(){
//     char arr[100];
//     cout<<"Enter your name and age : ";
//     cin.getline(arr,100);

//     ofstream out_myfile("xyz.txt");
//     if(out_myfile.open()){
//         out_myfile<<arr;

//         out_myfile.close();
//         cout<<"File write operation performed successfully."<<endl;         }
//     else {
//         cout<<"Error opening file for writing."<<endl;
//     }
    



//     //cout<<"Reading of the file started : ";
//     char arr1[100];
//     ifstream obj("xyz.txt");
//     if(obj.open()){
//         obj.getline(arr1 , 100);
//         cout<<"array element : "<<arr1<<endl;
//         cout<<"readsing closed .....";
//         obj.close();
        
//     }
//     else {
//     cout << "Error opening file for reading." << endl;
//     }
    
//     return 0;
    
// }



// #include <iostream>
// #include <fstream>  // For file handling
// using namespace std;

// int main() {
//     char arr[100];  // Array to hold name and age

//     // Input name and age from the user
//     cout << "Enter your name and age: ";
//     cin.getline(arr , 100);  // Get the input (name and age)

//     // Writing to a file using ofstream
//     ofstream fout("myfile1.dat");  // Open the file for writing
//     if (fout) {
//         fout << arr << endl;  // Write data to the file
//         cout << "File write operation performed successfully." << endl;
//     } else {
//         cout << "Error opening file for writing." << endl;
//     }

//     fout.close();  // Close the file

//     // Reading from the file using ifstream
//     ifstream fin("myfile1.dat");  // Open the file for reading
//     if (fin) {
//         char ch;
//         cout << "READING FROM FILE OPERATION started" << endl;
//         while (fin >> ch) {  // Read character by character
//             cout << ch;  // Print each character
//         }
//         cout << endl << "File read operation completed." << endl;
//     } else {
//         cout << "Error opening file for reading." << endl;
//     }

//     fin.close();  // Close the file

//     return 0;
// }





// #include <fstream>
// #include <iostream>
// using namespace std;

// int main() {
//     char name[100];  // Array to hold the name
//     char age[10];    // Array to hold the age

//     ofstream outputFile;  // Output file stream
//     outputFile.open("output.txt");  // Open the file for writing

//     // Get user input and write to file
//     cout << "Enter your name: ";
//     cin.getline(name, 100);
//     outputFile << "Name: " << name << endl;

//     cout << "Enter your age: ";
//     cin.getline(age, 10);
//     outputFile << "Age: " << age << endl;

//     outputFile.close();  // Close the file after writing

//     ifstream inputFile;  // Input file stream
//     inputFile.open("output.txt");  // Open the file for reading

//     // Reading and displaying the file content
//     string line;
//     cout << "\nReading from the file:" << endl;
//     while (getline(inputFile, line)) {
//         cout << line << endl;
//     }

//     inputFile.close();  // Close the file after reading

//     return 0;
// }



#include<iostream>
#include<fstream>

using namespace std;

int main(){
    char arr[100];
    cout<<"enter your name and age : ";
    cin.getline(arr,100);

    ofstream fout;
    fout.open("xyx.txt");
    fout<<arr<<endl;
    fout<<"File operation performed succesfully...";
    fout.close();

    cout<<"Reading started...";
    char ch[100];
    ifstream fin;
    fin.open("xyz.txt");
    while(fin){
        fin.getline(ch,100);
        cout<<ch<<endl;
    }
    fin<<"reading finished";
    fin.close();

    return 0;
}





#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Getting input from the user
    void getInput() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your age: ";
        cin >> age;
    }

    // Saving data to the file
    void saveToFile() {
        ofstream outFile("student.txt");  // Open a file to save data
        outFile << "Name: " << name << endl;
        outFile << "Age: " << age << endl;
        outFile.close();  // Close the file after saving
        cout << "Data saved to file!" << endl;
    }

    // Reading data from the file
    void readFromFile() {
        ifstream inFile("student.txt");  // Open the file to read data
        string line;
        cout << "Reading from file:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;  // Display each line from the file
        }
        inFile.close();  // Close the file after reading
    }
};

int main() {
    Student s;
    
    // Get input from the user
    s.getInput();
    
    // Save the input to a file
    s.saveToFile();
    
    // Read the data from the file and show it
    s.readFromFile();
    
    return 0;
}
