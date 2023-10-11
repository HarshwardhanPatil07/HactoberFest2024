#include<stdio.h>

int main(){

    int num;       
    int count=0;

    printf("Enter a number : ");
    scanf("%d",&num);

    for(int i=1;i<=num;i++){
        if(num%i==0){
            count++;
        }
    }if(count==2){
        printf("%d is prime\n",num);
    }else{
        printf("%d is not a prime\n",num);
    }if(num==1 ||num==0){
        printf("0,1 are neither prime nor composite");
    }



    return 0;
}