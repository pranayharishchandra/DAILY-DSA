https://leetcode.com/problems/merge-intervals/

/*
very simple and basic approch
just extend the current interval or (it will remain as it is if d lesser than b)

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];

        // first pair of a,b
        // second pair of c,d 
        // { {a,b}, {c,d} }

        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            int a = curr[0];
            int b = curr[1];
            int c = intervals[i][0];
            int d = intervals[i][1];

            if (b >= c) {
                // continue or extend the same intervel
                int maxi = max(b,d);
                curr[1] = maxi;
            }
            else {
                // add prev intervel to ans and make new intervel
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
