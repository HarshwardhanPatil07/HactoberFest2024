
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

void main(){
	int k, arr[30], i;
	printf("Enter no. of elements you want to add");
	scanf("%d", &k);
	printf("Enter the elements\n");
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, k);
	printf("Sorted list is:\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", arr[i]);
	}
	
}
