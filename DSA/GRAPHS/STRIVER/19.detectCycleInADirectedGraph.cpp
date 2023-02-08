#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // DFS
    // NO PARAMETER REQUIRED FOR PARENT BECAUSE -- IT'S DIRECTED GRAPH
    // i.e. parent has nbr child BUT child don't have parent as nbr
    // parent --> child
    bool check(int src, vector<int> adj[], int vis[], int pathVis[])
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
                if (check(nbr, adj, vis, pathVis) == true)
                    return true; // even if you get a single cycle -- means whole graph is cyclic
                                 /* we stops immediately n returns back to parent call and we don't check for the other nbr -- and they remains unvisited
                                    since they are unvisited -- we can call them from the isCyclic() function to check they have any cycle or not */
            }
            // if the nbr was already visited -- then just check when it was visited -- during this path or while exploring some other path

            // VVVVVVVVVVVVVVVVVVVVVVVVVVV USE EITHER OF THE 2 CONDITIONS -- BOTH ARE CORRECT
            // else if (pathVis[nbr] == 1) // condition 1
            else if (vis[nbr] == 2)        // condition 2
                return true;
        }

        // while returning from the path -- mark the path as unvisited -- so while exporing the same node from
        // some other path we don't find it visited and say it's a cycle
        // FOR THAT EITHER YOU CAN USE ONE VIS ARRAY AND PATH VISITED ARRAY
        // OR YOU CAN DO USE 2 WHEN VISITING THE PATH -- AND FOR UNVISITED YOU CAN DO VIS[SRC] = 1 -- STILL IT'S VISITED BUT NOT PATH VISITED

        // === POST ORDER === ( when curr src is not part of any cycle ) == ( executed only when return true will not get executed )
        vis[src] = 1;
        pathVis[src] = -1;

        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        // create visited array
        int vis[V];
        int pathVis[V];

        for (int i = 0; i < V; i++)
        {
            vis[i] = -1;
            pathVis[i] = -1;
        }

        for (int i = 0; i < V; i++)
        {
            int src = i;
            // calling the node never visited
            if (vis[src] == -1)
            {
                if (check(src, adj, vis, pathVis) == true)
                    return true;
            }
        }

        return false;
    }
};
