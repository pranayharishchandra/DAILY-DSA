https://leetcode.com/problems/sort-colors/submissions/

/*
  SIMPLE APPROCH
  just counted and replaced in place
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        int n = nums.size();

        for (auto it : nums) {
            if (it == 0) zero++;
            if (it == 1) one++;
            if (it == 2) two++;
        }

        for (int i = 0; i < n; i++)
        {
            if (zero) {
                zero--;
                nums[i] = 0;
            }
            else if (one) {
                one--;
                nums[i] = 1;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};

/*
APPROCH 2
DNF
3 pointers


MAIN HINTS TO SOLVE THIS QUESTION
=> 0 -> j-1 : sorted
=> sort the element j == k to it's right position
=> j  -> k  : unknowns

j  -> k  : unknowns


==================
0 -> i-1 : 0
i -> j-1 : 1 

j -> k : UNKNOWNS

k+1 -> n-1 : 2 
===================
*/

[2,0,1]

  class Solution {
public:
    void sortColors(vector<int>& arr) {
        int zero = 0;
        int one = 0;
        int two = 0;

        int n = arr.size();

        int i = 0, j = 0, k = n-1;

        // [2,0,1] this test case will not pass if (j < k)
        while (j <= k) {
            if (arr[j] == 0) {
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else if (arr[j] == 2) {
                swap(arr[j], arr[k]);
                k--;
            }
            else if (arr[j] == 1) {
                j++;
            }
        }
    }
};









  
