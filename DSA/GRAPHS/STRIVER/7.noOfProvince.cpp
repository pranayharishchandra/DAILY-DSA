#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // dfs traversal function
    void dfs(int node, vector<int> adjLs[], int visited[])
    {
        // work on node
        visited[node] = 1;
        for (auto it : adjLs[node])
        {
            if (visited[it] == 0)
            {
                dfs(it, adjLs, visited);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // adjmatrix --> adjlist
        vector<int> adjLs[V];

        // NOTE : adj.size () == adj[0].size() == V

        for (int row = 0; row < V; row++)
        {
            for (int col = 0; col < V; col++)
            {
                // self nodes are not considered
                if (adj[row][col] == 1 && row != col)
                {
                    adjLs[row].push_back(col);
                    adjLs[col].push_back(row);
                }
            }
        }

        int visited[V] = {0};
        int countConnectedComponents = 0;

        for (int i = 0; i < V; i++)
        {
            int node = i;
            if (visited[node] == 0)
            {
                dfs(node, adjLs, visited);
                countConnectedComponents++;
            }
        }
        return countConnectedComponents;
    }
};

int main()
{

    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    Solution ob;
    cout << ob.numProvinces(adj, 3) << endl;

    return 0;
}
