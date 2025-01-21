class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dst(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        dst[0][0] = 0;
        std::priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int r,c,nr,nc;
        int shortest_path = -1;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int curr_effort = curr.first;
            pair<int,int> curr_cell = curr.second;            
            r = curr_cell.first;
            c = curr_cell.second;
            if (r==heights.size()-1 && c==heights[0].size()-1) return curr_effort;
            for (auto d : dir){
                nr = r+d.first;
                nc = c+d.second;
                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size()){
                    int new_effort = abs(heights[nr][nc] - heights[r][c]);
                    int max_effort = max(new_effort,curr_effort);
                    if (max_effort < dst[nr][nc]) {
                        dst[nr][nc] = max_effort;
                        pq.push({max_effort,{nr,nc}});
                    }
                }

            }

        }
        return shortest_path;

        
    }
};