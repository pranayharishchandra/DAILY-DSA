// RECURSION =============================================================================================
int cs(int n){
    // write your code here
    if (n == 0) return 1; // one way to reach from 0 to 0
    if (n < 0 ) return 0; // no way to reach from -ve to 0 with +ve steps
    
    // following will give me total paths.. since we have set our base case like that
    int call1 = cs(n - 1);
    int call2 = cs(n - 2);
    int call3 = cs(n - 3);
    
    int total_ways = call1 + call2 + call3; // till current n to 0
    return total_ways;

}

// DP =============================================================================================
int cs_helper(int n, vector<int> &dp)
{
    if (n == 0) return 1; // one way to reach from 0 to 0
    if (n < 0 ) return 0; // no way to reach from -ve to 0 with +ve steps
    
    if (dp[n] != -1) return dp[n];
    
    // following will give me total paths.. since we have set our base case like that
    int call1 = cs_helper(n - 1, dp);
    int call2 = cs_helper(n - 2, dp);
    int call3 = cs_helper(n - 3, dp);
    
    int total_ways = call1 + call2 + call3; // total ways till current n to 0
    dp[n] = total_ways; 
    
    return total_ways;
}

int cs(int n){
    // write your code here
    vector<int> dp(n + 1, -1); // total stairs = n
                               // vector for n to 0 i.e. n+1
    int ans = cs_helper(n, dp);
    return ans;

}

// TABULATION =============================================================================================
int cs_helper(int n, vector<int> &dp)
{ 
    if (n == 0) return 1; // one way to reach from 0 to 0
    if (n < 0 ) return 0; // no way to reach from -ve to 0 with +ve steps
    
    if (dp[n] != -1) return dp[n];
    
    // following will give me total paths.. since we have set our base case like that
    int call1 = cs_helper(n - 1, dp);
    int call2 = cs_helper(n - 2, dp);
    int call3 = cs_helper(n - 3, dp);
    
    int total_ways = call1 + call2 + call3; // total ways till current n to 0
    dp[n] = total_ways; 
    
    return total_ways;
}

int cs(int n)
{
    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    { 
        dp[i] = dp[i - 1];
        if (i > 1)
            dp[i] += dp[i - 2];
        if (i > 2)
            dp[i] += dp[i - 3];
    }
    return dp[n];
}

// SPACE OPTIMISED=============================================================================================
int cs_helper(int n, vector<int> &dp)
{ 
    if (n == 0) return 1; // one way to reach from 0 to 0
    if (n < 0 ) return 0; // no way to reach from -ve to 0 with +ve steps
    
    if (dp[n] != -1) return dp[n];
    
    // following will give me total paths.. since we have set our base case like that
    int call1 = cs_helper(n - 1, dp);
    int call2 = cs_helper(n - 2, dp);
    int call3 = cs_helper(n - 3, dp);
    
    int total_ways = call1 + call2 + call3; // total ways till current n to 0
    dp[n] = total_ways; 
    return total_ways;
}

int cs(int n)
{ 
    int prev = 1; // dp[0] = 1
    int prev2 = 0;// dp[-ve] = 0
    int prev3 = 0;// dp[-ve] = 0
  
    for (int i = 1; i <= n; i++)
    { 
        int curr = prev;
        if (i > 1)
            curr += prev2;
        if (i > 2)
            curr += prev3;
        
        prev3 = prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
