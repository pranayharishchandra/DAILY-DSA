#include <bits/stdc++.h>
using namespace std;

class Solution {
    // SIMILAR TO DETECT CYCLE -- JUST SLIGHT MODIFICATIONS
private:
    // DFS
    bool dfs(int src, vector<int> adj[], int vis[], int pathVis[])
    {
        // mark visited and work
        vis[src] = 2;
        pathVis[src] = 1;

        // calling the unvisited nbrs
        for (auto nbr : adj[src])
        {
            // if nbr unvisited -- call it
            if (vis[nbr] == -1)
            {
                if (dfs(nbr, adj, vis, pathVis) == true)
                    return true; 
            }

            // else if (pathVis[nbr] == 1) // condition 1
            else if (vis[nbr] == 2)  // conditon 2
                return true;
                

            /*
                DON'T WRITE THE FOLLOWING CONDITION -- you will get extra answers -- idk why
            // else if (vis[nbr] == 1) 
            // {
            //     vis[src] = 1;
            //     return false;
            // }
            */
        }

        vis[src] = 1;
        pathVis[src] = -1;

        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int vis[V];
        int pathVis[V];

        for (int i = 0; i < V; i++)
        {
            vis[i] = -1;
            pathVis[i] = -1;
        }
        

        // calling the unvisited
        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (vis[i] == -1)
            {
                if (dfs(src, adj, vis, pathVis) == true)
                {
                    // return true;
                    continue;
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 1)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
