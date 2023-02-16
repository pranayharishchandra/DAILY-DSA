class Solution
{
public:

// alone visited is useful only when you are chaning visited like in this case
// intialClr organges visited along with grid -- since 2 was not being changed intialClr)
    // void dfs(vector<vector<int>> &vis ,vector<vector<int>> &image, int r, int c ,int newColor, int drow[], int dcol[])
    void dfs(auto &vis, auto &image, int r, int c, int newColor, int drow[], int dcol[], int iniclr)
    {

        int n = image.size();
        int m = image[0].size();

        // visited and work
        vis[r][c] = newColor;

        // calling the unvisited nbrs
        for (int i = 0; i < 4; i++)
        {
            int x = r + drow[i];
            int y = c + dcol[i];

            if (x >= 0 && y >= 0 && x < n && y < m)
            {
                // check connected
                // if connected then check
                // if not already visited
                if (image[x][y] == iniclr && vis[x][y] != newColor)
                {
                    dfs(vis, image, x, y, newColor, drow, dcol, iniclr);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int iniclr = image[sr][sc];
        
        // WRITE THIS CONDITION OTHER WISE YOUR CODE WILL GIVE RUNTIME ERROR
        if (iniclr == newColor)
            return image;

        // vector<vector<int>> vis = image;
        auto vis = image;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // dfs(vis, image, sr, sc, newColor, drow, dcol, iniclr);

        // BFS
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>> q;
        
        // push q and mark visited
        q.push({sr,sc});
        vis[sr][sc] = newColor;
        

        
        while(q.size() > 0)
        {
            auto it = q.front();
            q.pop();
            int sx = it.first;
            int sy = it.second;
            
            for (int i = 0; i < 4; i++)
            {
                int x = sx + drow[i];
                int y = sy + dcol[i];
                
                if (x >= 0 && y >= 0 && x < n && y < m)
                {
                    // unvisited clr
                    // if (image[x][y] == iniclr && vis[x][y] != newColor)
                    if (image[x][y] == iniclr && vis[x][y] == iniclr) // why is this condition wrong?
                    
                    {
                        q.push({x,y});
                        vis[x][y] = newColor; // marked visited
                    }
                }
            }
        }
        
        return vis;
    }
};
