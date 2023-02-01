#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs(V);

        int visited[V] = {0};
        queue<int> q;

        // push the starting node
        q.push(0);
        visited[0] = 1;

        while (q.size() > 0)
        {
            // remove
            int node = q.front();
            q.pop();

            // work
            bfs.push_back(node);

            // add nbr
            for (auto it : adj[node])
            {
                if (visited[it] == 0)
                {
                    // mark visited and add nbr
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
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
    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
