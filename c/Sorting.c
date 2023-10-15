#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[], int p, int r, int q)
{
   int temp[40], i=0, j = r+1, k=0;
   while ((i<=r)&&(j<=q))
   {
    if (arr[i]<arr[j])
    {
        temp[k] = arr[i];
        i++;
    }else{
        temp[k] = arr[j];
        j++;
    }
    k++;c
   }
   if (j>q)
   {
    while (i<=r)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    }else{
		while (j<=q)
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
		
	}
   for (int i = 0; i <= q; i++)
   {
	arr[i] = temp[i];
	
   }
   
   
}

void merge_sort(int arr[], int p, int q){
	int r;
	if (p<q)
	{
		r = (p+q)/2;
		merge_sort(arr, p, r);
		merge_sort(arr, r+1, q);

		Merge(arr, p, r, q);
	}
	
}


int partetian(int A[], int start, int end)
{
    int x, i, temp;
    x = A[end];
    i = start - 1;
    for(int j = start; j < end; j++)
    {
        if(A[j] <= x)
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[end];
    A[end] = temp;

    return i+1;
}

void quicksort(int A[], int start, int end)
{

    int i,q;
    if(start>=end)
    {
        return;
    }
    q = partetian(A, start, end);
    quicksort(A, start, q-1);
    quicksort(A, q+1, end);

}


void bubblesort(int a[], int k){
    int i, j, temp;
    for(i = 0; i<k; i++){
        for(j=0; j<k; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1]= temp;
            }
        }
    }
    for(i=0; i<k ; i++){
        printf("%d\n", a[i]);
    }
}

void main(){
	int r, arr[30], i;
	printf("Enter no. of elements you want to add");
	scanf("%d", &r);
	printf("Enter the elements\n");
	for (int i = 0; i < r; i++)
	{
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, k);
	printf("Sorted list is:\n");
	for (int i = 0; i < r; i++)
	{
		printf("%d\n", arr[i]);
	}


    //For Quick sort
    int start, end;
    int A[10]= {8,1,6,4,0,3,9,5};
    quicksort(A, 0, 7);
    for(int k=0; k<8; k++)
    {
        printf("%d",A[k]);
        printf("\n");
    }


    //For Bubble Sort
    int k, a[40], i;
    printf("Enter no of elements in array\n");
    scanf("%d",&k);
    printf("Enter array\n");
    for(i=0; i<k; i++){
        scanf("%d", &a[i]);
    }
    bubblesort(a, k);
	
}
