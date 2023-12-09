/*============================================================================================================
    APPROACH: SOLUTION - 1, 2

    Q1) WHY ARE WE GOING LEFT, UP when the question is telling us to go RIGHT, DOWN
    
    we are calling from the last cell of the matrix --> n-1, m-1
    and we are going to                             -->   0, 0

    0,0 we have a base case

    then again we are coming back to n-1, m-1

    SO, SINCE WE HAVE EX-CHANGED THE STARTING POINTS, THUS DOWN becomes UP, RIGHT becomes LEFT

    Q2) WHEN USING 1e9?
    
    since here we are talking about the min sum: 1e9
    if it was asked max sum: -1e9
    if it was asked ways/ number of ways: 0

    Q3) WHY USING INT_MAX GIVES WRONG ANSWER BUT 1e9 gives correct answer?

        The memoization Approach please don't take INT_MAX in the base condition for 
        (i<0 || j<0) as when we will reach the base condition it will be added to the value 
        of previous state which is grid[i][j] , and it will lead to integer overflow ,
        so just please use a bigger number like 1e9 as striver has done. In case anyone is wondering

============================================================================================================*/



/*============================================================================================================
    SOLUTION - 1 : MOMOIZATION - dumb function call
    note: don't use INT_MAX, use 1e9

    TC: mxn
    SC: mxn + (m-1 + n-1) i.e. path le

    reason : The memoization Approach please don't take INT_MAX in the base condition for 
        (i<0 || j<0) as when we will reach the base condition it will be added to the value 
        of previous state which is grid[i][j] , and it will lead to integer overflow ,
        so just please use a bigger number like 1e9 as striver has done. In case anyone is wondering
============================================================================================================*/
class Solution {
public:
    // Helper function to find the minimum sum path 
    // from (i, j) to (0, 0) in the matrix

    int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    
        if (i == 0 && j == 0)
            return matrix[0][0];
        
        if (i < 0 || j < 0)
            return 1e9; 
        
        if (dp[i][j] != -1)
            return dp[i][j]; 
    
        int up   = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
        int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);
    
        return dp[i][j] = min(up, left);
    }
    
    int minPathSum( vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); 
        return minSumPathUtil(n - 1, m - 1, matrix, dp); 
    }

};



/*============================================================================================================
    SOLUTION - 2 : MOMOIZATION - smart function call 
    TC: mxn
    SC: mxn + (m-1 + n-1) 
    
    recursion stack space = O(path len) = O(m-1 + n-1)
============================================================================================================*/
class Solution {
public:
    int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

        if (i == 0 && j == 0) {
            return matrix[0][0];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = 1e9;
        if (i-1 >= 0) up = minSumPathUtil(i - 1, j, matrix, dp);
        
        int left = 1e9;
        if (j-1 >= 0) left = minSumPathUtil(i, j - 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minSumPathUtil(n - 1, m - 1, matrix, dp);
    }
};

/*============================================================================================================
    SOLUTION - 3 : TABULATION - (TABULIZING SOLUTION 2)

    here i am going from 0,0 to n-1, m-1
    because answer is not gonna change if i go from  (0,0)     to (n-1, m-1) 
                                                  or (n-1,m-1) to (0,0)

============================================================================================================*/
class Solution {
public:
    int minSumPath(int n, int m, vector<vector<int>> &matrix) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
    
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                
                if (i == 0 && j == 0)
                    dp[i][j] = matrix[i][j];
                    
                else {
                    int up   = matrix[i][j] + ((i-1 >= 0) ? dp[i - 1][j] : 1e9);
                    int left = matrix[i][j] + ((j-1 >= 0) ? dp[i][j - 1] : 1e9);
                    
                    dp[i][j] = min(up, left);
                }
    
        return dp[n - 1][m - 1];
    }
};

/*============================================================================================================
    SOLUTION - 4 : TABULATION 

============================================================================================================*/
class Solution {
public:
    int minPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n, vector<int>(m, -1));
    
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                
                if (i == 0 && j == 0)
                    dp[i][j] = matrix[i][j];
                    
                else if (i == 0)
                    dp[i][j] = matrix[i][j] + dp[i][j - 1];
                    
                else if (j == 0)
                    dp[i][j] = matrix[i][j] + dp[i - 1][j];
                    
                else
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
    
        return dp[n - 1][m - 1];
    }
};

/*============================================================================================================
    SOLUTION - 4 : TABULATION -- space optimised
============================================================================================================*/
class Solution {
public:
    int minSumPath(int n, int m, vector<vector<int>> &matrix) {
        vector<int> prev(m, 0);
    
        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    temp[j] = matrix[i][j];
                else {
                    int up = matrix[i][j] + ((i > 0) ? prev[j] : 1e9);
                    int left = matrix[i][j] + ((j > 0) ? temp[j - 1] : 1e9);
                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }
    
        return prev[m - 1];
    }
}
/*============================================================================================================
    SOLUTION - 5 : TABULATION -- most space optimised
============================================================================================================*/
class Solution {
public:
    int minPathSum(vector<vector<int>> &matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
    
        // Use a 1D array for the dp table
        vector<int> dp(m, -1);
    
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                
                if (i == 0 && j == 0)
                    dp[j] = matrix[i][j];
                    
                else if (i == 0)
                    dp[j] = matrix[i][j] + dp[j - 1];
                    
                else if (j == 0)
                    dp[j] = matrix[i][j] + dp[j];
                    
                else
                    dp[j] = matrix[i][j] + min(dp[j], dp[j - 1]);

        
        return dp[m - 1];
    }
};





