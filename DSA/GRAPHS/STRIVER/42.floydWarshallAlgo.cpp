class Solution
// FLOYD WARSHALL ALGO -- multi source algo
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // Code here
        // just converting -1 to INT_MAX
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == -1)
                    matrix[i][j] = INT_MAX;

        // FINDING DISTANCE BETWEEN ALL THE EDGES
        for (int via = 0; via < n; via++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX)
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);


        // just converting INT_MAX TO -1
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == INT_MAX)
                    matrix[i][j] = -1;
    }
};

// works only in a matrix... if you are given edges in place of a matirx then 
// create a matrix and don'tn forget to assign the diagonals to 0 [i][j] diagonals i == j
