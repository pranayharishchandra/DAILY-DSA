#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // DFS
    // bool checkCycle(int src, vector<int> &vis, vector<int> adj[])
    bool checkCycle(int src, int vis[], vector<int> adj[], int parent)
    {
        // visited mark and work
        vis[src] = 1;

        // calling unvisited nbr
        // if they are visited and are not parent then --> CYCLE DETECTED

        for (auto nbr : adj[src])
        {
            // if not visited then call the nbr
            if (vis[nbr] == 0)
            {
                // return checkCycle(nbr, vis, adj, src);
              
              /* https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/
                GO TO THE ABOVE LINK... YOUR CODE WILL NOT WORK FOR THE EXAMPLE IN THE WEBSITE
                SINCE YOU ALREADY RETURNED FALSE ...
                AND DIN'T CHECK FOR THE FURTHER NODES
                SO BECAUSE OF NOT EXPLORING THE NODES... AND GETTING RETURNED (FALSE) AFTER 4
                YOU ARE GETTING WRONG ANSWER
                SEE THE GIF ABOVE PSUDOCODE... YOU WILL UNDERSTAND
               */
                if (checkCycle(nbr, vis, adj, src) == true)
                {
                    return true;
                }
            }
            else if (vis[nbr] == 1 && nbr != parent) 
            {
                return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        // creating visited vector
        // vector<int> vis(V);
        int vis[V] = {0};

        // connnected components
        for (int i = 0; i < V; i++)
        {
            int src = i;
            if (vis[src] == 0)
            {
                if (checkCycle(src, vis, adj, -1) == true)
                {
                    return true;
                }
                else
                {
                    // check for other components
                    continue;
                }
            }
        }

        return false;
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
