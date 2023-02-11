#include <bits/stdc++.h>
using namespace std;

// TOPO SORT -- BFS
class Solution
{
    // MODIFICATION OF Prerequisite Tasks code --> Course Schedule code 
    // question --> find if it is possible to finish all tasks.
    // you just need to check that the tasks are non cyclic 
    // only when the tasks are non cyclic then vector<int> topo; topo.size() == V --> means there is way present to complete the tas


public:
	 vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
	    // Code here

        // storing in adj list to solve it using topological sort
        vector<int> adj[N];

        // int n = prerequisites.size();
        int n = m;
        
        // prerequisites --> [nbr,src] or [nbr <--src]

        for (int i = 0; i < n; i++)
        {
            // int nbr = prerequisites[i].first;
            // int src = prerequisites[i].second;
            int nbr = prerequisites[i][0];
            int src = prerequisites[i][1];
            adj[src].push_back(nbr);
        }

        // NOW JUST WRITING TOPOLOGICAL SORT FROM HERE
        queue<int> q;
        int ind[N] = {0}; // ind --> indegree

        for (int i = 0; i < N; i++)
            ind[i] = 0;
        
        for (int i = 0; i < N; i++)
        {
            int src = i;
            for (auto nbr : adj[src])
            {
                ind[nbr]++;
            }
        }

        for (int i = 0; i < N; i++)
        {
            int node = i;
            if (ind[node] == 0)
                q.push(node);
        }

        vector<int> topo;

        while (q.size() > 0)
        {
            int src = q.front();
            q.pop();
            topo.push_back(src);

            for (auto nbr : adj[src])
            {
                ind[nbr]--;
                if (ind[nbr] == 0)
                    q.push(nbr);
            }

        }
        // one topo sort / order is ready now

        // according to the question

        // it's possible only complete taks -- topo order is possible only when DAG
        // if cycle exists then topo will be of < N

        // if (topo.size() == N) return true;
        // else return false;

        if (topo.size() == N) return topo;
        else return {}; //empty vector    
	}
};
