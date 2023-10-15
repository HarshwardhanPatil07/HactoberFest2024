#include <stdio.h>
void getMatrix(int r,int c,int arr[][10])
{
    printf("Enter matrix elements\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
int sparseRep(int r,int c,int arr[][10])
{
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                // printf("\n %d %d %d",i+1,j+1,arr[i][j]);
                k++;//k gives number of non zero elements
            }
        }
    }
    return k;
}
void sparseMatrix(int matrix[][3],int arr[][10],int rows,int r,int c)
{
    matrix[0][0]=r;
    matrix[0][1]=c;
    matrix[0][2]=rows;
    int m=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                matrix[m][0]=i;
                matrix[m][1]=j;
                matrix[m][2]=arr[i][j];
                m++;
            }
        }
    }
}
void main()
{
    int r,c;
    int arr[10][10];
    printf("Enter no: of rows\n");
    scanf("%d",&r);
    printf("Enter no: of columns\n");
    scanf("%d",&c);
    getMatrix(r,c,arr);
    int rows=sparseRep(r,c,arr);
    int matrix[rows][3];
    sparseMatrix(matrix,arr,rows,r,c);
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}