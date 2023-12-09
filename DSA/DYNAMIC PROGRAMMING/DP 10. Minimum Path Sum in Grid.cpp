/*============================================================================================================
    SOLUTION - 1 : MOMOIZATION
    note: don't use INT_MAX, use 1e9

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
    
        int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
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
