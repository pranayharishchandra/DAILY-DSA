//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    bool isSubsetSumMemo(vector<int> arr, int sum, int n, vector<vector<int>> &memo)
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
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> memo(n + 1, vector<int> (sum + 1, -1));
        return isSubsetSumMemo(arr, sum, n, memo);
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
