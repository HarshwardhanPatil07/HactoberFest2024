
/*
Username : yuvrajverma25 (https://github.com/yuvrajverma25)
Aim : Create a Hollow Sandglass Star Pattern
Date : 19/10/2023
*/
import java.util.Scanner;

public class HollowSandglassStarPattern {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		
		int i, j, k;
		
		System.out.print("Enter Hollow Sandglass Star Pattern Rows = ");
		int rows = sc.nextInt();
		
		System.out.println("Printing Hollow Sandglass Star Pattern");
		
		for (i = 1; i <= rows; i++ ) 
		{
			for (j = 1; j < i; j++ ) 
			{
				System.out.print(" ");
			}
			for(k = i; k <= rows; k++) 
			{
				if(i == 1 || k == i || k == rows)
				{
					System.out.print("* ");
				}
				else 
				{
					System.out.print("  ");
				}
			}
			System.out.println();
		}
		
		for (i = rows - 1; i >= 1; i-- ) 
		{
			for (j = 1; j < i; j++ ) 
			{
				System.out.print(" ");
			}
			for(k = i; k <= rows; k++) 
			{
				if(i == 1 || k == i || k == rows)
				{
					System.out.print("* ");
				}
				else 
				{
					System.out.print("  ");
				}
			}
			System.out.println();
		}
	}
}
