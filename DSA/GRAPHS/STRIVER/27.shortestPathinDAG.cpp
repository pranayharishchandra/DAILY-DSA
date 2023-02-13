class Solution
{
private:

    void toposort(vector<pair<int, int>> adj[], int vis[], int src, stack<int> &st)
    {
        vis[src] = 1;

        for (auto it : adj[src])
        {
            int nbr = it.first;
            int wt = it.second;

            if (vis[nbr] == 0)
                toposort(adj, vis, nbr, st);
        }
        st.push(src);
    }

public:
    // M = EDGES, N = NODES, edges - [{src,nbr,wt}, ....]
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
                toposort(adj, vis, src, st);
            }
        }
        
        /* THE SOURCE IS ALWAYS ZERO */
        dist[0] = 0;
        
        while (!st.empty())
        {
            int nsrc = st.top();
            st.pop();
            
            if (dist[nsrc] == INT_MAX) 
            {
                dist[nsrc] = -1;
                continue;
            }
            
            for (auto edge : adj[nsrc])
            {
                // edge --> src ==> wt, nbr
                int nbr = edge.first;
                int wt = edge.second;
                
                dist[nbr] = min(dist[nbr], dist[nsrc] + wt);

            }
        }
        return dist;
    }
};
