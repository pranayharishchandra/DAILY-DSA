#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;


// O(n2) + set 
class Solution
{
private:
    bool solve(int arr[], int n, int x)
    {
        set<vector<int>> allUniqueTriplets;

        // ele , freq // ele , freq
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
            um[arr[i]]++;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int first = arr[i];
                int second = arr[j];

                um[arr[i]]--;
                um[arr[j]]--;

                int third = x - first - second;

                if (um.find(third) != um.end() && um[third] > 0)
                {
                    vector<int> temp;
                    temp = {first, second, third};
                    sort(temp.begin(), temp.end());
                    allUniqueTriplets.insert(temp);
                }

                um[arr[i]]++;
                um[arr[j]]++;
            }
        }

        vector<vector<int>> ans(allUniqueTriplets.begin(), allUniqueTriplets.end());

        if (ans.size() > 0)
            return true;
        else
            return false;
    }

public:
    bool find3Numbers(int A[], int n, int X)
    {
        // Your Code Here
        bool ans = solve(A, n, X);
        return ans;
    }
};

// BETTER -- tc : o(n2) + sotring
class Solution2 
{
private:
    bool solve(int arr[], int n, int x)
    {

        vector<vector<int>> ans;
        // sort(arr, arr + n, greater<int>());
        sort (arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = x - arr[i] - arr[j] - arr[k];
                if (sum > 0)
                    j++;
                else if (sum < 0)   
                    k--;
                else {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    k--;
                    j++;

                    // doing the below to avoid duplicate triplets
                    while(arr[k] == arr[k + 1]) 
                        k--;
                    while(arr[j] == arr[j - 1])
                        j++;
                }
            }
        }
        if (ans.size() > 0) return true;
        else return false;
    }

public:
    bool find3Numbers(int A[], int n, int X)
    {
        // Your Code Here
        bool ans = solve(A, n, X);
        return ans;
    }
};



