#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS
    void dfs(int row, int col, vector<vector<int>> &grid, vector<pair<int, int>> &comp, vector<vector<int>> &vis, int drow[], int dcol[], int refRow, int refCol)
    {
        int n = grid.size();
        int m = grid[0].size();

        // mark visited and work(adding into comp)
        vis[row][col] = 1;
        comp.push_back({row - refRow, col - refCol});

        // calling the unvisited nbrs
        for (int i = 0; i < 4; i++)
        {
            int r = row + drow[i];
            int c = col + dcol[i];

            if (r >= 0 && c >= 0 && r < n && c < m)
            {
                // it unvisited then call for the nbr
                // calling unvisited 1
                if (vis[r][c] == -1 && grid[r][c] == 1)
                {
                    dfs(r, c, grid, comp, vis, drow, dcol, refRow, refCol);
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        set<vector<pair<int, int>>> comps; // all distnict components
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, -1));
        
        int totalComp = 0; 

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == -1 && grid[i][j] == 1)
                {
                    vector<pair<int, int>> comp;
                    dfs(i, j, grid, comp, vis, drow, dcol, i, j);
                    comps.insert(comp);
                    totalComp++;
                }
            }
        }

        // cout << totalComp << endl;
        
        return comps.size();
    }
};
