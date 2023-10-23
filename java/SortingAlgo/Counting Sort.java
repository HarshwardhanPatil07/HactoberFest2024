public class Countingsort {
	public static void print(int arr[]) {
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
			
		}System.out.println();
	}
	public static void counting(int arr[]) {
	int largest =Integer.MIN_VALUE;
	for (int i=0;i<arr.length;i++) {
		if (arr[i]>largest ) {
			largest= arr[i];
		}
	}
	
		int count[]= new int[largest+1];
	 for(int i=0;i<arr.length;i++) {
		 count[arr[i]]++;
	 }
	 int j=0;
	 for(int i=0;i<count.length;i++) {
		 while(count[i]>0) {
			 arr[j]=i;
			 j++;
			 count[i]--;
		 }
	 }
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[]= {5,3,4,7,1,2};
		counting(arr);
		print(arr);

	}

}
