class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
        std::queue<std::pair<int, int>> q;
        int islandCount = 0;
        for (int i = 0; i<grid.size(); i++){
            for (int j =0; j<grid[0].size(); j++){  
                if(!visited[i][j] && grid[i][j] == '1' ) {             
                    q.push({i,j});
                    visited[i][j] = true;                    
                    while(!q.empty()){
                        std::pair<int, int> curr = q.front();
                        q.pop();
                        int r = curr.first;
                        int c = curr.second;
                        if ((r-1)>=0 && !visited[r-1][c] && grid[r-1][c] == '1')
                        {
                            q.push({r-1,c});
                            visited[r-1][c] = true;
                        }
                        if ((r+1)<grid.size() && !visited[r+1][c] && grid[r+1][c] == '1')
                        {
                            q.push({r+1,c});
                            visited[r+1][c] = true;
                        }   
                        if ((c-1)>=0 && !visited[r][c-1] && grid[r][c-1] == '1')
                        {
                            q.push({r,c-1});
                            visited[r][c-1] = true;
                        } 
                        if ((c+1)<grid[0].size() && !visited[r][c+1] && grid[r][c+1] == '1')
                        {
                            q.push({r,c+1});
                            visited[r][c+1] = true;
                        }

                    }
                    islandCount++;                                      

                }                    
                
            }
        }
    return islandCount;    
    }
};