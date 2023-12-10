/*============================================================================================================
  CATEGORY: 1 src, m destinations 
            - ques 1 of 3
============================================================================================================*/

/*============================================================================================================
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
