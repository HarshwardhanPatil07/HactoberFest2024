/*
username:limitlesslogger
date:15 october 2023
Aim:to find transpose of a sparse matrix
*/
#include <stdio.h>
typedef struct 
{
    int rows;
    int columns;
    int value;
}triplet;
void inputSparse(triplet a[],int n,int r,int c)
{
    printf("Enter the inputs as rows columns and values\n");
    a[0].rows=r;
    a[0].columns=c;
    a[0].value=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a[i].rows,&a[i].columns,&a[i].value);
    }
}
void displayInput(triplet a[],int n)
{
    printf("The sparse representation is\n");
    for(int i=0;i<=n;i++)
    {
        printf("%d %d %d\n",a[i].rows,a[i].columns,a[i].value);
    }
}
void arrangeSparse(triplet a[],int n)
{
    triplet temp[1];
    //arrange in ascending order of columns
    //input il column ascending akuka
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((a[i].rows>a[j].rows&&a[j].columns==a[i].columns)||(a[i].columns>a[j].columns))
            {
                    temp[0]=a[i];
                    a[i]=a[j];
                    a[j]=temp[0];
            }
        }
    }
}
void transSparse(triplet t[],int n)
{
    //swap
    triplet temp[1];
    for(int i=0;i<=n;i++)
    {
        temp[0].rows=t[i].rows;
        t[i].rows=t[i].columns;
        t[i].columns=temp[0].rows;
    }
}
void main()
{
    triplet a[10],t[10];
    int nonZero1;
    printf("Enter number of non zero elemnets in first matrix\n");
    scanf("%d",&nonZero1);
    int r1,c1;
    printf("Enter number of rows and columns of sparse 1\n");
    scanf("%d %d",&r1,&c1);
    inputSparse(a,nonZero1,r1,c1);
    printf("input\n");
    displayInput(a,nonZero1);
    arrangeSparse(a,nonZero1);
    printf("Arrange\n");
    displayInput(a,nonZero1);
    printf("swap\n");
    transSparse(a,nonZero1);
    displayInput(a,nonZero1);
}
//arraged order in trans il akuka swap cheyuka
