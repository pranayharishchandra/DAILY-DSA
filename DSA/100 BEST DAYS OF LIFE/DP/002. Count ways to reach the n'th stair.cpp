https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    // top - down (from n to 0)
    int countWaysHelper(int n, vector<int> &dp)
    {
        // your code here
        int mod = 1e9 + 7; // this is wrong why
        if (n == 0 || n == 1) return 1; // 1 way to go from 0th to 0th stair
        if (n == 2) return 2;

        // if (n <  0) return 0;
        
        
        if (dp[n] != -1) return dp[n];
        // cout << n << " ";
        
        int left  = countWaysHelper(n - 1, dp);
        int right = countWaysHelper(n - 2, dp);
        
        int ans = (left + right) % mod;
        // cout << ans << " ";
        return dp[n] = ans;
    }
    
    // bottom up from 0 to n
    int tab(int n)
    {
        int mod = 1e9 + 7;
        vector<int> dp(n+1, - 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            if (i > 1) dp[i] += dp[i - 2];
            dp [i] = dp[i] % mod;
        }
        return dp[n];
    }
    
    // TABULATION SPACE OPTIMISED
    int tabOptmised(int n)
    {
        int mod = 1e9 + 7;
        
        int prev1 = 1, prev2 = 1;
        int curr  = 1; // if n < 2 then for loop will not run and answer will be 1
        
        for (int i = 2; i <= n; i++)
        {
            curr = prev1;
            if (i >= 2) curr += prev2;
            curr = curr % mod;
            
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // memo
        // vector<int> dp(n+1, -1);
        // int ans = countWaysHelper(n, dp);
        
        
        // tab
        // int ans = tab(n);
        
        // tab space optimised
        int ans = tabOptmised(n);
        
        return ans;
    }

};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends
