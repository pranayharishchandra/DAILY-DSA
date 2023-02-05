#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BFS -- SIMILAR TO ROTTEN ORGANGE -- min time , here return the matrix
    // STEP BY STEP -- level order -- level by distance
    // in rotten oranges -- level order -- level by time

public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<vector<int>> ans = grid;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == 1)
                {
                    vis[row][col] = 1;
                    ans[row][col] = 0;
                    q.push({{row, col}, 1});
                }
                else
                {
                    vis[row][col] = 0;
                    // ans[row][col] --? this is what you need to find out
                }
            }
        }

        while (q.size() > 0)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            // cout << " (" << x << "," << y << ")-> " << d << " " << endl;

            for (int i = 0; i < 4; i++)
            {
                int r = x + drow[i];
                int c = y + dcol[i];

                // check for validity
                if (r >= 0 && r < n && c >= 0 && c < m)
                {
                    // unvisited zero
                    if (vis[r][c] == 0 && grid[r][c] == 0)
                    {
                        ans[r][c] = d;
                        vis[r][c] = 1;
                        q.push({{r, c}, d + 1});
                    }
                }
            }
        }
        // cout << endl << endl;

        return ans;
    }
};
