#include <vector>
using namespace std;

/**=============  =================
SAME AS PREV QUESTION: JUST CHANGE THE "maxRob" function
*/

class Solution {
public:
    int maxRob(vector<int>& nums, int start , int n , vector<int>& dp ){
        if(n == start) return nums[start];
        if( n < start ) return 0; 
        if( dp[n] != -1 ) return dp[n];

        int pick = nums[n] + maxRob(nums,start, n-2, dp);  
        int notPick = 0 + maxRob(nums,start, n-1, dp); 
        return dp[n] = max(pick, notPick); 
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if( n == 1 ) return nums[0];

        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        
        // making 2 cases so we ensure that we don't include 
        // 0th and (n-1)th index
        // rest the question is same as previous

        int case1 = maxRob(nums,0, n-2, dp1); 
        int case2 = maxRob(nums,1, n-1, dp2);  

        return max(case1, case2); 
    }
};






