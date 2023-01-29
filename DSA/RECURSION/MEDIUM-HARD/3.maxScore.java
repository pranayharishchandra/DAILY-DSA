import java.io.*;
import java.util.*;

public class Main {

    // uncomment the commented 
    public static void solution2(String[] words, int[] farr, int[] score, int idx, int[] ans) {
        if (idx == words.length) {
            ans[0] = Math.max(ans[0], ans[1]);
            return;
        }

        // not including
        solution2(words, farr, score, idx + 1, ans);

        // including
        boolean flag = false;
        String word = words[idx];
        int currScore = 0;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            farr[ch - 'a']--;
            if (farr[ch - 'a'] < 0) {
                flag = true;
            }
            currScore += score[ch - 'a'];
        }

        if (flag) {
            for (int i = 0; i < word.length(); i++) {
                char ch = word.charAt(i);
                farr[ch - 'a']++;
            }
        } else {
            ans[1] += currScore;
            solution2(words, farr, score, idx + 1, ans);
        }

    }

    public static int solution(String[] words, int[] farr, int[] score, int idx) {
        /*
         * // FOR SOLUTION2 -- IT WORKS FINE
         * int [] ans = new int[2]; // 0th idx -- main answer or max score // 1st idx --
         * current score
         * ans[0] = Integer.MIN_VALUE;
         * solution2(words, farr, score, idx, ans);
         * return ans[0];
         * 
         * // return 0;
         */

        // write your code here

        if (idx == words.length)
        {
            return 0;
        }

        int inc = 0;
        int notInc = 0;

        notInc = 0 + solution(words, farr, score, idx + 1);

        String word = words[idx];

        int currScore = 0;
        boolean flag = true;

        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            currScore += score[ch - 'a'];
            farr[ch - 'a']--;
            if (farr[ch - 'a'] < 0) {
                flag = false;
            }
        }

        if (flag) {
            inc = currScore + solution(words, farr, score, idx + 1);
        }

        // make the orginal parameter as it is for the next call... calls of the other
        // side (right side)
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            farr[ch - 'a']++;

        }

        return Math.max(inc, notInc);
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int nofWords = scn.nextInt();
        String[] words = new String[nofWords];
        for (int i = 0; i < words.length; i++) {
            words[i] = scn.next();
        }
        int nofLetters = scn.nextInt();
        char[] letters = new char[nofLetters];
        for (int i = 0; i < letters.length; i++) {
            letters[i] = scn.next().charAt(0);
        }
        int[] score = new int[26];
        for (int i = 0; i < score.length; i++) {
            score[i] = scn.nextInt();
        }
        scn.close();
        if (words == null || words.length == 0 || letters == null || letters.length == 0 || score == null
                || score.length == 0) {
            System.out.println(0);
            return;
        }
        int[] farr = new int[score.length];
        for (char ch : letters) {
            farr[ch - 'a']++;
        }
        System.out.println(solution(words, farr, score, 0));

    }
}
