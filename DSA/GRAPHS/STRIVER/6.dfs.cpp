#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int visited[], vector<int> &ans)
    {
        // work on the node
        visited[node] = 1;
        ans.push_back(node);

        // call the unvisited nbr
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                dfs(it, adj, visited, ans);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            int node = i;
            if (visited[node] == 0)
            {
                // do all the work in the funciton -- dfs
                // that has to performed on a node
                dfs(node, adj, visited, ans);
            }
        }
        return ans;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
