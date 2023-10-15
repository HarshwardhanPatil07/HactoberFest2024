import java.util.*;

public class Strings {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
       System.out.println("Enter name");
        String name = sc.nextLine();
        System.out.println("Your name is "+name);

        //concatenation
        System.out.println("Enter first name");
        String first = sc.next();
        System.out.println("Enter last name");
        String last = sc.next();
        String fullname = first+" "+last;
        System.out.println("Your full name is"+fullname);
        System.out.println(fullname.length());

        //charAt

       for (int i = 0; i < fullname.length(); i++) {
            System.out.println(fullname.charAt(i));
       }


        //comparison function

       if (first.compareTo(last)==0){
            System.out.println("Equal");
        } else if (first.compareTo(last)>0){
                System.out.println("Strings are not equal and greater than other name");
        }else {
            System.out.println("Strings are not equal and second string is greater than 1st string");
       }

        //Substring

        String Sub = fullname.substring(5, fullname.length());
        System.out.println(Sub);


        //Check for substring existence
        System.out.println("Enter substring you want to check");
        String x = sc.next();
        if (name.contains(x)) {
            System.out.println("Substring Found");
        }


        //Replace Substrings
        System.out.println("Enter string you want to replace with");
        String y = sc.next();
        String replacedStr = name.replace(x, y);
    }
}
