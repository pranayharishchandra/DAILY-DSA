/*============================================================================================================
  CATEGORY: 1 src, m destinations 
            - ques 1 of 3
============================================================================================================*/

/*============================================================================================================
    SOLUTION 1: MEMOIZATION -- (direction: up to down)
    TC: nxm or ( 1+2+ ... n = n*(n+1)/2 ) 
    SC: nxm 

    NOTE: 
        for RECURSIVE soluiton TC: (2 ^ (no of cell))
    
preferable to start from 1 source
m destinations is okay, since they can be handled by the basecase easily

so we are starting from (0,0) and going till the (n-1)th row
then we will backtrack and come to (0,0)


MORE TO KNOW: 
    the condition checks like (i+1 <= n-1 && j+1 <= m-1) 
    to prevent "OUT OF BOUND CASES" are not actually required
    since we can ""never go out of bound""
    since we are only going "down" and "diagonal" in the "triangle"

    BUT STILL I HAVE USED THEM 
        so i can  use the same code for rectangle as well
============================================================================================================*/
// t - triangle
// f - helper function

class Solution {
    int f(vector<vector<int>> & t, 
            vector<vector<int>> & dp, 
                int i, int j,
                int n, int m) {
    
        // base case -- last row
        if (i == n-1) {
            return t[i][j];
        }

        if (dp[i][j] != -1) 
            return dp[i][j];

        // you have 2 options
        // opt 1 - down
        int dwn  = (i+1 <= n-1)               ? f(t, dp, i+1, j, n, m)   : 1e9;

        // opt 2 - diagonal (right and down)
        int dgnl = (i+1 <= n-1 && j+1 <= m-1) ? f(t, dp, i+1, j+1, n, m) : 1e9;

        return dp[i][j] = t[i][j] + min(dwn, dgnl);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<vector<int>> dp (n, vector<int>(m, -1));

        return f(triangle, dp, 0, 0, n, m);

    }
};


/*============================================================================================================
    SOLUTION - 2 : TABULATION -- (direction: down to up)

    removed condition checks for out of bound... since they were not actually required for "TRIANGLE"

============================================================================================================*/
// t -- triangle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // "Initialize" the bottom row of the dp table
        dp[n-1] = t[n-1];

        // Build the dp table from "bottom to top"
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Calculate the minimum path sum considering moving down and moving diagonally to the right and down
                int down     = t[i][j] + dp[i + 1][j];
                int diagonal = t[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }

        // The result is stored in the top element of the dp table
        return dp[0][0];
    }
};


/*============================================================================================================
    SOLUTION - 3 : TABULATION -- (direction: UP to DOWN)

    removed condition checks for out of bound... since they were not actually required for "TRIANGLE"

============================================================================================================*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the dp table with the top row of the triangle
        dp[0][0] = t[0][0];

        // Build the dp table from top to bottom
        for (int i = 1; i < n; i++) {          
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    dp[i][0] = t[i][0] + dp[i - 1][0];     // Only one option - moving down vertically
                else if (i == j)
                    dp[i][i] = t[i][i] + dp[i - 1][i - 1]; // Only one option - moving down diagonally to the left
                else
                    dp[i][j] = t[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }

        }

        // Find the minimum value in the bottom row of the dp table
        int minSum = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            minSum = min(minSum, dp[n - 1][j]);
        }

        return minSum;
    }
};

/*============================================================================================================
    SOLUTION - 4 : TABULATION -- SPACE OPTIMAIZATION 
                              -- whenever there is i-1 or row - 1
                              -- in those cases we can easily do space optimaization using prev, curr

    removed condition checks for out of bound... since they were not actually required for "TRIANGLE"

============================================================================================================*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        int n = t.size();
        vector<int> prev(n);

        // Initialize the dp table with the top row of the triangle
        prev[0] = t[0][0];
        // prev = t[0];

        // Build the dp table from top to bottom
        for (int i = 1; i < n; i++) {          
            vector<int> curr(n);
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    curr[0] = t[i][0] + prev[0];     // Only one option - moving down vertically
                else if (i == j)
                    curr[i] = t[i][i] + prev[i - 1]; // Only one option - moving down diagonally to the left
                else
                    curr[j] = t[i][j] + min(prev[j], prev[j - 1]);
            }
            prev = curr;
        }

        // Find the minimum value in the bottom row of the dp table
        int minSum = prev[0];
        for (int j = 1; j < n; j++) {
            minSum = min(minSum, prev[j]);
        }

        return minSum;
    }
};

/*============================================================================================================
    SOLUTION - 5 (NOT POSSIBLE) : TABULATION -- MOST SPACE OPTIMAIZATION (not possible in this question)
                                -- the most optimal solution not possible
                                -- like it was in the PREVIOUS PROBLEM
                                -- because .. read below
 
    In the previous question: 
        consider a cell (i,j)
        we are moving/considering 2 paths -- left and top, 
        so the left of the jth col cell in that row got updated 
        since jth cell in the 1d dp is still holds the answer for the top cell i.e. (i-1,j)
        so the (i,j) cell can take it's left and top cells answers from the 1d dp
        and after updating we were storing the value in jth cell of dp, and loosing the answer of 
        (i-1,j)th cell

    In this question:
        we are moving diagonal(left + up) and left
        so here if we update the (j-1)th cell of 1d dp
        the the jth cell will not be able to know the answer of diagonal(left+up)
        thus we require 2 level of dp,
        i.e. prev_row and curr_row

============================================================================================================*/
