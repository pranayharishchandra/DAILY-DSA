/*============================================================================================================
  CATEGORY: 3D DP
            -- alice and bob, both travelling on the same grid
            -- they both are comming down by 1 step every time so i+1 everytime
            -- so "i" will be common in both
            -- for columns, j1, j2 -- for alice and bob
============================================================================================================*/


/*============================================================================================================
                   TIME COMPLEXITY    SPACE COMPLEXITY
    recursive:     O(9^(n * m))       O(n) maximum height of the grid  
    tabulation:    
    
============================================================================================================*/



/*============================================================================================================
    APPROCH:
        WRONG WAY: 
            calc alice and bob path seperately and then find out the 
        CORRECT WAY:
            calc both together, and just put conditions,
                if they are in the same cell, i.e. "j1 == j2" then add it only once
                else add both the cells
============================================================================================================*/



/*============================================================================================================
    SOLUTION - 1: RECURSIVE - stupid function call
============================================================================================================*/

// recursive solution
int f(int i, int j1, int j2, int n, int m,
        vector<vector<int>> &grid) {

    // out of bound -- to handle stupid funciton call
    if (j1>m || j2>m || j1<0 || j2<0)
        return -1e9;
     
    // base cases
    if (i==n-1) 
        if (j1==j2) 
            return grid[i][j1];
        else 
            return grid[i][j1] + grid[i][j2];


    int maxi = 0;
    for (int dj1=-1; dj1 <= 1; dj1++) {
        for (int dj2=-1; dj2 <= 1; dj2++) {
            int curr = f(i+1, j1+dj1, j2+dj2, n, m, grid);
            if (curr != -1e9)
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + curr);   
                else 
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + curr);    
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return f(0, 0, m-1, n, m, grid);
}



/*============================================================================================================
    SOLUTION - 2: RECURSIVE - smart function call
============================================================================================================*/

// recursive solution
int f(int i, int j1, int j2, int n, int m,
        vector<vector<int>> &grid) {

    // // out of bound -- to handle stupid funciton call
    // if (j1>m || j2>m || j1<0 || j2<0)
    //     return -1e9;

    // base cases
    if (i==n-1) 
        if (j1==j2) 
            return grid[i][j1];
        else 
            return grid[i][j1] + grid[i][j2];


    int maxi = 0;
    for (int dj1=-1; dj1 <= 1; dj1++) {
        for (int dj2=-1; dj2 <= 1; dj2++) {

            int curr;

            if (!(j1+dj1 >= m || j2+dj2 >= m || j1+dj1 < 0 || j2+dj2 < 0))
                curr = f(i+1, j1+dj1, j2+dj2, n, m, grid);
            else 
                curr = -1e9;

            if (curr != -1e9)
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + curr);   
                else 
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + curr);    
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return f(0, 0, m-1, n, m, grid);
}


/*============================================================================================================
    SOLUTION - 3.1: MEMOIZATION - solution 2 memo
============================================================================================================*/

// memoization solution
int f(int i, int j1, int j2, int n, int m,
        vector<vector<vector<int>>> &dp,
        vector<vector<int>> &grid) {

    // // out of bound
    // if (j1>m || j2>m || j1<0 || j2<0)
    //     return -1e9;

    // base cases
    if (i==n-1) 
        if (j1==j2) 
            return grid[i][j1];
        else 
            return grid[i][j1] + grid[i][j2];

    if (dp[i][j1][j2] != -1) 
        return dp[i][j1][j2];


    int maxi = 0;
    // for all 9 combination - dj1 -> delta j1 -> change in j1
    for (int dj1=-1; dj1 <= 1; dj1++) {
        for (int dj2=-1; dj2 <= 1; dj2++) {

            int curr;

            if (!(j1+dj1>=m || j2+dj2>=m || j1+dj1<0 || j2+dj2<0))
                curr = f(i+1, j1+dj1, j2+dj2, n, m, dp, grid);
            else 
                curr = -1e9;

            if (curr != -1e9)
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + curr);   
                else 
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + curr);    
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
    return f(0, 0, m-1, n, m, dp, grid);
}


