class Solution {

// do surrounded regions -- and this question is automatically solver

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &mat, int drow[], int dcol[])
    {

        int n = mat.size();
        int m = mat[0].size();

        // visited and work
        vis[row][col] = 1;

        // adding unvisited nbrs of [row][col]
        for (int i = 0; i < 4; i++)
        {
            int r = row + drow[i];
            int c = col + dcol[i];

            if (r >= 0 && c >= 0 && r < n && c < m)
            {
                // unvisited O
                if (vis[r][c] == 0 && mat[r][c] == 1)
                {
                    dfs(r, c, vis, mat, drow, dcol);
                }
            }
        }
    }

public:
    // vector<vector<char>> fill(int n, int m, vector<vector<int>> mat)
    int numberOfEnclaves(vector<vector<int>> &mat) 
    {

        int n = mat.size();
        int m = mat[0].size();

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // n -- rows
        // m -- cols
        // [row][col] -- [n][m] --> visualizing this will be helpful while writing following conditions
        // so you will not get confused where to write [n][m] or like [m][n]

        for (int i = 0; i < n; i++)
        {
            // unvisited O -- 1st col
            if (vis[i][0] == 0 && mat[i][0] == 1)
            {
                dfs(i, 0, vis, mat, drow, dcol);
            }
            // unvisited O -- last col
            if (vis[i][m - 1] == 0 && mat[i][m - 1] == 1)
            {
                dfs(i, m - 1, vis, mat, drow, dcol);
            }
        }

        for (int j = 0; j < m; j++)
        {
            // unvisited O -- 1st row
            if (vis[0][j] == 0 && mat[0][j] == 1)
            {
                dfs(0, j, vis, mat, drow, dcol);
            }

            // unvisited O -- last row
            if (vis[n - 1][j] == 0 && mat[n - 1][j] == 1)
            {
                dfs(n - 1, j, vis, mat, drow, dcol);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // count the unvisited 1
                if (vis[i][j] == 0 && mat[i][j] == 1)
                {
                    ans++;
                }
            }
            
        }
        

        return ans;
    }

};
