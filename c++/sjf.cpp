#include<bits/stdc++.h>
using namespace std;
static bool cmp (pair<int,pair<char,int>>a,pair<int,pair<char,int>>b ){
    return a.first < b.first;
}
void find (vector<pair<int,pair<char,int>>>&arr, int n){
    int ct = 0;
    double total_tat = 0;
    double total_wt = 0;
    for (int i=0; i<n; i++){
        if (arr[i].second.second <= ct){
            ct += arr[i].first;
        }
        cout<<arr[i].second.first<<"         ";
        cout<<arr[i].second.second<<"   ";
        cout<<arr[i].first<<"    ";
        cout << ct << "  ";
        int tat = (ct-arr[i].second.second);
        total_tat += tat;
        cout << tat << "    ";
        int wt = tat - arr[i].first;
        total_wt += wt;
        cout << wt;
        cout<<endl;
    }
    cout<<"Average waiting time is: "<<(total_wt/n)<<endl;
    cout<<"Average turn around time is: "<<(total_tat/n)<<endl;
}
int main()
{
    vector<pair<int,pair<char,int>>>arr;
    arr.push_back(make_pair(6,make_pair('P1',0)));
    arr.push_back(make_pair(8,make_pair('P2',0)));
    arr.push_back(make_pair(7,make_pair('P3',0)));
    arr.push_back(make_pair(3,make_pair('P4',0)));
    int n = 4; //no of processes;
    sort(arr.begin(),arr.end(),cmp);
    cout << "Process"<<"   "<<"At"<<"  "<<"Bt"<<"  "<<"Ct"<<"  "<<"Tat"<<"  "<<"Wt"<<endl;
    find(arr,n);
    return 0;
}