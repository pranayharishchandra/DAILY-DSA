https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954

/*============================================================================================================
    CATEGORY: DP ON SUBSEQUENCE
============================================================================================================*/



/*============================================================================================================
    SOLUITON - 1: MEMOIZATION - stupid function call
            dp -> int type, not bool type, because we need -1, 
            that is the 3rd value other than true and false to know that
            if we have already computed the answer for that cell
============================================================================================================*/

// memoization solution
bool f(int n, int k, vector<int>& arr, vector<vector<int>>& dp) {

    // keeping "true" on the top
    if (k == 0) return true;
    
    // out of bound
    if (n == -1) 
        return false;
    
    // base case
    if (k <  0) return false;

    if (dp[n][k] != -1) return dp[n][k];

    bool take    = f(n-1, k - arr[n], arr, dp);
    bool notTake = f(n-1, k, arr, dp);

    return dp[n][k] = take || notTake;
}

// n -> number of elements in array
// k -> target
// dp -> [n][target + 1]

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp (n, vector<int> (k+1, -1)); 

    return f(n-1, k, arr, dp);
}

/*============================================================================================================
    SOLUITON - 2: MEMOIZATION - smart function call
            dp -> int type, not bool type, because we need -1, 
            that is the 3rd value other than true and false to know that
            if we have already computed the answer for that cell
============================================================================================================*/

// memoization solution
bool f(int n, int k, vector<int>& arr, vector<vector<int>>& dp) {

    // keeping "true" on the top
    if (k == 0) return true;

    // handling out of bound index (i.e. negative index)
    if (n == 0) 
        return (k - arr[0] == 0);

    if (dp[n][k] != -1) return dp[n][k];

    // handeling out of bound target (i.e. negative target)
    bool take    = false;
    if (k - arr[n] >= 0) 
        take = f(n-1, k - arr[n], arr, dp);

    bool notTake = f(n-1, k, arr, dp);

    return dp[n][k] = take || notTake;
}

// n -> number of elements in array
// k -> target
// dp -> [n][target + 1]

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp (n, vector<int> (k+1, -1)); 

    return f(n-1, k, arr, dp);
}


/*============================================================================================================
    SOLUITON - 3: TABULATION - tabulating solution 3
============================================================================================================*/

bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    if (k == 0) return true;
    if (n == 0) return false; 
    
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    
    // base case - if the target is 0, mark true
    for (int i = 0; i < n; i++) 
        dp[i][0] = true;

    // base case - initallize the first row 
    if (arr[0] <= k) 
        dp[0][arr[0]] = true;
    
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) 
        {
            bool notTaken = dp[ind - 1][target];
            bool taken = (arr[ind] <= target) ? dp[ind - 1][target - arr[ind]] : false;
            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

/*============================================================================================================
    SOLUITON - 4: TABULATION - space optimaization sol 3
============================================================================================================*/

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> prev(k+1, false);
    
    // base case - if the target is 0, mark true
    prev[0] = true;

    // base case - initallize the first row 
    if (arr[0] <= k) 
        prev[arr[0]] = true;
    
    for (int ind = 1; ind < n; ind++) {
        vector<bool> curr(k+1, false);
        curr[0] = true; // don't forget to mark this true
        for (int target = 1; target <= k; target++) 
        {
            bool notTaken = prev[target];
            bool taken = (arr[ind] <= target) ? prev[target - arr[ind]] : false;
            curr[target] = notTaken || taken;
        }
        prev = curr;
    }

    return prev[k];
}


/*============================================================================================================
    SOLUITON - 5: TABULATION - most space optimaization sol 4
============================================================================================================*/


bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> prev(k+1, false);
    
    // base case - if the target is 0, mark true
    prev[0] = true;

    // base case - initallize the first row 
    if (arr[0] <= k) 
        prev[arr[0]] = true;
    
    for (int ind = 1; ind < n; ind++) {
        // this loop must be from (right to left) (k to 0) 
        // if you go (0 to k) then it will consider same number 2 or more times 
        // as you are using only 1 vector "prev" to store
        // so "prev" contains current row answers also, and prev row answers also
        // prev row answers: when we don't have computed
        // curr row answers when we have used prev row to find answer
        // so we are coming right to left, to make sure we only use the prev rows answers
        // and not use the results we have stored in the current iteration
        for (int target = k; target >= 0; target--) 
        {
            bool notTaken = prev[target];
            bool taken    = (target - arr[ind] >= 0 ) ? prev[target - arr[ind]] : false;
            prev[target]  = notTaken || taken;
        }
    }

    return prev[k];
}

/*============================================================================================================
    SOLUITON - 6: TABULATION - most time and space optimized solution - best solution
============================================================================================================*/


bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> prev(k+1, false);
    
    // base case - if the target is 0, mark true
    prev[0] = true;

    // base case - initallize the first row 
    if (arr[0] <= k) 
        prev[arr[0]] = true;
    
    for (int ind = 1; ind < n; ind++) {
        for (int target = k; target >= arr[ind]; target--) 
        {
            bool notTaken = prev[target];
            bool taken    = (target - arr[ind] >= 0 ) ? prev[target - arr[ind]] : false;
            prev[target]  = notTaken || taken;
        }
    }

    return prev[k];
}














