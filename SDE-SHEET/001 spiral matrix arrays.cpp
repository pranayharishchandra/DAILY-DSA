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
