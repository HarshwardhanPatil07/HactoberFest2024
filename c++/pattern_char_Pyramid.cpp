#include<iostream>
using namespace std;

void printTriangle(int n) {
    
    for(int i=0; i<n; i++){
        
        char ch = 'A';
        
        //space
        for(int k=0; k<=n-i-2; k++){
            cout<<" ";
        }
        
        //triangle
        int breakpoint = (2*i+1)/2;
        for(int j=1; j<=2*i+1; j++){
            cout<<ch;
            if(j<=breakpoint) ch++;
            else ch--;
        }        
        cout<<endl;
    }
}

int main() {

    printTriangle(4);
    return 0;
}

/*isheta20, 21/10/23
   A
  ABA
 ABCBA
ABCDCBA
*/