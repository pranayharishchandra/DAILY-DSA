#include <vector>
using namespace std;

/**============= memoization =================
Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time O(1). 
Therefore the total number of new subproblems we solve is ‘n’.
Hence total time complexity is O(N).

Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). 
Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/

int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0) 
        return arr[0];

    // if (ind < 0)   // solution 1 - if 'ind' is negative or not valid, means not can't add anything
    //     return 0;


    if (ind == 1)   // solution 2 - creating a base case to ensure that we 'ind' don't become negative
        return max(arr[0], arr[1]);

    int pick    = arr[ind] + solveUtil(ind - 2, arr, dp);
    int nonPick = 0        + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

int f(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return solveUtil(n - 1, arr, dp);
}

/**============= tabulation =================
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/
class Solution {
public:

    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);

        if (n >= 1) dp[0] = arr[0];
        if (n >= 2) dp[1] = max(arr[1], arr[0]);
    

        for (int ind = 2; ind < n; ind++) {

            int pick    = arr[ind] +  dp[ind-2];
            int nonPick = 0        +  dp[ind-1];

            dp[ind] = max(pick, nonPick);
        }
        return dp[n-1];
    }
};
/**============= tabulation (space optimaization)=================
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/
class Solution {
public:

    int rob(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        // vector<int> dp(n, -1);
        int prev2, prev, curr;


        if (n >= 1) prev2 = arr[0];
        if (n >= 2) prev  = max(arr[1], arr[0]);

        for (int ind = 2; ind < n; ind++) {

            int pick    = arr[ind] +  prev2;
            int nonPick = 0        +  prev;

            curr = max(pick, nonPick);

            prev2 = prev;
            prev  = curr;
        }
        return prev;
    }
};