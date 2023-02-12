// User function Template for C++

class Solution{
private:
    void topoSort(vector<int> adj[], vector<int> &topo, int K)
    {
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
            // pair<int, int> priorityOrder = findPriority(dict[i], dict[i + 1]); <-- making other funciton is giving error
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int n = min(s1.length(), s2.length());

            for (int i = 0; i < n; i++)
            {
                if (s1[i] != s2[i])
                {
                    adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                    break;
                }
            }
        }

        vector<int> topo;

        topoSort(adj, topo, K);

        string ans = "";
        for (auto it : topo)
        {
            ans = ans + (char)(it + 'a');
        }

        return ans;
    }
};
