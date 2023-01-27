import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[m][n];

        for (int i = 0; i < arr.length; i++) {
            String parts = br.readLine();
            for (int j = 0; j < arr[0].length; j++) {
                arr[i][j] = Integer.parseInt(parts.split(" ")[j]);
            }
        }

        // write your code here
        // graph is basically a tress supported by visited
        boolean visited[][] = new boolean[arr.length][arr[0].length];
        int countIslands = 0;

        for (int row = 0; row < arr.length; row++) {
            for (int col = 0; col < arr[0].length; col++) {
                if (visited[row][col] == false && arr[row][col] == 0) {
                    System.out.print(".");
                    // call the funtion
                    dfs(arr, visited, row, col);
                    countIslands++;
                }

            }

        }
        System.out.println(countIslands);
    }

    public static void dfs(int[][] arr, boolean[][] visited, int row, int col) {
        if (row < 0 || row >= arr.length || col < 0 || col >= arr[0].length || visited[row][col] == true
                || arr[row][col] == 1)
            return;

        visited[row][col] = true;

        dfs(arr, visited, row + 1, col);
        dfs(arr, visited, row - 1, col);
        dfs(arr, visited, row, col - 1);
        dfs(arr, visited, row, col + 1);
    }

}
