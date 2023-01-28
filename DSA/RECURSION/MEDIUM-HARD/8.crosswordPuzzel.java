import java.io.*;
import java.util.*;

/* 
 * JUST TRY WRITING -- CANPALACEVERTICLE or CANPLACEHORIZONTAL -- you may make mistake in writing those condions 
 * REST ALL Func. are easy..  just go through them
 */

public class Main {

    public static class Edge {

        int src;
        int nbr;
        int wt;

    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        char[][] arr = new char[10][10];
        for (int i = 0; i < arr.length; i++) {
            String str = scn.next();
            arr[i] = str.toCharArray();
        }
        int n = scn.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < words.length; i++) {
            words[i] = scn.next();
        }
        scn.close();
        solution(arr, words, 0);

    }

    public static void display(char[][] arr) {
        for (int row = 0; row < arr.length; row++) {
            for (int col = 0; col < arr.length; col++) {
                System.out.print(arr[row][col] + "");
            }
            System.out.println();
        }
    }

    /*
     * For placing each word we have to check the arr[][] from the start
     * While traversing each cell of the arr[][] --> you have 2 options --> place
     * vertically, place horiczontally
     * But before checking if it (word) fits vertically of horizontally we must
     * check if it's '-' or word.charAt(i)
     */

    public static void solution(char[][] arr, String[] words, int vidx) {
        if (vidx == words.length) {
            display(arr);
            return;
        }

        String word = words[vidx];

        for (int row = 0; row < arr.length; row++) {
            for (int col = 0; col < arr[0].length; col++) {

                if (arr[row][col] == '-' || arr[row][col] == word.charAt(0)) {
                    if (canPlaceHorizontally(arr, word, row, col)) {
                        boolean visited[] = new boolean[word.length()];
                        placeWordHorizontally(arr, word, row, col, visited);
                        solution(arr, words, vidx + 1);
                        unPlaceWordHorizontally(arr, word, row, col, visited);
                    }

                    else if (canPlaceVertically(arr, word, row, col)) {
                        boolean visited[] = new boolean[word.length()];
                        placeWordVertically(arr, word, row, col, visited);
                        solution(arr, words, vidx + 1);
                        unPlaceWordVertically(arr, word, row, col, visited);
                    }
                }

            }
        }

    }

    public static boolean canPlaceHorizontally(char[][] arr, String word, int row, int col) {
        // if there exists a cell then it must be '+' and if it don't exits then very
        // good
        if (col - 1 >= 0 && arr[row][col - 1] != '+')
            return false;

        // if (col + word.length() != arr[0].length && col + word.length() != '+')

        if (col + word.length() < arr[0].length && arr[row][col + word.length()] != '+')
            return false;

        int i;
        for (i = 0; i < word.length(); i++) {
            // if (arr[row][i + col] != word.charAt(i) || arr[row][i + col] == '+')
            // return false;

            if ((arr[row][i + col] == word.charAt(i) || arr[row][i + col] == '-'))
                continue;
            else
                return false;
        }

        /* YOU CAN ALSO DO THE FOLLOWING TO CHECK THE LAST */
        // if (i + col < arr[0].length && arr[row][i + col] != '+') {
        // return false;
        // }

        return true;
    }

    public static void placeWordHorizontally(char[][] arr, String word, int row, int col, boolean visited[]) {
        for (int i = 0; i < word.length(); i++) {
            if (arr[row][col + i] == '-') {
                visited[i] = true;
            }
            arr[row][col + i] = word.charAt(i);
        }
    }

    public static void unPlaceWordHorizontally(char[][] arr, String word, int row, int col, boolean visited[]) {
        for (int i = 0; i < word.length(); i++) {
            if (visited[i] == true) {
                arr[row][col + i] = '-';
            }
        }
    }

    public static boolean canPlaceVertically(char[][] arr, String word, int row, int col) {
        // if there exists a cell then it must be '+' and if it don't exits then very
        // good
        if (row - 1 >= 0 && arr[row - 1][col] != '+')
            return false;

        // if (row + word.length() != arr.length && row + word.length() != '+') // this
        // is wrong
        if (row + word.length() < arr.length && row + arr[row + word.length()][col] != '+') // this is wrong
            return false;

        int i;
        for (i = 0; i < word.length(); i++) {

            // if (arr[row + i][col] != word.charAt(i) || arr[row + i][col] == '+')
            // return false;

            /* 
             * ABOVE CONDITION IS WRONG -- BELOW IS CORRECT
             * THE ABOVE COND. WILL ALWAYS BE TRUE -- AND 'FALSE' WILL ALWAYS BE RETURNED
             * SO YOUR canPlaceVertically is always false
             * 
             * NOTE : WHEN USING (OR)(||) MAKE SURE YOU WRITE 
             * vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
             * --> FAVOURABLE CONDITION <-- (favourable condition 1 || falvourable cond. 2 || fav. cond. 3 || .... so on ... )
             * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
             * 
             * NOTE : WHEN USING (AND)(&&) MAKE SURE YOU WRITE 
             * vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
             * --> UNFAVOURABLE CONDITION <-- (unfavourable condition 1 &&  unfalvourable cond. 2 &&  unfav. cond. 3 && .... so on ... )
             * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
             * 
             */
            if ((arr[i + row][col] == word.charAt(i) || arr[i + row][col] == '-'))
                continue;
            else
                return false;
        }

        /* YOU CAN ALSO THE THE FOLLOWING -- IT'S CORRECT */
        // if (i + row < arr[0].length && arr[i+row][col] != '+')
        // {
        // return false;
        // }

        return true;
    }

    public static void placeWordVertically(char[][] arr, String word, int row, int col, boolean visited[]) {
        for (int i = 0; i < word.length(); i++) {
            if (arr[row + i][col] == '-') {
                visited[i] = true;
            }
            arr[row + i][col] = word.charAt(i);
        }
    }

    public static void unPlaceWordVertically(char[][] arr, String word, int row, int col, boolean visited[]) {
        for (int i = 0; i < word.length(); i++) {
            if (visited[i] == true) {
                arr[row + i][col] = '-';
            }
        }
    }

}
