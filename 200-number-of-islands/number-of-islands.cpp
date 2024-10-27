class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<std::pair<int,int>> q;
        
        int islandCount = 0;
        for (int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1' && visited[i][j] == 0){
                    q.push({i,j});
                    while(!q.empty()){
                        std::pair<int,int> curr = q.front();
                        q.pop();
                        int r = curr.first;
                        int c = curr.second;
                        // Check all four neighbors
                        if (r - 1 >= 0 && visited[r - 1][c] == 0 && grid[r - 1][c] == '1') { // Up
                            q.push({r - 1, c});
                            visited[r - 1][c] = 1;
                            // isIsland = true;
                        }
                        if (r + 1 < grid.size() && visited[r + 1][c] == 0 && grid[r + 1][c] == '1') { // Down
                            q.push({r + 1, c});
                            visited[r + 1][c] = 1;
                            // isIsland = true;
                        }
                        if (c - 1 >= 0 && visited[r][c - 1] == 0 && grid[r][c - 1] == '1') { // Left
                            q.push({r, c - 1});
                            visited[r][c - 1] = 1;
                            // isIsland = true;
                        }
                        if (c + 1 < grid[0].size() && visited[r][c + 1] == 0 && grid[r][c + 1] == '1') { // Right
                            q.push({r, c + 1});
                            visited[r][c + 1] = 1;
                            // isIsland = true;
                        }                                           
                    }
                    islandCount++;
                }
            }
        }
        return islandCount;
        
    }
};