/*============================================================================================================
    Variable Starting and Ending Points | DP on Grids

    max path sum if we end at (n-1, 0) is "p"
    max path sum if we end at (n-1, 1) is "q"
    .
    .
    .
    .
    max path sum if we end at (n-1, m-1) is "t"

    now take the max of "p, q, ..... t" and that will be your answer
    
============================================================================================================*/

/*============================================================================================================
    so here we will start from the (n-1, j)th col and will go till all the columns of the top row
    and then we will have the base case in the top row
    then will backtrack down again after hitting the base case and this is how we will get our answer

    so one src and "m" destinations
    we will do this "m" times
============================================================================================================*/



/*============================================================================================================
    SOLUTION 1 - MEMOIZATION - (stupid function call) - TLE in leetcode
============================================================================================================*/


class Solution {
    int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix, 
                        vector<vector<int>> &dp) {
        if (j < 0 || j >= m)
            return 1e9;
    
        if (i == 0)
            return matrix[0][j];
    
        if (dp[i][j] != -1)
            return dp[i][j];
    
        int up            = getMinUtil(i - 1,     j, m, matrix, dp);
        int leftDiagonal  = getMinUtil(i - 1, j - 1, m, matrix, dp);
        int rightDiagonal = getMinUtil(i - 1, j + 1, m, matrix, dp);
    
        return dp[i][j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n, vector<int>(m, -1));
    
        int mini = INT_MAX;
    
        for (int j = 0; j < m; j++) {
            int ans = getMinUtil(n - 1, j, m, matrix, dp);
            mini = min(mini, ans);
        }
    
        return mini;
    }
};



/*============================================================================================================
    SOLUTION 2 - MEMOIZATION - (smart function call) - TLE in leetcode

    -- one src and "m" destinations
    -- then taking the best answer by iterting over the all 'm' srcs
============================================================================================================*/

class Solution {
    int getMinUtil(int i, int j, int m, vector<vector<int>> &matrix, 
                        vector<vector<int>> &dp) {
        // if (j < 0 || j >= m)
        //     return 1e9;
    
        if (i == 0)
            return matrix[0][j];
    
        if (dp[i][j] != -1)
            return dp[i][j];
    
        int up            = getMinUtil(i - 1,     j, m, matrix, dp);
        int leftDiagonal  = (j-1 >= 0) ? getMinUtil(i - 1, j - 1, m, matrix, dp) : 1e9;
        int rightDiagonal = (j+1 <  m) ? getMinUtil(i - 1, j + 1, m, matrix, dp) : 1e9;
    
        return dp[i][j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n, vector<int>(m, -1));
    
        int mini = INT_MAX;
    
        for (int j = 0; j < m; j++) {
            int ans = getMinUtil(n - 1, j, m, matrix, dp);
            mini = min(mini, ans);
        }
    
        return mini;
    }
};



/*============================================================================================================
    SOLUTION 3 - TABULATION - (using solution - 2)
============================================================================================================*/

class Solution {
    int getMinUtil(int sc, int n, int m, vector<vector<int>> &matrix, 
                                                        vector<vector<int>> &dp) {
    
        // sc -> src col
        // top to bottom -- src to dest
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j]; // base case
    
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
    
                int up            = dp[i-1][j];
                int leftDiagonal  = (j-1 >= 0) ? dp[i-1][j-1] : 1e9;
                int rightDiagonal = (j+1 <  m) ? dp[i-1][j+1] : 1e9;
    
                dp[i][j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
            }
        }
    
        int mini = dp[n-1][0];
        for (int j = 0; j < m; j++)
            mini = min(dp[n-1][j], mini);
    
        return mini;
        
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n, vector<int>(m, -1));
    
        int mini = INT_MAX;
    
        for (int j = 0; j < m; j++) {
            int ans = getMinUtil(j, n, m, matrix, dp);
            mini = min(mini, ans);
        }
    
        return mini;
    }
};


/*============================================================================================================
    SOLUTION 4 - TABULATION (space optimised)
============================================================================================================*/

class Solution {
int getMinUtil(int sc, int n, int m, vector<vector<int>> &matrix) {

    vector<int> prev(m);

    // sc -> src col
    // top to bottom -- src to dest
    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++) {
        vector<int> curr(m);
        for (int j = 0; j < m; j++) {

            int up            = prev[j];
            int leftDiagonal  = (j-1 >= 0) ? prev[j-1] : 1e9;
            int rightDiagonal = (j+1 <  m) ? prev[j+1] : 1e9;

            curr[j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }

    int mini = prev[0];
    for (int j = 0; j < m; j++)
        mini = min(prev[j], mini);

    return mini;
    
}

int getMinPathSum(vector<vector<int>> &matrix) {

}

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int mini = INT_MAX;

    for (int j = 0; j < m; j++) {
        int ans = getMinUtil(j, n, m, matrix);
        mini = min(mini, ans);
    }

    return mini;
    }
};


/*============================================================================================================
    SOLUTION 5 - TABULATION (space optimised)

    why the following is also working

    // base case
    for (int j = 0; j < m; j++)
        if (j == sc) 
            prev[sc] = matrix[0][sc];
        else 
            prev[j]  = 1e9;
============================================================================================================*/


class Solution {
int getMinUtil(int sc, int n, int m, vector<vector<int>> &matrix) {

    vector<int> prev(m);

    // sc -> src col
    // top to bottom -- src to dest
    for (int j = 0; j < m; j++)
        if (j == sc) // base case
            prev[sc] = matrix[0][sc];
        else 
            prev[j]  = 1e9;

    for (int i = 1; i < n; i++) {
        vector<int> curr(m);
        for (int j = 0; j < m; j++) {

            int up            = prev[j];
            int leftDiagonal  = (j-1 >= 0) ? prev[j-1] : 1e9;
            int rightDiagonal = (j+1 <  m) ? prev[j+1] : 1e9;

            curr[j] = matrix[i][j] + min(up, min(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }

    int mini = prev[0];
    for (int j = 0; j < m; j++)
        mini = min(prev[j], mini);

    return mini;
    
}

int getMinPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int mini = INT_MAX;

    for (int j = 0; j < m; j++) {
        int ans = getMinUtil(j, n, m, matrix);
        mini = min(mini, ans);
    }

    return mini;
}

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return getMinPathSum(matrix);
    }
};


