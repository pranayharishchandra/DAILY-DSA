#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // BFS
    // bool checkCycle(int src, vector<int> &vis, vector<int> adj[])
    bool checkCycle(int src, int vis[], vector<int> adj[])
    {
        // queue and visited
        queue<pair<int, int>> q;
        vis[src] = 1;

        q.push({src, -1});

        while (q.size() > 0)
        {
            // remove and work
            int nsrc = q.front().first;
            int parent = q.front().second;
            q.pop();

            // adding the unvisited nbrs
            for (auto nbr : adj[nsrc])
            {
                // if not visited then add the nbr
                if (vis[nbr] == 0)
                {
                    vis[nbr] = 1;
                    q.push({nbr, nsrc});
                }

                // if it's visited and not the parent then it must have been touched by some other node
                // so cycle exists
                // smallest cycle is of lenght = 3
                else if (vis[nbr] == 1 && nbr != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        // creating visited vector
        // vector<int> vis(V);
        int vis[V] = {0};

        // connnected components
        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (vis[i] == 0) // don't forget to add this line.. otherwise long TCs couldn't be handled
            {
                if (checkCycle(src, vis, adj) == true)
                {
                    return true;
                }
                else
                {
                    // check for other components
                    continue;
                }
            }
        }

        return false;
    }
};

int main()
{

    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
