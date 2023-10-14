#include<bits/stdc++.h>
using namespace std;
class Process{
    public:
    int order;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void find (vector<Process>&pro, int n, int q){
    int rt[n];
    for (int i=0; i<n; i++){
        rt[i]=pro[i].bt;
    }
    int ct=0;
    while (1){
        bool check = true;
        for (int i=0; i<n; i++){
            if(rt[i] > 0){
                check = false;
                if(rt[i]>q){
                    ct += q;
                    rt[i]-=q;
                }
                else{
                    ct += rt[i];
                    rt[i]=0;
                    pro[i].ct = ct;
                }
            }
        }
        if(check==true)
            break;
    }
    double avg_tat = 0.0;
    double avg_wt = 0.0;
    for (int i=0; i<n; i++){
        pro[i].tat = pro[i].ct-pro[i].at;
        pro[i].wt = pro[i].tat-pro[i].bt;
        avg_tat += pro[i].tat;
        avg_wt += pro[i].wt;
    }
    cout<<"Process"<<"\t\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<endl;
    for (int i=0; i<n; i++){
        cout<<"P"<<pro[i].order<<"\t\t"<<pro[i].at<<"\t"<<pro[i].bt<<"\t"<<pro[i].ct<<"\t"<<pro[i].tat<<"\t"<<pro[i].wt;
        cout<<endl;
    }
    cout <<"Avg tat is: "<<(avg_tat/n)<<endl;
    cout <<"Avg wt is: "<<(avg_wt/n)<<endl;
}
int main()
{
    int n;
    cout <<"The number of processes: ";
    cin>>n;
    cout<<"Enter: ";
    vector<Process>pro(n);
    for (int i=0; i<n; i++){
        int o,a,b;
        cin >>o>>a>>b;
        pro[i].order = o;
        pro[i].at = a;
        pro[i].bt = b;
    }
    int q;
    cout<<"Enter time  quantum: ";
    cin>>q;
    find(pro,n,q);
    return 0;
}