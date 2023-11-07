// https://leetcode.com/problems/spiral-matrix/submissions/

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();
        int top_r = 0, right_c = m-1, bottom_r = n-1, left_c = 0;

        while (top_r <= bottom_r && left_c <= right_c) {

            // 1 traversing over top row
            for (int col = left_c; col <= right_c; col++)
                ans.push_back(matrix[top_r][col]); 

            top_r++;
            
            // 2 traversing right col
            for (int row = top_r; row <= bottom_r; row++)
                ans.push_back(matrix[row][right_c]);

            right_c--;
            
            
            // 3 traversing over bottom row
            if (bottom_r >= top_r){
                for (int col = right_c; col >= left_c; col--)
                    ans.push_back(matrix[bottom_r][col]);

                bottom_r--;            
            }
            
            // 4 traversing over right col
            if (right_c >= left_c){
                for (int row = bottom_r; row >= top_r; row--)
                    ans.push_back(matrix[row][left_c]);

                left_c++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();
        int top_r = 0, right_c = m-1, bottom_r = n-1, left_c = 0;

        while (top_r <= bottom_r && left_c <= right_c) {

            // 1 traversing over top row
            for (int col = left_c; col <= right_c; col++)
                ans.push_back(matrix[top_r][col]); 

            top_r++;
            
            // 2 traversing right col
            for (int row = top_r; row <= bottom_r; row++)
                ans.push_back(matrix[row][right_c]);

            right_c--;
            
            
            // 3 traversing over bottom row
            if (bottom_r >= top_r){
                for (int col = right_c; col >= left_c; col--)
                    ans.push_back(matrix[bottom_r][col]);
            }
            bottom_r--;            
            
            // 4 traversing over right col
            if (right_c >= left_c){
                for (int row = bottom_r; row >= top_r; row--)
                    ans.push_back(matrix[row][left_c]);
            }
            left_c++;
        }
        return ans;
    }
};





======================================================================================================================================================

// 3 sum -- optimal — WRONG SOLTION — CORNER CASES NOT HANDLED
// TAKING 4 VARIABLES - top, left, bottom, right IS BETTER FOR CODE QUALITY
// RATHER THAN JUST TAKING 1 VARIABLE - cnt
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        while (cnt <= ceil((float) n/2) || cnt <= ceil((float) m/2)) {

            // 1 traversing over top row
            for (int col = cnt; col < m-cnt; col++) {
                ans.push_back(matrix[cnt][col]);
            }
            
            // 2 traversing left col
            for (int row = cnt+1; row < n-cnt-1; row++) {
                ans.push_back(matrix[row][m-1-cnt]);
            }
            
            // 3 traversing over bottom row
            for (int col = (m-1)-cnt; col >= cnt; col--) {
                ans.push_back(matrix[n-1- cnt][col]);
            }
            
            // 4 traversing over right col
            for (int row = (n-1)-cnt-1; row >= cnt+1; row--) {
                ans.push_back(matrix[row][cnt]);
            }

            cnt++;
        }
        return ans;
    }
};
