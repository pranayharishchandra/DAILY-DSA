public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> ans = grid;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == 1)
                {
                    ans[row][col] = 0;
                    q.push({{row, col}, 1});
                }
            }
        }

        while (q.size() > 0)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = x + drow[i];
                int c = y + dcol[i];

                // check for validity
                if (r >= 0 && r < n && c >= 0 && c < m)
                {
                    // unvisited zero
                    // if (zero originally && unvisited )
                    if (grid[r][c] == 0 && ans[r][c] == 0)
                    {
                        ans[r][c] = d;            // marked visited
                        q.push({{r, c}, d + 1});
                    }
                }
            }
        }
        return ans;
    }
