#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // rows ans cols
        int rows = grid.size();
        int cols = grid[0].size();

        int rottens = 0;
        int freshCount = 0;

        int visited[rows][cols]; // since we don't want to change our original grid/matrix
                                 // 2 -- visited // 0 -- unvisited

        // queue to store current rotten -- ((x, y), t) --  coordinated and time
        queue<pair<pair<int, int>, int>> q;

        // traversing the grid -- counting and visiting
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 2)
                {
                    visited[row][col] = 2;
                    rottens++;
                    q.push({{row, col}, 0});
                }
                else
                {
                    visited[row][col] = 0;
                }
                if (grid[row][col] == 1)
                {
                    freshCount++;
                }
            }
        }

        // cout << rottens  << " " << << endl;

        int maxTime = 0;

        // delta row and delta column
        // top, right, bottom, left -- avoid writing condition for 4 times and write only once
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int freshToRottened = 0;

        // bfs symultanously over all the rotten tomatoes
        while (q.size() > 0)
        {
            pair<pair<int, int>, int> rem = q.front();
            q.pop();
            int x = rem.first.first;
            int y = rem.first.second;
            int t = rem.second;

            // cout << x << "," << y << ", " << t << endl;

            // updating the max time 
            maxTime = max(maxTime, t);

            for (int i = 0; i < 4; i++)
            {
                // row, col - -new rows and cols -- write nrow, ncol
                int row = x + drow[i];
                int col = y + dcol[i];

                // if row and col are valid indix of the grid then only traverse them
                // also they should not be visited
                // and they should be fresh aswell

                if ((row >= 0 && col >= 0 && row < rows && col < cols ) && (visited[row][col] == 0) && (grid[row][col] == 1))
                {
                    visited[row][col] = 2; // changing the visited because we don't want to make any change in original grid
                    q.push({{row,col},t + 1});
                    freshToRottened++;
                }
            }
        }

        if (freshToRottened != freshCount) {
            return -1;
        }
        else {
            return maxTime;
        }
    }
};

int main()
{

    vector<vector<int>> grid{{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";

    return 0;
}
