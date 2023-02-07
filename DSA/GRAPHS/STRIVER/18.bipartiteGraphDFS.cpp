class Solutoion1
{
private:
    // DFS SOL1           WITH using currCle paremeter-------VVVVVVV
    bool check(int src, int V, vector<int> adj[], int color[], int currClr)
    {
        // mark visited and work
        color[src] = currClr;

        // calling the unvisited nbr
        // if visited then check if have same color then not bipertite graph
        // if different color the ignore it
        for (auto nbr : adj[src])
        {
            if (color[nbr] == -1)
            {
                // call the unvisited nbr
                if (check(nbr, V, adj, color, !currClr) == false) return false;
                
            }
            // if already visited the check -- the color should not be same
            else if (color[src] == color[nbr]) return false;

            
        }

        return true; // if color[src] == color[nbr] was never found -- bipertite graph
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];

        for (int i = 0; i < V; i++) color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (color[src] == -1)
            {
                if (check(src, V, adj, color, 0) == false) return false;
            }
        }

        return true; // all the components are bipertite
    }
}









class Solution2
{
private:
    // DFS SOL2              whitout using currCle paremeter-------VVVVVVV
    bool check(int src, int V, vector<int> adj[], int color[], int currClr)
    {
        // mark visited and work
        color[src] = currClr;

        // calling the unvisited nbr
        // if visited then check if have same color then not bipertite graph
        // if different color the ignore it
        for (auto nbr : adj[src])
        {
            if (color[src] == -1)
            {
                // call the unvisited nbr
                color[nbr] = !color[src];
                if (check(nbr, V, adj, color, !currClr) == false)
                {
                    return false;
                }
            }
            else // if already visited the check -- the color should not be same
            {
                if (color[src] == color[nbr])
                {
                    return false;
                }
            }
        }

        return true; // if color[src] == color[nbr] was never found -- bipertite graph
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V] = {-1};

        for (int i = 0; i < V; i++) color[i] = -1;
        

        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (color[src] == -1)
            {
                color[src] = 0;
                if (check(src, V, adj, color, 0) == false)
                {
                    return false;
                }
            }
        }

        return true; // all the components are bipertite
    }
};