/*============================================================================================================
    SOLUTION - 3.2: MEMOIZATION - same above solution -- just with better -- code readability
============================================================================================================*/

// recursive solution with memoization
int f(int i, int j1, int j2, int n, int m,
        vector<vector<vector<int>>> &dp,
        vector<vector<int>> &grid) {

    // base cases
    if (i == n - 1) 
        return (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);

    if (dp[i][j1][j2] != -1) 
        return dp[i][j1][j2];

    int maxi = 0;

    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int next_j1 = j1 + dj1;
            int next_j2 = j2 + dj2;

            if (next_j1 >= 0 && next_j1 < m && next_j2 >= 0 && next_j2 < m) {
                int curr = f(i + 1, next_j1, next_j2, n, m, dp, grid);
                if (curr != -1e9) {
                    if (j1 == j2)
                        maxi = max(maxi, grid[i][j1] + curr);
                    else
                        maxi = max(maxi, grid[i][j1] + grid[i][j2] + curr);
                }
            }
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return f(0, 0, m - 1, n, m, dp, grid);
}




/*============================================================================================================
    SOLUTION - 4: TABULATION - tabulation of 3.2
============================================================================================================*/

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));

    // basecase -> (tabulation => bottom up)
    // in tabulation we start from the basecase 
    // and go to the source from othe destination
    // thus it's called bottom up
    // means from dest (basecase) to the src
    for (int j1 = 0; j1 < m; j1++) 
        for (int j2 = 0; j2 < m; j2++) 
            if (j1==j2) 
                dp[n-1][j1][j2] = grid[n-1][j1];
            else 
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];

    for (int i = n-2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                int maxi = 0;
                // for all 9 combination - dj1 -> delta j1 -> change in j1
                for (int dj1=-1; dj1 <= 1; dj1++) {
                    for (int dj2=-1; dj2 <= 1; dj2++) {

                        int curr;

                        if (!(j1+dj1 >= m || j2+dj2 >= m || j1+dj1 < 0 || j2+dj2 < 0))
                            curr = dp[i+1][j1+dj1][j2+dj2];
                        else 
                            curr = -1e9;

                        if (curr != -1e9)
                            if (j1 == j2)
                                maxi = max(maxi, grid[i][j1] + curr);   
                            else 
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + curr);    
                    }
                }
                dp[i][j1][j2] = maxi;
                
            }
        }
    }
    
    // alice starts at (0,0) and bob at (0,m-1) -> [0][0][m-1]
    return dp[0][0][m-1];
}



/*============================================================================================================
    SOLUTION - 5: TABULATION - space optimaization of SOULTION - 4
============================================================================================================*/

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));

    vector<vector<int>> prev (vector<vector<int>> (m, vector<int> (m)));

    for (int j1 = 0; j1 < m; j1++) 
        for (int j2 = 0; j2 < m; j2++) 
            if (j1==j2) 
                prev[j1][j2] = grid[n-1][j1];
            else 
                prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];

    for (int i = n-2; i >= 0; i--) {
        vector<vector<int>> currrr (vector<vector<int>> (m, vector<int> (m)));
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                int maxi = 0;
                // for all 9 combination - dj1 -> delta j1 -> change in j1
                for (int dj1=-1; dj1 <= 1; dj1++) {
                    for (int dj2=-1; dj2 <= 1; dj2++) {

                        int curr;

                        if (!(j1+dj1 >= m || j2+dj2 >= m || j1+dj1 < 0 || j2+dj2 < 0))
                            curr = prev[j1+dj1][j2+dj2];
                        else 
                            curr = -1e9;

                        if (curr != -1e9)
                            if (j1 == j2)
                                maxi = max(maxi, grid[i][j1] + curr);   
                            else 
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + curr);    
                    }
                }
                currrr[j1][j2] = maxi;
            }
        }
        prev = currrr;
    }
    
    // alice starts at (0,0) and bob at (0,m-1) -> [0][0][m-1]
    return prev[0][m-1];
}




