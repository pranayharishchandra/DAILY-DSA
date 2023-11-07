// https://leetcode.com/problems/maximum-subarray/submissions/
=====================================================================================================================================================================
  // input: [-1], output:   -1

=====================================================================================================================================================================
//  o(n3)
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int n = arr.size();
        int ans = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int curr = 0;
                
                for (int k = i; k <= j; k++) {
                    curr += arr[k];
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
=====================================================================================================================================================================

//  o(n2)
  
class Solution {
public:
    int maxSubArray(vector<int>& arr) {

        int n = arr.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            for (int j = i; j < n; j++) {

                curr += arr[j];
                ans = max(ans, curr);
                if (curr < 0) curr = 0;
            }
        }
        return ans;
    }
};
=====================================================================================================================================================================
//  optimal -- kaden's algorithemn -- o(n)

class Solution {
public:
    int maxSubArray(vector<int>& arr) {

        int n = arr.size();
        int ans = INT_MIN;
        int curr = 0;

        for (int i = 0; i < n; i++)
        {
            curr += arr[i];
            ans = max(ans, curr);

            if (curr < 0) curr = 0;  
        }
        return ans;
    }
};
=====================================================================================================================================================================
// FOLLOIW UP QUESTION

#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& arr) {

        int n = arr.size();
        int ans = INT_MIN;
        int curr = 0;

        int start = 0;
        int end = 0;
        int temp_start = 0;

        for (int i = 0; i < n; i++)
        {
            if (curr == 0) {
                temp_start = i;
            }
            curr += arr[i];

            if (curr > ans) {
                start = temp_start;
                end = i;
                ans = curr;
            }

            if (curr < 0){ 
                curr = 0;
            }
        }
        cout << start << endl << end << endl;
        return ans;
        // return {start, end};
    }
};
=====================================================================================================================================================================
