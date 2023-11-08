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
/*

  APPROCH OF THIS AND IT'S FOLLOWUP
 
  we are able to optimse it to a single pass solution because
  we need to find a SUBARRYA    i.e. continous
  and not a         SUBSEQUENCE i.e. may not be continous

  so we are breaking the squence and doing a fresh new start of a subarray
  when ( sum == 0 ) 

  we add the ith element in our curr, and if it becomes lesser than zero
  we break the sequence in that iteration only


  ONE MORE FOLLOWUP QUESTION CAN BE
  => FIND THE SUBARRAY WITH MAX SUM AND MIN LENGHT
      if (curr < 0)
  => FIND THE SUBARRAY WITH MAX SUM AND MIN LENGHT
      if (curr <= 0) 
      if sum zero also keep continuing the sequence
    
*/

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
/*
  => FIND THE SUBARRAY WITH MAX SUM AND MIN LENGHT
      if (curr < 0)
*/
  
  // FOLLOW UP QUESTION
  // FIND FIRST AND SHORTEST SUBARRAY WITH MAX SUM (KADEN'S ALGO)

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

            // don't update answer until curr greater 
            // FOLLOW-UP of this question is : FIND THE LAST AND SHORTEST SUBARRAY WITH MAX SUM
            // doing this you will get the 1st (leftmost) 
            // to get the rightmost sequence do : curr >= ans
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
/*
  => FIND THE SUBARRAY WITH MAX SUM AND MAX LENGHT

  since it's the question of max length, 
  so there is no problem thinking about taking the left or the right subarray
  since we are actually considering both the subarrays
  i.e. length of left subarr with sum + length of right subarr with max sum
      if (curr <= 0) 
      if sum zero also keep continuing the sequence
*/
class Solution {
public:
    int maxSubArray(vector<int>& arr) {

        int n = arr.size();
        int ans = INT_MIN;
        int curr = 0;

        int start = 0;
        int end = 0;
        int temp_start = 0;

        bool cntnu = false;

        for (int i = 0; i < n; i++)
        {
            if (curr == 0 && !cntnu) {
                temp_start = i;
            }
            curr += arr[i];

            // keep continuing even if it's equal to the ans
            // input : [1,0,-1,0,1]  
            // output: {0, 4}
            if (curr >= ans) {
                start = temp_start;
                end = i;
                ans = curr;
            }

            if (curr < 0){ 
                curr = 0;
                cntnu = false;
            } else {
              cntnu = true;
            }
        }
        cout << start << endl << end << endl;
        return ans;
        // return {start, end};
    }
};

  
