#include <vector>

using namespace std;

/**============= memoization =================
Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time O(1). 
Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).

Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). 
Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/

int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}


/**============= Tabulation =================
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
*/

int f(int n){
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  return dp[n];
}



/**============= Tabulation (space opt )=================
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(1)
Reason: we are using only 2 extra variables to solve this problem
*/
int f(int n){

  vector<int> dp(n+1,-1);
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }

  return prev;
}

