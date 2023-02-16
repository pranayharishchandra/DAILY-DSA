class Solution
{
public:
// all the rotting has to be done symultanously so bfs
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        // int vis[n][m];
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        auto vis = grid;

        int fresh = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    q.push({{i, j}, 0});
                else if (grid[i][j] == 1)
                    fresh++;
                

        int rottened = 0;
        int maxTime = 0;

        // delta row and col
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (q.size() > 0)
        {
            // remove and work
            auto src = q.front();
            q.pop();

            int x = src.first.first;
            int y = src.first.second;
            int t = src.second;

            maxTime = t;

            // adding nbr
            for (int i = 0; i < 4; i++)
            {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && c >= 0 && r < n && c < m)
                {
                    // unvisited fresh -- since not changing 1->2 of grid -- so using visited
                    // color should be same in the grid and it should be unvisited as well
                    if (grid[r][c] == 1 && vis[r][c] == 1)
                    {
                        vis[r][c] = 2; // mark visited
                        rottened++;
                        q.push({{r, c}, t + 1});
                    }
                }
            }
        }
        
        /* FOR PRINTING THE NEW MATRIX */
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++){
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        // cout << "fresh    : " << fresh << endl;
        // cout << "rottened : " << rottened << endl;
        

        if (fresh != rottened)
        {
            return -1;
        }
        else
        {
            return maxTime;
        }
    }

};
 
