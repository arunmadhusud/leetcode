class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int area;
        std::vector<std::vector<int>> visited(grid.size(),std::vector<int>(grid[0].size(),false));
        std::queue<std::pair<int,int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j=0; j< grid[0].size(); j++){
                if(grid[i][j]==1 && !visited[i][j])
                {   
                    
                    q.push({i,j});
                    visited[i][j] = 1;
                    area = 1;              
                
                    while(!q.empty()){
                        std::pair<int,int> curr = q.front();
                        int r = curr.first;
                        int c = curr.second;
                        q.pop();
                        if (r-1>=0 &&  grid[r-1][c]==1 && !visited[r-1][c]){
                            visited[r-1][c] = true;
                            q.push({r-1,c});
                            area++;
                        }
                        if (c-1>=0 &&  grid[r][c-1]==1 && !visited[r][c-1]){
                            visited[r][c-1] = true;
                            q.push({r,c-1});
                            area++;
                        }
                        if (r+1<grid.size() &&  grid[r+1][c]==1 && !visited[r+1][c]){
                            visited[r+1][c] = true;
                            q.push({r+1,c});
                            area++;
                        }
                        if (c+1<grid[0].size() &&  grid[r][c+1]==1 && !visited[r][c+1]){
                            visited[r][c+1] = true;
                            q.push({r,c+1});
                            area++;
                        }
                    }
                    max_area = std::max(max_area,area);
                }

            }
        }
        return max_area;
        
    }
};