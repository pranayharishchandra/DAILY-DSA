class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        // Code here
        vector<int> dist(V, 1e8);

        dist[S] = 0; // dist from sourse to sourse will always be 0 .. only in negative cycle it will become zero

        for (int i = 0; i < V; i++)
        {
            for (auto edge : edges)
            {
                int src = edge[0];
                int nbr = edge[1];
                int wt = edge[2];

                if (dist[src] != 1e8 && dist[nbr] > dist[src] + wt)
                {
                    dist[nbr] = dist[src] + wt;
                }
            }
        }

        // DETECTING THE NEGATIVE CYCLE -- ths dist will still keep on reducing .. as sum of all edges of the cycle will be negative
        // and that negative will reduce distance for the next NTH iteration
        for (auto edge : edges)
        {
            int src = edge[0];
            int nbr = edge[1];
            int wt = edge[2];

            if (dist[src] != 1e8 && dist[nbr] <= dist[src] + wt)
            {
                // everytings is fine till now...
                continue;
            }

            if (dist[src] != 1e8 && dist[nbr] > dist[src] + wt)
            {
                // return true; // neg cycle exists
                return {-1};
            }
        }

        // return false; // neg cycle not exists
        return dist;
    }
};
/*
 * order of edges don't matter
 * since we will run the loop for N - 1 times so we will get the required answer may be before but surely after N - 1 iterations
 * Why N - 1 iterations
 * take an example .. in worst case you are given a linera graph .. and the ORDER of  edges is given in such a way that {(3, 4, wt), (2, 3, wt), (1, 2, wt), (0, 1, wt)}
 * so in this case you will get the required answer in N - 1 iterations
 *
 * ALSO NOTES THAT :
 * NOTE 1: HANDLING INT_MAX
 * if you add some interger in INT_MAX then it can become smallest INTEGER -2...........7
 * so to handle this you will have to use a condition
 * if (dist[src] != INT_MAX && dist[src] + edgeWt < dist[nbr])
 * { statement(s); } -- updating the dist[nbr] with the smaller value
 *
 *
 * NOTE 2: NEGATIVE CYCLE
 * if you have any of a negative cycle (i.e. a cycle whose all edge sum is a negative number)
 * in that case you will not get your answer in N - 1 iterations
 * and to detect if there exists a negative cycle  -- you just need to write a loop again i.e. your Nth iteration
 * and now you can check if after the Nth iteraiton your array remains same then you didn't have neg. cycle
 * if while checking you get change in any index in dist array in Nth iteration then you can stop there only and say that a neg cycle exists in the graph
 *
 *
 * OBERVATION 1: ONLY AFTER THE SOURCE COME form there we can start using dist array... see the dry run.. this is not very imp. obs
 */
