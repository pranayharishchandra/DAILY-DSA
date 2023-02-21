class Solution
// FLOYD WARSHALL ALGO -- multi source algo
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));

        for (auto ed : edges)
        {
            int src = ed[0];
            int nbr = ed[1];
            int wt = ed[2];

            mat[src][nbr] = wt;
            mat[nbr][src] = wt; // the distance from src to nbr is same as dist from nbr to src also
                                // bi-directional graph since if you can go from city i to city j
                                // then you can go to city j to city i as well
        }

        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }

        // FINDING DISTANCE BETWEEN ALL THE EDGES
        for (int via = 0; via < n; via++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (mat[i][via] != INT_MAX && mat[via][j] != INT_MAX)
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);

        int city = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int countNearCities = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] <= distanceThreshold)
                {
                    countNearCities++;
                }
            }

            // update when you get city with min no. of near cities
            // if 2 cities have same near cities then prefer the bigger no, city
            if (minCount >= countNearCities)
            {
                city = i;
                minCount = countNearCities;
            }
        }

        return city;
    }
};
