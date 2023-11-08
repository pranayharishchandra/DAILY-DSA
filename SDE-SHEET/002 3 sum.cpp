https://leetcode.com/problems/3sum/submissions/



==========================================================================================================================================================================
      find tc : log(no. of unique triplets)
  3 pointer   : Time Complexity: O(N3 * log(no. of unique triplets))
  hashing     : Time Complexity: O(N2 * log(no. of unique triplets))
  2 pointer   : Time Complexity: O(N2)
==========================================================================================================================================================================
brute n cube sol

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        set<vector<int>> s;


        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    int curr = arr[i] + arr[j] + arr[k];
                    vector<int> subans = {arr[i], arr[j], arr[k]};
                    sort(subans.begin(), subans.end());

                    if (curr == 0 && s.find(subans) == s.end()) {
                        ans.push_back(subans);
                        s.insert(subans);
                    }
                }
            }
        }
        return ans;
    }
};
=========================================================================================================================================================
better o n2 sol
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        set<vector<int>> s;



        for (int i = 0; i < n; i++)
        {
            map<int,int> m;

            for (int j = 0; j < i; j++)
            {
                    int arr_k = -(arr[i] + arr[j]);

                    int feq_k = m[arr_k];
                    vector<int> subans = {arr_k, arr[j], arr[i]};
                    sort(subans.begin(), subans.end());


                    if (feq_k > 0 &&  s.find(subans) == s.end()) {
                        ans.push_back({arr_k, arr[j], arr[i]});
                        s.insert(subans);
                    }
                    int feq = m[arr_k];
                    m[arr[j]]++;
            }
        }
        return ans;
    }
};
==========================================================================================================================================================================
best 2 pointers

  #include <vector>
using namespace std;

/**
 * APPROCH
 * 2 pointers
 * compare the ith with the prev and if same continue
 * i to n-1 == part of array, use 2 pointer and find uniqure tiplets
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum = 0; // if the required sum is 0
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n-2; i++)
        {
            if (i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1, k = n-1;
            // not doing j < k, otherwise i can have 2 same elements if j = k
            // and the numbers must be unique
            while (j < k) {
                int a = nums[i];
                int b = nums[j];
                int c = nums[k];
                
                int total = a + b + c;

                if (total > sum) {
                    // dec the total
                    k--;
                }
                else if (total < sum ) {
                    // inc the total 
                    j++;
                }
                else {
                    vector<int> subans = {a, b, c};
                    ans.push_back(subans);
                    
                    j++; k--;
        
                    // if still equal to prev ele, for avoiding duplicates
                    while (j<k && nums[j] == nums[j-1]) j++;
                    while (k>j && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
