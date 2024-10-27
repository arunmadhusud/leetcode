class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<std::pair<int, int>> q;

        for(int i=0; i < grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        
        int count = 0;        
        while(!q.empty()){
            bool hasRotten = false;
            int n = q.size();
            for(int i=0; i< n; i++){
                std::pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                if(r - 1 >= 0 && !visited[r - 1][c] && grid[r - 1][c] == 1) {
                    q.push({r - 1, c});
                    visited[r - 1][c] = true;
                    grid[r - 1][c] = 2;
                    hasRotten = true;
                }
                if(r + 1 < grid.size() && !visited[r + 1][c] && grid[r + 1][c] == 1) {
                    q.push({r + 1, c});
                    visited[r + 1][c] = true;
                    grid[r + 1][c] = 2;
                    hasRotten = true;
                }
                if(c - 1 >= 0 && !visited[r][c - 1] && grid[r][c - 1] == 1) {
                    q.push({r, c - 1});
                    visited[r][c - 1] = true;
                    grid[r][c - 1] = 2;
                    hasRotten = true;
                }
                if(c + 1 < grid[0].size() && !visited[r][c + 1] && grid[r][c + 1] == 1) {
                    q.push({r, c + 1});
                    visited[r][c + 1] = true;
                    grid[r][c + 1] = 2;
                    hasRotten = true;
                }
            }
            if(hasRotten) count++;
        }

        for(const auto& row : grid) {
            for(const auto& cell : row) {
                if(cell == 1) return -1;
            }
        }
        return count;
        
    }
};