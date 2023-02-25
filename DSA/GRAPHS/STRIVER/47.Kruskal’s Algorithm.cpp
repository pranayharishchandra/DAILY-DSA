#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank, size;

    // constuctor
    DisjointSet (int n){
        // doing n + 1 so our code works for 0 as well as 1 based indexing
        parent.resize(n+1); 
        rank.resize(n+1, 0);
        size.resize(n+1, 1);

        for (int i = 0; i < n+1; i++)
        {
            parent[i] = i;
        }
    }

    // finding the ultimate parent and path compression as well ==> parent[root] = findUparent(parent[root])
    int findUparent (int root)
    {
        if (root == parent[root]) //  node which is itself it's parent is the one of the ultimate parent
            return root;

        else parent[root] = findUparent(parent[root]); // child calling it's parent 
                                                       // until they find their ultimate parent 
                                                       // and while returning we assign that ultimate parent to it's(UP's) every child node 
    }


    void unionBySize(int u, int v)
    {
        int up_u = findUparent(u);
        int up_v = findUparent(v);

        if (up_u == up_v) return; // since they are already part of same component 
                                  // so noting to do (union/combining the components)

        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v]  += size[up_u];
        }

        else if (size[up_u] > size[up_v] || size[up_u] == size[up_v])
        {
            parent[up_v] = up_u;
            size[up_u]  += size[up_v];
        }
    }

    void unionByRank(int u, int v)
    {
        int up_u = findUparent(u);
        int up_v = findUparent(v);

        if (up_u == up_v) return; // since they are already part of same component 
                                  // so noting to do (union/combining the components)

        if (rank[up_v] > rank[up_u])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_u] > rank[up_v])
        {
            parent[up_v] = up_v;
        }
        else{
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int,int>>> edges;
        
        // see the drivers code to check the adj list
        for (int i = 0; i < V; i++)
        {
            int src = i;
            for (auto ed : adj[src])
            {
                int nbr  = ed[0];
                int wt   = ed[1];

                edges.push_back({wt, {src, nbr}});
            }
        }

        // using kruskal's algorithm -- soriting the edges
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        int minSum = 0;
        int uselessEdge = 0;

        for (auto ed : edges)
        {
            int edwt = ed.first;
            int src  = ed.second.first;
            int nbr  = ed.second.second;

            // checking if src and the nbr are -- directly (by an edge) or indirectly (via some other node) connected
            // then the path already present is best path even if the distance from src to nbr may be longer but it must be via some other path... 
            // and we eventually have to cover all the nodes
            /*
             * (0,1,2)
             * (1,2,3)
             * (3,0,4)
             * draw it's MST you will understand -- dist from 0 to 3 is --> directly 4 and indirectly 2+3=5 
             * 5 may be a longer distance but it convers more no. of nodes... and covering more nodes is our top priority ..
             * so we prever 0 to 3 via 2 over direct edge b/w 0 and 3
             */ 

           /*
            * let's src = 0 and nbr = 3
            * if 0 and 3 iare directly or indirectly connected then 0 and 3 will be in same component
            * i.e. they both should have same ultimate parent... 
            * if that's the case then no need to include that edge in the MST
            * else {include that edge in you MST by connecting src; nbr and sum+=edwt;}
            */

            if (ds.findUparent(src) != ds.findUparent(nbr))
            {
                minSum += edwt;
                ds.unionBySize(src, nbr);
            }
            else {
                uselessEdge++;
            }
        }
        return minSum;
    }
};
