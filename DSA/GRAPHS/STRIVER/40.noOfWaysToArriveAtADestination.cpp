class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<int,int>> adj[n];
        for (auto ed : roads)
        {
            int src = ed[0];
            int nbr = ed[1];
            int wt  = ed[2];

            // bi-direcitonal roads
            adj[src].push_back({nbr, wt});
            adj[nbr].push_back({src, wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int> dis(n,INT_MAX);
        vector<int> ways(n, 0);

        int Qsrc = 0;
        pq.push({0,Qsrc});
        ways[Qsrc] = 1;
        dis[Qsrc] = 0;

        int modulo = (int)(1e9 + 7);
        
        while(pq.size() > 0)
        {
            auto it = pq.top();
            pq.pop();

            /*
            NOTE : YOU ALWAYS DO THE FOLLOWING MISTAKE -- RUNTIME ERROR
            int src = it.first;
            int dsf = it.second;
            */
            
            int src = it.second;
            int dsf = it.first;


            // cout << "src = " << src << ", ways = " << ways[src] << ", dsf = " << dsf << endl;
            
            for (auto ed : adj[src])
            {
                int nbr = ed.first;
                int dist = ed.second;
                

                if (dis[nbr] > dsf + dist)
                {
                    dis[nbr] = dsf + dist;  // updating distance till the nbr
                    pq.push({dis[nbr], nbr});
                    ways[nbr] = ways[src]; // updating ways to the nbr
                    
                }
                else if (dis[nbr] == dsf + dist)
                {
                    ways[nbr] = (ways[nbr] + ways[src]) % modulo; // updating ways to the nbr
                }
                
                // cout << "nbr = " << nbr << ", ways = " << ways[nbr] << ", dis[nbr] = " << dis[nbr] << ", dist = " << dist <<  endl;
            }
        }
        return ways[n - 1] % modulo;
    }   
};
