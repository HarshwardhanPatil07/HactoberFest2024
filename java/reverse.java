// Username - Akash2001, aim: To reverse the string, date: 23-10-2023

import java.io.*;
import java.util.Scanner;
 
class reverse {
    public static void main (String[] args) {
       
        String str= "Hacktoberfest", nstr="";
        char ch;
       
      System.out.print("Original word: ");
      System.out.println(str);
       
      for (int i=0; i<str.length(); i++)
      {
        ch= str.charAt(i);
        nstr= ch+nstr;
      }
      System.out.println("Reversed word: "+ nstr);
    }
}