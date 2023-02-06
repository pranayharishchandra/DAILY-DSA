class Solution {

// do surrounded regions -- and this question is automatically solved

public:
    // BFS
    int numberOfEnclaves(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};

        int totalOne = 0;
        int outerOne = 0;

        // visited and add to queue
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    totalOne++;
                    // 1s in the last
                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    {
                        outerOne++;
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        while (q.size() > 0)
        {
            auto nsrc = q.front();
            q.pop();

            int x = nsrc.first;
            int y = nsrc.second;

            // adding the unvisited nbrs
            for (int i = 0; i < 4; i++)
            {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && r < n && c >= 0 && c < m)
                {
                    // unvisited land cells
                    if (vis[r][c] == 0 && mat[r][c] == 1)
                    {
                        outerOne++;
                        q.push({r, c});
                        vis[r][c] = 1;
                    }
                }
            }
        }

        int insideOne = totalOne - outerOne;
        return insideOne;
    }
};
