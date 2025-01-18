class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<int> color(graph.size(),-1);
        std::queue<int> q;
        int col = 0;
        for (int i = 0; i<graph.size(); i++){ 
            if (color[i] ==-1){
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for (int elem : graph[curr]){
                        if(color[elem]==-1){
                            color[elem] = 1-color[curr];
                            q.push(elem);
                        }
                        else if(color[elem]==color[curr]) return false;                        
                    }
                }

            }
        }
        return true;
    }
};