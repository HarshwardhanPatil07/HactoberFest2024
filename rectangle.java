package practice_java;
import java.util.*;
import java.lang.*;

class OutOfRange extends Exception//creating exception
{
	Double a;
	OutOfRange(Double b) {
	     a=b;
	   }
	   public String toString(){
	     return ("Out Of Range Value provided "+a) ;
	  }
}


public class Rectangle 
{   Scanner sc=new Scanner(System.in);
	Double length, width;
	private String area;
	private String perimeter;


	public Double getLength()
	{
		return this.length;
	}
	public Double setLength(Double length)
	{
		try {
			if(length < 0.0 || length > 20.0)//checking exception
			{
				throw new OutOfRange(length);
			}
		}
		catch (OutOfRange e)
		{
			System.out.println(e); 
		}
		
		return this.length = length;
	}
	public Double getWidth()
	{
		return this.width;
	}
	public Double setWidth(Double width)
	{
		try {
			if(width < 0.0 || width > 20.0)
			{
				throw new OutOfRange(width);
			}
		}
		catch (OutOfRange e)
		{
			System.out.println(e);
		}
		
		return this.width = width;
	}
	 public double area()
	    {
	    	return (this.length*this.width);
	    }
	 public double perimeter()
	 {
		 return (2*(this.length+this.width));
	 }
	 
	
	 public Rectangle(double x1, double x2, double x3, double x4, double y1, double y2, double y3, double y4)//taking cordinates
	
	{  
		
		if(Math.hypot(x1-x2, y1-y2)==Math.hypot(x3-x4, y3-y4))
		{
			System.out.println("Rectangle is valid ");
		}
		else if(x1==x3 && x3==x4 && y1==y2 && y3==y4)
		{
			System.out.println("It is square");
			
		
		}
		else
			System.out.println("Rectangle is invalid ");
		
		this.setLength(Math.sqrt((y4 - y1) * (y4 - y1) + (x4 - x1) * (x4 - x1)));
		this.setWidth(Math.sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)));
		System.out.println("Length is "+getLength());
		System.out.println("Width is" +getWidth());  
		
		
		
	}
	
	public static void main(String args[])
	{
		
		Rectangle obj=new Rectangle(3.0,5.0,4.0,5.0,3.0,7.0,4.0,7.0);
		System.out.println("area is" +obj.area());
		System.out.println("perimeter is" +obj.perimeter());
			}
	}
