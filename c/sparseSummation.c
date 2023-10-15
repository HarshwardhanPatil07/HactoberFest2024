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
    printf("The sparse representations are\n");
    for(int i=0;i<=n;i++)
    {
        printf("%d %d %d\n",a[i].rows,a[i].columns,a[i].value);
    }
}
int sparseSum(triplet a[],triplet b[],triplet c[],int n1,int n2)
{
    int i=1,k=1,j=1;
    if(a[0].rows==b[0].rows&&a[0].columns==b[0].columns)
    {
        c[0].rows=a[0].rows;
        c[0].columns=a[0].columns;
        while(i<=n1&&j<=n2)
        {
            if(a[i].rows==b[j].rows&&a[i].columns==b[j].columns)
            {
                c[k].rows=a[i].rows;
                c[k].columns=a[i].columns;
                c[k].value=a[i].value+b[j].value;
                i++;j++;k++;
            }
            else if((a[i].rows==b[j].rows&&a[i].columns>b[j].columns)||(a[i].rows>b[j].rows))
            {
                c[k].rows=b[j].rows;
                c[k].columns=b[j].columns;
                c[k].value=b[j].value;
                j++;k++;  
            }
            else if((a[i].rows==b[j].rows&&a[i].columns<b[j].columns)||(a[i].rows<b[j].rows))
            {
                c[k].rows=a[i].rows;
                c[k].columns=a[i].columns;
                c[k].value=a[i].value;
                i++;k++; 
            }
        }
        while(i<=n1)
        {
            c[k].rows=a[i].rows;
            c[k].columns=a[i].columns;
            c[k].value=a[i].value;
            i++;k++;
        }
        while(j<=n2)
        {
            c[k].rows=b[j].rows;
            c[k].columns=b[j].columns;
            c[k].value=b[j].value;
            j++;k++;
        }
    }
    return k;
}
void main()
{
    triplet a[10],b[10],c[10];
    int nonZero1,nonZero2;
    printf("Enter number of non zero elemnets in first matrix\n");
    scanf("%d",&nonZero1);
    printf("Enter number of non zero elemnets in second matrix\n");
    scanf("%d",&nonZero2);
    int r1,c1,r2,c2;
    printf("Enter number of rows and columns of sparese 1\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter number of rows and columns of sparese 2\n");
    scanf("%d %d",&r2,&c2);
    inputSparse(a,nonZero1,r1,c1);
    inputSparse(b,nonZero2,r2,c2);
    displayInput(a,nonZero1);
    displayInput(b,nonZero2);
    int k=sparseSum(a,b,c,nonZero1,nonZero2);
    c[0].value=k-1;
    displayInput(c,k-1);
}
