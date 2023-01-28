
// import java.io.*;
import java.util.*;

public class Main {
    public static void display(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void solveSudoku(int[][] board, int row, int col) {
        // write your code here

        // if going out of board then shift to next line
        if (col == board[0].length) {
            row = row + 1;
            col = 0;
        }

        // if traversed whole board -- display board
        if (row == board.length) {
            display(board);
            return;
        }

        if (board[row][col] != 0) {
            solveSudoku(board, row, col + 1);
        } else {
            for (int value = 1; value <= 9; value++) {

                if (isValid(board, row, col, value)) {
                    board[row][col] = value;
                    solveSudoku(board, row, col + 1);
                    board[row][col] = 0;
                }

            }
        }

    }

    public static boolean isValid(int[][] board, int row, int col, int value) {

        // checking vertically
        for (int i = 0; i < board.length; i++) {
            if (board[i][col] == value) {
                return false;
            }
        }

        // checking horizontally
        for (int i = 0; i < board[0].length; i++) {
            if (board[row][i] == value) {
                return false;
            }
        }

        // checking the block
        int x = (row / 3) * 3;
        int y = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + x][j + y] == value) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int[][] arr = new int[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                arr[i][j] = scn.nextInt();
            }
        }
        scn.close();

        solveSudoku(arr, 0, 0);

        // display(arr);
    }
}
