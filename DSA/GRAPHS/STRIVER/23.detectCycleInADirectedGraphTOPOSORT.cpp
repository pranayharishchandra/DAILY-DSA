#include <bits/stdc++.h>
using namespace std;

// DFS
class Solution
{
    // TO SEE COMMENTS / EXPLAINATION -->

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        // TOPO SORT USNIG VISITED -- "Kahn’s Algorithm"

        // CREATING QUEUE
        queue<int> q;

        // CREATING VISITED -- VISITED WILL BE CONTAIN THE NO OF EDGES
        int indegree[V];
        for (int i = 0; i < V; i++) // IF NO OUTGOING EDGES -- PUT ZERO
            indegree[i] = 0;

        // checking nbrs of each src
        for (int i = 0; i < V; i++)
        {
            int src = i;
            for (auto nbr : adj[src])
            {
                indegree[nbr]++; // no of incoming edges to nbr node
            }
        }

        // src nodes with indegree == 0 --> add them in queue to remove their edges
        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (indegree[src] == 0)
            {
                q.push(src);
            }
        }

        // indegree[src] == 0 --> means visited --> src that is done

        // CREATING A vector answer -- topo
        // vector<int> topo;
        int count = 0;

        while (q.size() > 0)
        {
            // removing front -- and work (adding src in topo sort)
            int src = q.front();
            q.pop();

            // topo.push_back(src);
            count++;

            for (auto nbr : adj[src])
            {
                indegree[nbr]--; // reduce the incoming edge the to nbr
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        // return topo;
        if (count == V)
            return false;
        else
            return true;
    }
};
