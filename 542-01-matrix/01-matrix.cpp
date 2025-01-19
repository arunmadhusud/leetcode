class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> grid(mat.size(),vector<int>(mat[0].size(),-1));
        std::queue<std::pair<int,int>> q;
        for (int i = 0; i< mat.size(); i++){
            for (int j = 0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    grid[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<std::pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int r,c,nr,nc;
        while(!q.empty()){
            std::pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for (auto& d : dir){
                int nr = r+d.first;
                int nc = c+d.second;
                if(nr>=0 && nc >=0 && nr < mat.size() && nc < mat[0].size() && grid[nr][nc]==-1){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return grid;        
    }
};