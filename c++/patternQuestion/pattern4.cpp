#include <iostream>
using namespace std;

/*        * 
        *   *
      *       *
    *           *
  * * * * * * * * *
*/

int main()
{
    int i,j;
    int n=5;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            cout<<"  ";
        }
        for(j=1;j<i;j++){
            if(i==n||j==1)
                cout<<"* ";
            else
                cout<<"  ";
        }
        for(j=1;j<=i;j++){
            if(i==n||j==i){
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
