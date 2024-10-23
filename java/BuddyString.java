package org.problems.strings;

import java.util.ArrayList;

public class BuddyString {


    public static void main(String[] args) {
        buddyStrings("abcde", "ebcda");
    }
    public static boolean buddyStrings(String s, String goal) {

        if (s.length() != goal.length())
            return false;
        boolean isBuddyString = true;
        int count = 0;
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != goal.charAt(i)) {
                count++;
                list.add(i);
            }
        }
        if (count == 2) {
            if (s.charAt(list.get(0)) != goal.charAt(list.get(1)))
                isBuddyString = false;
        }
        return isBuddyString;
    }
}
