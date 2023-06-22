// https://practice.geeksforgeeks.org/problems/minimal-cost/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    // MEMO
    // int is -->> min energy of the subproblem/ leftover problem memo(n-1) or memo(n-2)
    int memo(vector<int>& height, int n, vector<int> &dp, int k)
    {
        if (n == 0)
            dp[n] = 0;
        
        
        if (dp[n] != -1) return dp[n];

        int curr = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            if (n >= i) {
                int subAns  = abs(height[n] - height[n - i]) + memo(height, n - i, dp, k);
                curr = min(curr, subAns);
            }
        }
        
        dp[n] = curr;
        return dp[n];
    }
    // TAB
    int tab(vector<int>& height, int n, vector<int>& dp, int k)
    {
        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
                int curr = INT_MAX;

                for (int j = 1; j <= k; j++)
                {
                    if (i >= j) {
                        int subAns  = abs(height[i] - height[i - j]) + dp[i-j];
                        curr = min(curr, subAns);
                    }
                }
                
                dp[i] = curr;            
        }
        return dp[n-1];
    }

  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, -1);

        // MEMO
        // int ans = memo(height, n - 1, dp, k);

        // tab
        int ans = tab(height,n, dp, k);

        // tab -- sp opt
        // int ans = tabSpOpt(height, n);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
