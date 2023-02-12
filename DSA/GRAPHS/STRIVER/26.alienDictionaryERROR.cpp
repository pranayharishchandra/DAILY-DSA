#include <bits/stdc++.h>
using namespace std;

// idk why it's giving me run time error when using a function to find priority 

class Solution
{

private:
    pair<int, int> findPriority(string &s1, string &s2) // RTE becz of this...
    {
        int n = min(s1.length(), s2.length());

        int i;
        for (i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                return make_pair(s1[i] - 'a', s2[i] - 'a');
            }
        }

        return make_pair(s1[i] - 'a', s2[i] - 'a');
    }

    void topoSort(vector<int> adj[], vector<int> &topo, int K)
    {
        int V = K;

        int ind[K] = {0};

        for (int i = 0; i < K; i++)
        {
            int src = i;
            for (auto nbr : adj[src])
            {
                ind[nbr]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < K; i++)
        {
            int node = i;
            if (ind[node] == 0)
                q.push(node);
        }

        while (q.size() > 0)
        {
            int src = q.front();
            q.pop();

            topo.push_back(src);

            for (auto nbr : adj[src])
            {
                ind[nbr]--;
                if (ind[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            pair<int, int> priorityOrder = findPriority(dict[i], dict[i + 1]);

            adj[priorityOrder.first].push_back(priorityOrder.second);
        }

        vector<int> topo;

        topoSort(adj, topo, K);

        int n = topo.size();

        string ans = "";

        for (auto it : topo)
        {

            ans = ans + (char)(it + 'a');
        }

        return ans;
    }
};
