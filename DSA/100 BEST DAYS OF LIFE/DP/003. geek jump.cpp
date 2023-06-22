// https://practice.geeksforgeeks.org/problems/geek-jump/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

    // MEMO
    // int is -->> min energy of the subproblem/ leftover problem memo(n-1) or memo(n-2)
    int memo(vector<int>& height, int n, vector<int> &dp)
    {
        if (n == 0)
            dp[n] = 0;
        
        
        if (dp[n] != -1) return dp[n];

        int left  = abs(height[n] - height[n - 1]) + memo(height, n - 1, dp);
        
        int right = INT_MAX;
        if (n >= 2)
            right = abs(height[n] - height[n - 2]) + memo(height, n - 2, dp);

        dp[n] = min (left, right);
        return dp[n];
    }

    int tab(vector<int>& height, int n, vector<int> &dp)
    {
        // n -> i
        for (int i = 0; i < n; i++)
        {
            if (i == 0){
                dp[i] = 0;
                continue;
            }

            int left  = abs(height[i] - height[i - 1]) + dp[i - 1];
            
            int right = INT_MAX;
            if (i >= 2)
                right = abs(height[i] - height[i - 2]) + dp[i - 2];

            dp[i] = min (left, right);
        }
        return dp[n-1];
        
    }

public:
    int minimumEnergy(vector<int>& height, int n) {
        
        vector<int> dp(n, -1);

        // MEMO
        // int ans = memo(height, n - 1, dp);

        // tab
        int ans = tab(height,n, dp);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
