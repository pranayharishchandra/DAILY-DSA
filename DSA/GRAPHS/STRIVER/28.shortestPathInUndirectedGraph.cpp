class Solution
{
    // UNDIRECTED GRAPH -- BFS
    // all edge wt are 1
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int Qsrc)
    {
        // code here

        // CREATING ADJ LIST ==> SRC - {{nbr, wt}, {nbr2, wt2},....}
        vector<pair<int, int>> adj[N];

        for (auto edge : edges)
        {
            int src = edge[0];
            int nbr = edge[1];
            int wt  = 1;

            adj[src].push_back(make_pair(nbr, wt));
            adj[nbr].push_back(make_pair(src, wt));
        }

        int dis[N];
        
        for (int i = 0; i < N; i++) dis[i] = INT_MAX;
        
        queue<int> q;

        q.push(Qsrc);
        dis[Qsrc] = 0;

        while (q.size() > 0)
        {
            int src = q.front();
            q.pop();

            for (auto edge : adj[src])
            {
                int nbr = edge.first;
                int wt  = edge.second;

                if (dis[nbr] > dis[src] + wt)
                {
                    dis[nbr] = dis[src] + wt;
                    q.push(nbr);
                }
            }
        }
        
        vector<int> dist(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (dis[i] != INT_MAX)
            {
                dist[i] = dis[i];
            }
        }

        return dist;
    }
};

/*
 * LINE 45 - pushing only when we get a shorter path -- which is not possible if we go front and come back ( wt x 2) -- so visited not required -
 * there can't be updation when going to nbr and again coming back
 * this is new type of visited -- just learn this method in these types of questions
 */
