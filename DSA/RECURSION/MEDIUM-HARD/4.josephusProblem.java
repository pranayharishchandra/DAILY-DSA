import java.io.*;
import java.util.*;

public class Main {

    public static int solution(int n, int k) {
        // write your code here
        if (n == 1)
            return 0;

        int alivePersonPrevIdx = solution(n - 1, k); // index of our ans when n - 1 people were alive
        
        int alivePersonCurrIdx = (alivePersonPrevIdx * k) % n; // prev ans was prevAns when n - 1 person were alive ..
                                                               // when we do backtracking and come back to n people
                                                               // alive .. the person which will be alive in when (n-1)
                                                               // people alive will be found out by using the formula
        // ( prevAns + k ) % n <-- idx of the person who will be alive in the next round

        return alivePersonCurrIdx;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int k = scn.nextInt();
        System.out.println(solution(n, k));
    }

}
