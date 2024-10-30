//Author: Sumon Chatterjee @Sumon670
//Data: 14/10/2023
#include<bits/stdc++.h>
using namespace std;
class Process{
    public:
    int order;
    int at;
    int bt;
};
static bool cmp (Process a, Process b){
    return a.order < b.order;
}
void find (vector<Process>&arr, int n){
    int ct = 0;
    double total_tat = 0;
    double total_wt = 0;
    for (int i=0; i<n; i++){
        if (arr[i].at <= ct){
            ct += arr[i].bt;
        }
        cout<<"P"<<(i+1)<<"         ";
        cout<<arr[i].order<<"       ";
        cout<<arr[i].at<<"   ";
        cout<<arr[i].bt<<"   ";
        cout << ct << "  ";
        int tat = (ct-arr[i].at);
        total_tat += tat;
        cout << tat << "  ";
        int wt = tat - arr[i].bt;
        total_wt += wt;
        cout << wt << " ";
        cout<<endl;
    }
    cout<<"Average waiting time is: "<<(total_wt/n)<<endl;
    cout<<"Average turn around time is: "<<(total_tat/n)<<endl;
}
int main()
{
    vector<Process>arr;
    Process p1;
    p1.order = 1;
    p1.at = 0;
    p1.bt = 24;
    arr.push_back(p1);
    Process p2;
    p2.order = 2;
    p2.at = 0;
    p2.bt = 3;
    arr.push_back(p2);
    Process p3;
    p3.order = 3;
    p3.at = 0;
    p3.bt = 4;
    arr.push_back(p3);
    int n = 3; //no of processes;
    sort(arr.begin(),arr.end(),cmp);
    cout << "Process"<<"    "<<"Order"<<"   "<<"At"<<"  "<<"Bt"<<"  "<<"Ct"<<"  "<<"Tat"<<" "<<"Wt"<<endl;
    find(arr,n);
    return 0;
}