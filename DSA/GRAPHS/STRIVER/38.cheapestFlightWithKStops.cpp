class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int Qsrc, int dst, int k)  
    {
        // write your code here
        vector<pair<int,int>> adj[n];
        for (auto edge : flights)
        {
            int src = edge[0];
            int nbr = edge[1];
            int wt  = edge[2];

            adj[src].push_back({nbr, wt});
            // adj[nbr].push_back({src, wt});
        }

        // creating priority queue and distance
        vector<int> dis(n, INT_MAX);
        // priority_queue<pair<int, pair<int,int>>, vector<pair< int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        queue<pair<int, pair<int,int>>> q;

        // {stop, {dis, node}} -- wrong
        // {stop, {dis, node}}
        q.push({-1 ,{0, Qsrc}});
        dis[Qsrc] = 0;

        while (q.size())
        {
            // auto it  = q.top();
            auto it  = q.front();
            
            q.pop();
            int stop = it.first;
            int dsf  = it.second.first;
            int src  = it.second.second;

            if (stop == k) continue;

            for (auto ed : adj[src])
            {
                int nbr  = ed.first;
                int dist = ed.second;

                if (dis[nbr] > dsf + dist)
                {
                    dis[nbr] = dsf + dist;
                    q.push({stop - 1,{dis[nbr], nbr}});
                }
            }

        }
        if (dis[dst] == INT_MAX) return -1;
        return dis[dst];
    }
};

/* 
 * YOU CAN'T SOLVE IT PB PQ -- {dist, {stop, node}}
 * doing it with pq will be usless since you can't do - dist, stop, node -- it's giving me wrong answer -- this is because:
 * dis[node] will be updated to a let's say 4 but it's stops are over and by this route we can't reach to out destination ...
 * now we are going to other path .. and that path will actully give us the correct answer .. dis[node] is coming out to be 5 ... 
 * dis[node] will now should be updated to 5 .. but can't be updated because of line 45 condition... so {5,stop, node}... this node will never be pushed into the pq
 * so the node will become src .. so that reqired path will never be explored and hence you will never get your answer
 
 * so you will have to -- {stop, {dist, node}}
 * but the stop will always always be in inc. order so better use queue
 * below input is giving correct answer using queue but wrong answer using priotity_queue -- Why?
    5 6
    0 1 5
    1 2 5
    0 3 2
    3 1 2
    1 4 1
    4 2 1
    0
    2
    2
 */

/*
  this quesition was solved when using queue and stops   : -1 to k  and k + 1 to 0 as well
                                 usning pq   and stops   : -1 to k 
  but was giving wrong ans for above test case for queue : k + 1 to 0                                                                  
 */


/* BELOW CODE IS GIVING ME WRONG OUTPUT FOR THE ABOVE GIVEN TEST CASE */
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int Qsrc, int dst, int k)  
    {
        // write your code here
        vector<pair<int,int>> adj[n];
        for (auto edge : flights)
        {
            int src = edge[0];
            int nbr = edge[1];
            int wt  = edge[2];

            adj[src].push_back({nbr, wt});
            // adj[nbr].push_back({src, wt});
        }

        // creating priority queue and distance
        vector<int> dis(n, INT_MAX);
        // priority_queue<pair<int, pair<int,int>>, vector<pair< int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        queue<pair<int, pair<int,int>>> q;

        // {stop, {dis, node}} -- wrong
        // {stop, {dis, node}}
        q.push({k ,{0, Qsrc}});
        dis[Qsrc] = 0;

        while (q.size() > 0)
        {
            auto it  = q.front();
            // auto it  = q.top();
            q.pop();
            int stop = it.first;
            int dsf  = it.second.first;
            int src  = it.second.second;

            if (stop == -1) continue;

            for (auto ed : adj[src])
            {
                int nbr  = ed.first;
                int dist = ed.second;

                if (dis[nbr] > dsf + dist)
                {
                    dis[nbr] = dsf + dist;
                    q.push({stop - 1,{dis[nbr], nbr}});
                    // q.push({stop + 1,{dis[nbr], nbr}});
                }
            }
        }
        if (dis[dst] == INT_MAX) return -1;
        return dis[dst];
    }
};
