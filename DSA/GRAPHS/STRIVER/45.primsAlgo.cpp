class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // since you have to find min wt -- choose pq -- for lesser no of iterations
        // make a priority queue -- {wt,{node,parent}} and visited
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int> vis(V, 0);

        // push src and mark it visited
        // let 0 be the src since no src is given
        pq.push({0,{0,-1}});
        // vis[0] = 1; // don't mark visited here otherwise 0 will be continued and it's nbrs will not be called

        bool flag = false;
        int sum = 0;
        
        // if the question asked you to construct one of the min spanning tree
        vector<pair<int,int>> constructSpanningTree;

        // in worst case our pq will have all edges -- so our while loop is gonna run E times
        while (pq.size() > 0)
        {
            auto it = pq.top();
            pq.pop();

            int     wt = it.first;
            int    src = it.second.first;
            int parent = it.second.second;

            if (vis[src] == 1) continue; // this line is actually not required since alread we mark visited in for loop
            else vis[src] = 1;

            sum += wt;
            if (flag == true)   constructSpanningTree.push_back({paren, src});
            else if (flag == false) flag = true;
            
            // cout << "src  = " << src << endl;

            for (auto ed : adj[src])
            {
                int nbr  = ed[0];
                int edwt = ed[1];

                // add into pq ~if you get a better~ all the edges to the nbr which is unvisited 
                if (vis[nbr] == 1) continue;
                else if (vis[nbr] == 0)
                {
                    pq.push({edwt, {nbr, src}});
                }
            }
        }
        
        // printing out min spanning tree.. code is working fine for it as well
        for (auto it :constructSpanningTree ) cout << it.first << " " << it.second << endl;
        
        return sum; 
    }
};
/*
 * NOTE 1:
 * you may push a node (let's say node1) more than once but whenever the node1 will be on the top of the pq
 * then it will always be the node1 with the min distance/weight on the top of pq
 * after it all the node1 with wt2,or may be wt3 and so on will be always more than w1
 * so I CAN SAY THAT ONLY THE 1ST TIME I GOT NODE1 HAS SIGNIFICANCE AND OTHER EDGES OF NODE1 DON'T HAVE ANY SIGNIFICANCE
 * AND THE ARE JUST WASTE AND ARE IGNORED BY OUR PROGRAM becuase of the condtions we use ... 
 * more distance than previously got... IGNORE
 * here, already visited previously ... IGNORE
 
 * and to save one of such useless iteration(s) we use set and erase them in DIJKSTRA'S ALGO.
 */
