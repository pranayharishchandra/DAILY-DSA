class Solution
{
    // MODIFIED 28th question
    // Dijkstra Algorithm -- QUEUE
	//Function to find the shortest distance of all the vertices
public:
    vector <int> dijkstra(int N, vector<vector<int>> adj[], int Qsrc)
    {
        // code here      

        // CREATING ADJ LIST ==> SRC - {{nbr, wt}, {nbr2, wt2},....}
        // CREATING ADJ LIST ==> SRC - {{nbr, wt}, {nbr2, wt2},....}
        // vector<pair<int, int>> adj[N];

        // for (auto edge : edges)
        // {
        //     int src = edge[0];
        //     int nbr = edge[1];
        //     int wt  = 1;

        //     adj[src].push_back(make_pair(nbr, wt));
        //     adj[nbr].push_back(make_pair(src, wt));
        // }

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
                // int nbr = edge.first;
                // int wt  = edge.second;
                int nbr = edge[0];
                int wt  = edge[1];

                if (dis[nbr] > dis[src] + wt) // UPDATE DISTANCE WHEN YOU GET A SHORTER DISTANCE TO A NODE 
			                      // AND THEN PUSH IS INTO QUEUE SO THIS NBR CAN ACT AS SRC FOR IT'S NBRS 
			                      // and that's how u will find distance for unexplored nodes from the src
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
 * LINE 50 - pushing only when we get a shorter path -- which is not possible if we go front and come back ( wt x 2) -- so visited not required 
 * there can't be updation when going to nbr and again coming back
 * this is new type of visited -- just learn this method in these types of questions
 */

/*
 * Original parameters -- of this question
 * // from the source vertex S.
 * vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
 */

/* queue is the slowest better use priority_queue
 * negative weights can't be handled by the Dijkstra Algorithm 
 * you can do a dry run -- of 2 nodes and a negative edge between them 
 * you will notice that the negaive will keep increasing -1 + (-1) = -2 
 * and -2 is better tham -1 in since Dijkstra Algorithm updates when you get shorter a distance to a node -- LINE - 46 
 * so it will become infinte as negative will keep on increasing according to this condition.
 */
