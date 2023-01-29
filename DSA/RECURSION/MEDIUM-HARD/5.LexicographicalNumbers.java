import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        scn.close();

        // write your code here
        // printLexicographicalNumbers(n, 1);
        for (int i = 1; i <= 9; i++) {
            printLexicographicalNumbers(n, i);

        }

    }

    static void printLexicographicalNumbers(int limit, int curr) {
        if (curr > limit) {
            return;
        }

        System.out.println(curr);

        for (int i = 0; i < 9; i++) {
            curr = curr * 10 + i;
            printLexicographicalNumbers(limit, curr);
            curr = curr / 10;
        }

    }

}
