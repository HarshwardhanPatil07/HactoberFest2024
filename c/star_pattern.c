#include<stdio.h>
//github username: @Kanan33
//date:15/10/2024
void main()
{
    int i,j,n;
    printf("Enter n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}