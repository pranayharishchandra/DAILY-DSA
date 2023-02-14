class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        // making dis array and initalizeing it with INT-MAX
        int n = grid.size();
        int m = grid[0].size();
        int dis[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    dis[i][j] = INT_MAX;
            }
        }

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // {edWt, {x,y}}
        pq.push({0, {source.first, source.second}});
        dis[source.first][source.second] = 0;

        while (pq.size() > 0)
        {
            // remove
            int srcWt = pq.top().first;
            int srcx = pq.top().second.first;
            int srcy = pq.top().second.second;
            
            pq.pop();

            // add nbrs
            for (int i = 0; i < 4; i++)
            {
                int nbrx = srcx + drow[i];
                int nbry = srcy + dcol[i];

                if (nbrx >= 0 && nbry >= 0 && nbrx < n && nbry < m)
                {
                    if (grid[nbrx][nbry] == 1)
                    {
                        int nbrWt = dis[nbrx][nbry];
                        int edgeWt = 1; // wt of edge between src and nbr

                        // if (nbrWt > srcWt + edgeWt)
                        if (dis[nbrx][nbry] > srcWt + edgeWt)
                        {
                            dis[nbrx][nbry] = srcWt + edgeWt;
                            pq.push({dis[nbrx][nbry], {nbrx, nbry}});
                            
                            // for optimisation write following
                            if (nbrx == destination.first && nbry == destination.second)
                                return dis[nbrx][nbry];
                        }
                    }
                }
            }
        }

        if (dis[destination.first][destination.second] == INT_MAX) 
            return -1;
        else 
            return dis[destination.first][destination.second];
    }
};
