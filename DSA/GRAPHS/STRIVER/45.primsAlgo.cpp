class Solution
{
        // overall time complexity --> O(E x log E) + O(E x log E) = O(E x log E)
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // since you have to find min wt -- choose pq -- for lesser no of iterations
        // make a priority queue -- {wt,{node,parent}} and visited
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        vector<int> vis(V,0);

        pq.push({0,{0,-1}});
        // vis[0] = 1; // don't do it here

        bool flag = false;         // using it to ignore the first pair into MST i.e. (parent, src) (0, -1)
        int   sum = 0;
        vector<pair<int,int>> MST; // {{parent,src}}
        
        // time complexity of this loop --> E x log E
        while (pq.size() > 0) // O(E) // E edges will be inserted into it in worst case
        {
            auto it = pq.top(); // O(log E)
            pq.pop();

            int wt     = it.first;
            int src    = it.second.first;
            int parent = it.second.second;

            if (vis[src] == 1) continue;     // if already visited
            else               vis[src] = 1; // mark it as visited

            sum += wt;
            if (flag == false) {
                flag = true;
                // continue;                  // since we have to add it's nbrs as well
            }
            else {
                MST.push_back({parent,src});
            }

            // time complexity of this loop --> E x log E
            for (auto ed : adj[src])             // max E edges can be possibe of a node
            {
                int nbr  = ed[0];
                int edwt = ed[1];

                if (vis[nbr] == 1) continue;     // if nbr was visited.. means we have already got answer for it so don't add it again in pq
                else {
                    pq.push({edwt, {nbr, src}}); // O(log E) // {edwt, {src, parent}} 
                }
            }
        }

        // for (auto it : MST) cout << it.first << " " << it.second << endl;
        return sum;
    }
};


/*
 * NOTE 1: 1ST OCCURANCE OF A NODE TOP OF PQ ONLY HAS SIGNIFICANCE.
 * you may push a node (let's say node1) more than once but whenever the node1 will be on the top of the pq
 * then it will always be the node1 with the min distance/weight on the top of pq
 * after it all the node1 with wt2,or may be wt3 and so on will be always more than w1
 * so I CAN SAY THAT ONLY THE 1ST TIME I GOT NODE1 HAS SIGNIFICANCE AND OTHER EDGES OF NODE1 DON'T HAVE ANY SIGNIFICANCE
 * AND THE ARE JUST WASTE AND ARE IGNORED BY OUR PROGRAM becuase of the condtions we use ... 
 * more distance than previously got... IGNORE
 * here, already visited previously ... IGNORE
 
 * and to save one of such useless iteration(s) we use set and erase them in DIJKSTRA'S ALGO.
 */

/*
 * NOTE 2: CAN'T USE QUEUE
 * UNLIKE DIJKSTRA'S ALGO WE CAN'T SOLVE THIS PROBLEM ALSO USING QUEUE
 * because we only want the 1st and smallest wt having edge from the nbr.
 * then you will get sum more than or equal to the min sum... since your program is acutally not considering the smallest wt edge... so this point was obvious.
 */

/*
 * NOTE 3: 
 * use parent when you are asked to construct the MST -- in this question they haven't asked to us to create it
 * but to write code of both construct and sum in once prog. I have used it.
 */
