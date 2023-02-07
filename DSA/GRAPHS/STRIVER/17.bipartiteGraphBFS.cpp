#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // BFS
    bool check(int src, vector<int> adj[], int color[])
    {
        // visited and make queue and push src in it
        color[src] = 0;
        queue<int> q;
        q.push(src);

        while (q.size() > 0)
        {
            // remove and work
            int nsrc = q.front();
            q.pop();

            // calling the unvisited nbrs
            for (auto nbr : adj[nsrc])
            {
                // if unvisited -- add the nbr to queue AND MARK IT VISITED
                if (color[nbr] == -1)
                {
                    q.push(nbr);
                    color[nbr] = !color[nsrc]; // opposite to the color of nsrc -- mark visited
                }
                else if (color[nbr] == color[nsrc])
                    return false;
            }
        }

        return true; // if you never encounterd an odd length cycle OR src and nbr color same
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];

        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (color[src] == -1)
            {
                if (check(src, adj, color) == false)
                    return false;
            }
        }

        return true;
    }
};
