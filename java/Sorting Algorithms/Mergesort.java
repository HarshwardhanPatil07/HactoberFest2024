/*Time Complexity:O(nlogn)
  Space Complexity:O(n)*/
import java.util.Scanner;
class Sort{

    void Merge(int[] arr,int l,int mid,int r){
        int n1=mid-l+1;
        int n2=r-mid;

        int left[]=new int [n1];
        int right[]=new int [n2];

        for(int i=0;i<n1;i++){
            left[i]=arr[l+i];
        }

        for(int j=0;j<n2;j++){
            right[j]=arr[mid+1+j];
        }

        int i=0,j=0,k=l;

        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                i++;
            }else{
                arr[k]=right[j];
                j++;
            }
            k++;
        }


        while(i<n1){
            arr[k]=left[i];
            i++;
            k++;
        }

        while(j<n2){
            arr[k]=right[j];
            j++;
            k++;
        }
    }




    void Mergesort(int []arr,int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            Mergesort(arr,l,mid);
            Mergesort(arr,mid+1,r);
            Merge(arr,l,mid,r);
        }
    }


    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        System.out.print("Enter the size of array:");
        int n=sc.nextInt();
        int []arr=new int [n];
        System.out.print("Enter the array:");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Sort s=new Sort();
        s.Mergesort(arr,0,n-1);
        
        System.out.print("Sorted array is:");

        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }

    }
}
