#include <iostream>
using namespace std;

/*
*
* *
*   *
*     *
* * * * *
*/

int main()
{
    int i,j;
    int n=5;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j==1||i==5||i==j){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}
