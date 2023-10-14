#include<bits/stdc++.h>
using namespace std;
class process{
    public:
        int id;
        int pr;
        int bt;
        int ct;
        int tat;
        int wt;
};
static bool cmp (process a, process b){
    return (a.pr > b.pr);
}
void solve (process arr[], int n){
    sort(arr,arr+n,cmp);
    int ct = 0;
    double avg_wt=0;
    double avg_tat=0;
    for (int i=0; i<n; i++){
        ct = ct + arr[i].bt;
        arr[i].ct = ct;
        arr[i].tat = ct;
        arr[i].wt = arr[i].tat - arr[i].bt;
        avg_tat += arr[i].tat;
        avg_wt += arr[i].wt;
    }
    cout<<"Process\t\tPr\tBT\tCT\tTAT\tWT\n";
    for (int i=0; i<n; i++){
        cout<<"P"<<arr[i].id<<"\t\t"<<arr[i].pr<<"\t"<<arr[i].bt<<"\t"<<arr[i].ct<<"\t"<<arr[i].tat<<"\t"<<arr[i].wt<<"\n";
    }
    cout<<"Average waiting time is: "<<(avg_wt/n)<<"\n";
    cout<<"Average turn around time is: "<<(avg_tat/n);
}
int main(){ 
    int n;
    cout<<"Enter no of process: ";
    cin>>n;
    process arr[n];
    for (int i=0; i<n; i++){
        cout<<"Enter id, priority and bt: ";
        int j;
        cin>>j;
        int p,b;
        cin>>p>>b;
        arr[i].id = j;
        arr[i].pr = p;
        arr[i].bt = b;
    }
    solve (arr,n);
    return 0;
}
