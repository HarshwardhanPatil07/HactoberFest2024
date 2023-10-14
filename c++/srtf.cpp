#include<bits/stdc++.h>
using namespace std;
class Process{
    public:
    char id;
    int at;
    int bt;
};
void findwt (vector<Process>&arr, int n, int wt[]){
    int rt[n];
    for (int i=0; i<n; i++){
        rt[i]=arr[i].bt;
    }
    int completed=0,t=0,minm=INT_MAX;
    int shortest=0, finish_time;
    bool check = false;
    while (completed != n){
        for (int i=0; i<n; i++){
            if ((arr[i].at<=t) && (rt[i]<minm) && rt[i]>0){
                minm = rt[i];
                shortest=i;
                check=true;
            }
        }
        if (check==false){
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm==0){
            minm=INT_MAX;
        }
        if (rt[shortest]==0){
            completed++;
            check = false;
            finish_time = t+1;
            wt[shortest]=finish_time-arr[shortest].bt-arr[shortest].at;
            if (wt[shortest]<0){
                wt[shortest]=0;
            }
            
        }
        t++;
    }
}
void findtat (vector<Process>&arr, int n, int wt[], int tat[]){
    for (int i=0; i<n; i++){
        tat[i]=arr[i].bt+wt[i];
    }
}
void findavgtime (vector<Process>&arr, int n){
    int wt[n],tat[n],ct[n];
    double total_wt=0,total_tat=0;
    findwt(arr,n,wt);
    findtat(arr,n,wt,tat);
    for (int i=0; i<n; i++){
        ct[i] = tat[i]+arr[i].at;
    }
    cout<<"P\t\t"<<"AT\t\t"<<"BT\t\t"<<"CT\t\t"<<"TAT\t\t"<<"WT\t\t\n";
    for (int i=0; i<n; i++){
        total_wt+=wt[i];
        total_tat+=tat[i];
        cout<<" "<<arr[i].id<<"\t\t"<<arr[i].at<<"\t\t"<<arr[i].bt<<"\t\t"<<ct[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;

    }
    total_wt = total_wt/n;
    total_tat = total_tat/n;
    cout<<"Average waiting time is: "<< (total_wt)<<endl;
    cout<<"Average turn around time is: "<< (total_tat)<<endl;
}
int main()
{
    vector<Process>arr;
    Process p1;
    p1.id = 'P1';
    p1.at = 0;
    p1.bt = 8;
    arr.push_back(p1);
    Process p2;
    p2.id = 'P2';
    p2.at = 1;
    p2.bt = 4;
    arr.push_back(p2);
    Process p3;
    p3.id = 'P3';
    p3.at = 2;
    p3.bt = 9;
    arr.push_back(p3);
    Process p4;
    p4.id = 'P4';
    p4.at = 3;
    p4.bt = 5;
    arr.push_back(p4);
    int n = 4;
    findavgtime(arr,n);
    return 0;
}