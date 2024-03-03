#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // simple dfs
    void dfs(vector<pair<int, int>> adj[], int vis[], int src, stack<int> &st)
    {
        // mark visited and work (adding) (adding into the stack) --> do it in postorder
        vis[src] = 1;

        for (auto it : adj[src])
        {
            // it --> is a vector
            int nbr = it.first;
            int wt = it.second;

            // call the nbr if unvisited
            if (vis[nbr] == 0)
                dfs(adj, vis, nbr, st);
            
        }
        // cout << "<-" << src;
        st.push(src);
    }

public:
    // Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M
    // vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        // code here
        vector<pair<int, int>> adj[N];

        // creating adj list
        for (auto edge : edges)
        {
            int src = edge[0];
            int nbr = edge[1];
            int wt = edge[2];

            adj[src].push_back({nbr, wt});
        }

        // creating visited array
        int vis[N] = {0};
        stack<int> st;

        vector<int> dist(N, INT_MAX);
        
        for (int i = 0; i < N; i++)
        {
            // calling the unvisited
            int src = i;
            if (vis[src] == 0)
            {   
                dfs(adj, vis, src, st);
                // dist[src] = -1;
            }
        }
        

        /* THE SOURCE IS ALWAYS ZERO */
        // int ssrc = st.top();
        dist[0] = 0;
        

        /* DID THE FOLLOWING PREVIOUS ... IS ALSO WORKS... BUT WHAT'S WRITTEN IN LINE 92 IS BETTER AND I GUESS MORE RELIABLE AS WELL */
        // until top of stack is not 0 keep removing the elements
        // while ( st.top() != 0)
        // {
        //     int top = st.top();
        //     dist[top] = -1;
        //     st.pop();
        // }

        while (!st.empty())
        {
            int nsrc = st.top();
            st.pop();
            
           /* 
            * YOU ARE GIVE THE dist[src] = 0 <-- src IS USUALLY 0 
            * NOW THE SRC WILL GO TO IT'S NBRS AND GIVE THEM SOME DISTANCE ==> dist[nsrc] + wt which is ofcourse lesser than INT_MAX so dist[nbr] will get updated from INT_MAX
            * ALL THE NODES WHICH WILL BE CONNECTED TO THE SRC WILL GET SOME DIST VALUE 
            * or u can say all nbrs of src i.e. 0 generally... their dist[nbr] will be updated atleast once from INT_MAX
            * So only those nodes who don't have incoming edge from the src will never get updated 
            * and when their time will come from stack their dist from src will be INT_MAX
            * and thus such node which becomes src but have dist = INT_MAX can be identified and their distance can be updated to -1 as no such distance exists
            */
            if (dist[nsrc] == INT_MAX) 
            {
                dist[nsrc] = -1;
                continue;
            }
            

            for (auto edge : adj[nsrc])
            {
                // edge --> src---wt---nbr
                int nbr = edge.first;
                int wt = edge.second;
                
                dist[nbr] = min(dist[nbr], dist[nsrc] + wt);
                
                // cout << "src : " << nsrc << ", nbr : " << nbr << ", wt : " << wt << " : dist[" << nbr << "] = " << dist[nbr] << endl;
            }
        }

        return dist;
    }
};
