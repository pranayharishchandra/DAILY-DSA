// IN THE QUESITON IT'S GIVEN THAT THE GRAPH IN TC's WILL BE DAG
class Solution
{
    // THERE CAN BE MULTIPLE ANSWERS FOR A TOPOLOGICAL SORT
    // ONLY ON DAG GIVES CORRECT ANSWER
    // CYCLIC GRAPH --> LESS THAN V (no. of node) AS ANSWER

private:
    // DFS
    void dfs(int src, vector<int> adj[], int vis[], stack<int> &st)
    {
        // marking true
        vis[src] = 1;

        // adding the unvisited nbrs
        for (auto nbr : adj[src])
        {
            // adding the unvisited nbr
            if (vis[nbr] == -1)
            {
                dfs(nbr, adj, vis, st);
            }
            // if nbr already visited -- do nothing -- just check the other nbr -- if no nbr present then there will be back-tracking
        }

        // POST-ORDER --- adding into the stack
        st.push(src);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here

        // CRAETING VISITED
        int vis[V];
        for (int i = 0; i < V; i++)
            vis[i] = -1;

        // CREATING A STACK
        stack<int> st;

        // printing in the increasing/dec ?  order
        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (vis[src] == -1)
            {
                dfs(src, adj, vis, st);
            }
        }

        vector<int> topo;

        while (!st.empty())
        {
            int ele = st.top();
            topo.push_back(ele);
            st.pop();
        }

        return topo;
    }
};
