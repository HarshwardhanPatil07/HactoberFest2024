import java.util.* ;
import java.io.*;
public class IntersectionOfArrays
{
    public static ArrayList<Integer> findArrayIntersection(ArrayList<Integer> arr1, int n, ArrayList<Integer> arr2, int m)
    {

        ArrayList<Integer>list = new ArrayList<>();
        //initializing pointers to 0
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(arr1.get(i).equals(arr2.get(j)))//use equals to check same value bcz if u use == it checks object.
            {
                list.add(arr1.get(i));
                i++;
                j++;
            }
            else if(arr1.get(i) < arr2.get(j))//since array is sorted so increment first array pointer if value is less than value in 2nd array
            {
                i++;
            }
            else{
                j++;
            }
        }
        if(list.size()== 0)
            list.add(-1);

        return list;
    }

    public static void main(String[] args) {

        ArrayList<Integer> ans = new ArrayList<>();

        ArrayList<Integer>l1 = new ArrayList<>(List.of(1,2,2,2,3,4));
        ArrayList<Integer>l2 = new ArrayList<>(List.of(2,2,3,3));
//        ArrayList<Integer>l1 = new ArrayList<>(List.of(3,4));
//        ArrayList<Integer>l2 = new ArrayList<>(List.of(2,2));
        ans = findArrayIntersection(l1,l1.size(),l2,l2.size());

        System.out.println(ans);
    }
}
