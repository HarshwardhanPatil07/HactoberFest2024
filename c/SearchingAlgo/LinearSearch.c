#include <stdio.h>
#define SIZE 5
int LinearSearch(int array[] , int size , int searchValue){
    for(int i =  0 ; i < size ; i++){
        if(searchValue == array[i]){
            return i;
        }
    }

    return -1;
}

int main(){

    int  array[] = {1,2,3,4,5}, searchValue;
   searchValue = 2;
  
    int size = sizeof(array) / sizeof(array[0]);
    int result = LinearSearch(array , size , searchValue);
    (result == -1)? printf("element not found in the array"):printf("element found in the array");
    return 0;
}