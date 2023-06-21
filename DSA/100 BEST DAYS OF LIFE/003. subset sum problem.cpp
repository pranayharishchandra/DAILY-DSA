//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool isSubsetSumMemo(int arr[], int sum, int n, vector<vector<int>> &memo)
    {
        if (sum == 0)
            return true;
        if (sum < 0)
            return false;
        if (sum == 0 || n == 0) {
            memo[n][sum] = 0;
        }
        if (memo[n][sum] != -1)
            return memo[n][sum];
        
        int currIdx = n - 1;
        int num     = arr[currIdx];
        // include 
        if (num <= sum)
            // memo[n][sum] = max(isSubsetSumMemo(arr, sum, n, memo),
            //                 isSubsetSumMemo(arr, sum - num, n - 1, memo) + num);
            memo[n][sum] = isSubsetSumMemo(arr, sum, n - 1, memo) ||
                            isSubsetSumMemo(arr, sum - num, n - 1, memo);
        else
            memo[n][sum] = isSubsetSumMemo(arr, sum, n -1, memo);
        
        return memo[n][sum];

    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int n = N;
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        
        if (sum % 2 == 1)
            return false;

        vector<vector<int>> memo(n + 1, vector<int> (sum + 1, -1));

        int ans = isSubsetSumMemo(arr, sum / 2, N, memo);
        return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
