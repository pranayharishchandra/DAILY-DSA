#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // work on the first node
        queue<pair<int, int>> q;
        vis[row][col] = 1;

        q.push(make_pair(row, col));

        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (q.size() > 0)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // adding nbr -- connted land in 8 dirct.
            for (int i = 0; i < 8; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // if valid index
                // then check if it's land
                // then check if it's not visited
                // if all are true then add the land

                // don't mistake in wrting nrow and row -- you can do mistake here
                if (nrow >= 0 && ncol >= 0 & nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1')
                {
                    // vis[row][col] = 1;
                    vis[nrow][ncol] = 1;
                    q.push(make_pair(nrow, ncol));
                }
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // create visited array and initialise to 0
        // int visited[n][m] = {0};
        // vector < vector < int >> visited;

        //                          v              v    I mistakenly wrote n n in both so my output was comming wrong -- so always check you have written correct n and m if you get error
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int countConnectedComponents = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (visited[row][col] == 0 && grid[row][col] == '1')
                {
                    bfs(row, col, visited, grid);
                    countConnectedComponents++;
                }
            }
        }

        return countConnectedComponents;
    }
};

int main()
{
    // n: row, m: column
    vector<vector<char>> grid{
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}};

    Solution obj;
    cout << obj.numIslands(grid) << endl;

    return 0;
}
