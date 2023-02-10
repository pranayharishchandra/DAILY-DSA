#include <bits/stdc++.h>
using namespace std;

// DFS
class Solution
{
    // THERE CAN BE MULTIPLE ANSWERS FOR A TOPOLOGICAL SORT
    // ONLY ON DAG GIVES CORRECT ANSWER
    // CYCLIC GRAPH --> LESS THAN V (no. of node) AS ANSWER

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        // TOPO SORT USNIG VISITED -- "Kahn’s Algorithm"

        // CREATING QUEUE
        queue<int> q;

        // CREATING VISITED -- VISITED WILL BE CONTAIN THE NO OF EDGES
        int indegree[V];
        for (int i = 0; i < V; i++) // IF NO OUTGOING EDGES -- PUT ZERO
            indegree[i] = 0;

        /*
         * U --> V
         * we want to calculate outgoing edges from src --> count no. of nbrs of src
         * indegree[nbr]++;
         * if we wanted to find no of incoming edges to a node --> count how many srcs are pointing to a nbr
         * indegree[src]++ <-- just replace indegree[nbr]++; with this ans rest all things wil remain the same
         */

        // checking nbrs of each src
        for (int i = 0; i < V; i++)
        {
            int src = i;
            for (auto nbr : adj[src])
            {
                indegree[nbr]++; // no of incoming edges to nbr node
            }

            /* NOTE : DON'T CALC indegree here only -- you could have calc outgoing here 
            but can't calc incoming edge like this.. use common sense -- you can't calc it till you check nbrs of all src */
            // if (indegree[src] == 0)
            // {
            //     q.push(src);
            // }
            
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
        vector<int> topo;

        while (q.size() > 0)
        {
            // removing front -- and work (adding src in topo sort)
            int src = q.front();
            q.pop();

            topo.push_back(src);

            // NOW REMOVE THE EDGES(outgoing to src) THIS src WAS POINTING TO -- BCAUZ THIS "SRC" IS GONNA REMOVED
            // and adding the edge with incoming edge becoming zero
            for (auto nbr : adj[src])
            {
                indegree[nbr]--; // reduce the incoming edge the to nbr
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                    /* 
                    NOTE : DON'T WRITE THE LINE BELOW .. since you are already adding it above in work 
                    Here you used to mark visitd -- but in this quesition -- visited is not actually required
                    // topo.push_back(nbr); // incoming edges became zero --> now push into stack to delete nbr's edges
                    */
                }
            }
        }

        return topo;
    }
};
