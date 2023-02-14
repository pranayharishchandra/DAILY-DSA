#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
    // MODIFIED 28th question
    // SET PROGRAM
    // MODIFICATION == 28 --> 29 (QUEUE) --> 29 (PQ) --> 29 (SET)
    // Dijkstra Algorithm -- SET
	//Function to find the shortest distance of all the vertices
public:
    vector <int> dijkstra(int N, vector<vector<int>> adj[], int Qsrc)
    {
        // code here      

        int dis[N];
        
        for (int i = 0; i < N; i++) dis[i] = INT_MAX;
        
        // queue<int> q;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        set<pair<int, int>> s;

        dis[Qsrc] = 0;
        // q.push(Qsrc);
        // pq.push({dis[Qsrc], Qsrc});
        s.insert({dis[Qsrc], Qsrc});


        // while (pq.size() > 0)
        while (s.size() > 0)
        {
            // int src = q.front();
            // q.pop();
            // int wtSrc = pq.top().first;
            // int src   = pq.top().second;
            // pq.pop();
            auto top_it = *(s.begin());
            int src = top_it.second;
            int srcWt = top_it.first;

            s.erase({srcWt, src});

            for (auto edge : adj[src])
            {
                int nbr = edge[0];
                int wt  = edge[1];

                if (dis[nbr] > dis[src] + wt)
                {
                    if (dis[nbr] != INT_MAX)            // *** if some useless node is present in set which has updated it from INT_MAX 
                        s.erase({dis[nbr],nbr});       //  *** erase that node from the set

                    dis[nbr] = dis[src] + wt;
                    // q.push(nbr);
                    // pq.push({dis[nbr], nbr});
                    s.insert({dis[nbr], nbr});
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
 * Original parameters -- of this question
 * // from the source vertex S.
 * vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
 */

/*
 * SET -- {dist, node} -- eg {{10,5}, {8,5}} -- 5 is at a dist 10, 8 -- so  delete (erase) -- {10,5} from set since using bigger distace is useless
 * so ADVANTAGE OF USING SET IS ==> you can erase useless elements and can save an iteration
 * BUT -- erasing an element takes  O(Log N) time -- and you are saving only 1 iteration <== DISVANTAGE
 * SO, IT DEPENDS ON THE TYPE OF GRAPH .. USING WHAT WILL BE BETTER -- "set" or "priority_queue"
 * there is no clear winner
 */

/*
 * Some elements that are not conneted to the src will never get visited so we will
 * since we initalized the visited with INT_MAX
 * we can't go to those elements so their dis will remain INT_Mz
 * and then you change it it to -1 as per the question demand
 */
