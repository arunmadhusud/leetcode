class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::vector<std::pair<int,int>> rot_idx;
        std::queue<std::pair<int,int>> q;
        std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                     q.push({i,j});
                     visited[i][j] = true;

                }
            }
        }

        // if (q.size() == 0) return -1;

        int time = 0;
        

        while(!q.empty()){
            int k = q.size();
            bool rotted = false;
            for (int i = 0; i < k; i++)
            {   
                std::pair<int,int> cur = q.front();
                int r = cur.first;
                int c = cur.second;
                q.pop();                
                if ( r-1 >= 0 && !visited[r-1][c] && grid[r-1][c]!=0)
                {
                    visited[r-1][c] = true;
                    grid[r-1][c] = 2;
                    q.push({r-1,c});
                    rotted = true;
                }
                if ( c-1 >= 0 && !visited[r][c-1] && grid[r][c-1]!=0)
                {
                    visited[r][c-1] = true;
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                    rotted = true;
                }
                if ( r+1 < grid.size() && !visited[r+1][c] && grid[r+1][c]!=0)
                {
                    visited[r+1][c] = true;
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                    rotted = true;
                }
                if ( c+1 < grid[0].size() && !visited[r][c+1] && grid[r][c+1]!=0)
                {
                    visited[r][c+1] = true;
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                    rotted = true;
                }                
            }
            if (rotted) time++;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }       
    
    return time;
        
    }
};