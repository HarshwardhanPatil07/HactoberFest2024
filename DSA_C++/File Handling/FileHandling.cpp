#include<iostream>
#include<fstream>

using namespace std;

// int main(){
//     char arr[100];
//     cout<<"enter your name and age : ";
//     cin.getline(arr,100);

//     ofstream fout;
//     fout.open("xyx.txt");
//     fout<<arr<<endl;
//     fout<<"File operation performed succesfully...";
//     fout.close();

//     cout<<"Reading started...";
//     char ch[100];
//     ifstream fin;
//     fin.open("xyz.txt");
//     while(fin){
//         fin.getline(ch,100);
//         cout<<"Array elements -->>"<<ch<<endl;
//     }
//     cout<<"reading finished";
//     fin.close();

//     return 0;
// }




int main (){
    char arr[100];
    cout<<"Enter your name and age here : ";
    cin.getline(arr , 100);

    ofstream fout("xyz.txt");
    fout<<arr<<endl;
    fout<<"File operation performed ended";
    fout.close();

    ifstream fin("xyz.txt");
    char ch[100];
    while(fin.getline(ch,100)){
        cout<<"Array elements -->>"<<ch<<endl;
    }
    cout<<endl;
    cout<<"reading finished";
    fin.close();

    return 0;
}