/*============================================================================================================
    APPROACH: SOLUTION - 1, 2
    we are calling from the last cell of the matrix --> n-1, m-1
    and we are going to                             -->   0, 0

    0,0 we have a base case

    then again we are coming back to n-1, m-1

    since here we are talking about the min sum: 1e9
    if it was asked max sum: -1e9
    if it was asked ways/ number of ways: 0

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



/*============================================================================================================
    SOLUTION - 2 : MOMOIZATION - smart function call 
    TC: mxn
    SC: mxn + (m-1 + n-1) i.e. path len
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
    
============================================================================================================*/



