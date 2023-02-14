class Solution
{
    // MODIFIED 28th question
    // MODIFIED QUEUE PROGRAM
    // MODIFICATION == 28 --> 29(QUEUE)
    // Dijkstra Algorithm -- QUEUE
	//Function to find the shortest distance of all the vertices
public:
    vector <int> dijkstra(int N, vector<vector<int>> adj[], int Qsrc)
    {
        // code here      

        int dis[N];
        
        for (int i = 0; i < N; i++) dis[i] = INT_MAX;
        
        // queue<int> q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        dis[Qsrc] = 0;
        // q.push(Qsrc);
        pq.push({dis[Qsrc], Qsrc});

        while (pq.size() > 0)
        {
            // int src = q.front();
            // q.pop();
            int wtsrc = pq.top().first;
            int src   = pq.top().second;
            pq.pop();

            for (auto edge : adj[src])
            {
                int nbr = edge[0];
                int wt  = edge[1];

                if (dis[nbr] > dis[src] + wt)
                {
                    dis[nbr] = dis[src] + wt;
                    // q.push(nbr);
                    pq.push({dis[nbr], nbr});
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
 * LINE 50 - pushing only when we get a shorter path -- which is not possible if we go front and come back ( wt x 2) -- so visited not required 
 * there can't be updation when going to nbr and again coming back
 * this is new type of visited -- just learn this method in these types of questions
 */

/*
 * Original parameters -- of this question
 * // from the source vertex S.
 * vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
 */
