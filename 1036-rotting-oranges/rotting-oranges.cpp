class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        std::queue<std::pair<int,int>> q;
        int time = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j=0; j < grid[0].size(); j++)
            {
                if(grid[i][j]==2) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        
        while(!q.empty())
        {   

            bool rotted = false;
            int k = q.size();
            for (int i = 0; i < k ; i++)
            {
                std::pair<int,int> cur = q.front();
                int r = cur.first;
                int c = cur.second;
                q.pop();
                if ((r-1)>=0 && !visited[r-1][c] && grid[r-1][c] != 0)
                {
                    q.push({r-1,c});
                    visited[r-1][c] = true;
                    grid[r-1][c] = 2;
                    rotted = true;
                }
                if ((r+1)<grid.size() && !visited[r+1][c] && grid[r+1][c] != 0)
                {
                    q.push({r+1,c});
                    visited[r+1][c] = true;
                    grid[r+1][c] =  2;
                    rotted = true;
                }   
                if ((c-1)>=0 && !visited[r][c-1] && grid[r][c-1] != 0)
                {
                    q.push({r,c-1});
                    visited[r][c-1] = true;
                    grid[r][c-1] = 2;
                    rotted = true;
                } 
                if ((c+1)<grid[0].size() && !visited[r][c+1] && grid[r][c+1] != 0)
                {
                    q.push({r,c+1});
                    visited[r][c+1] = true;
                    grid[r][c+1] = 2;
                    rotted = true;
                }
            }
            if (rotted) time++;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j=0; j < grid[0].size(); j++)
            {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return time;
        
    }
};