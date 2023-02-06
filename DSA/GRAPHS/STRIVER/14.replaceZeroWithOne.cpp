class Solution 
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int drow[], int dcol[])
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
                if (vis[r][c] == 0 && mat[r][c] == 'O')
                {
                    dfs(r, c, vis, mat, drow, dcol);
                }
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
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
            if (vis[i][0] == 0 && mat[i][0] == 'O')
            {
                dfs(i, 0,  vis, mat, drow, dcol);
            }
            // unvisited O -- last col
            if (vis[i][m - 1] == 0 && mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1,  vis, mat, drow, dcol);
            }
        }

        for (int j = 0; j < m; j++)
        {
            // unvisited O -- 1st row
            if (vis[0][j] == 0 && mat[0][j] == 'O')
            {
                dfs(0, j,  vis, mat, drow, dcol);
            }

            // unvisited O -- last row
            if (vis[n - 1][j] == 0 && mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j,  vis, mat, drow, dcol);
            }
        }

        // // PRINTING THE VISTED MAT
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << endl;

        // if unvisited O then convert to X
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};
