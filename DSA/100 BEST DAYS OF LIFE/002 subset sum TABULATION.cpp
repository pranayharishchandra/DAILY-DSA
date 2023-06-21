//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    bool isSubsetSumMemo(vector<int> arr, int sum, int n, vector<vector<int>> &dp)
    {
        for (int i = 0; i <= n ; i++) // i -> items
        {
            for (int j = 0; j <= sum ; j++) // j -> sum
            {
                if (j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if (i == 0) {
                    dp[i][j] = 0;
                    continue;
                }

                int currIdx = i - 1;
                int num     = arr[currIdx];
                // can include choice
                if (num <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i-1][j - num];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        return isSubsetSumMemo(arr, sum, n, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
