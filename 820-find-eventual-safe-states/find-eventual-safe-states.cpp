class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        vector<int> safeNodes;
        vector<vector<int>> revGraph(graph.size());
        vector<int> indegree(graph.size(),0);
        for(int i = 0; i < graph.size(); i++){
            if(graph[i].size()==0) safeNodes.push_back(i);
            for (int j = 0; j < graph[i].size(); j++) {
                revGraph[graph[i][j]].push_back(i);
                indegree[i]++;
            }          
        }
        std::queue<int> q;
        for(int i = 0; i < safeNodes.size(); i++ ){
            q.push(safeNodes[i]);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                for(int elem : revGraph[curr]){
                    indegree[elem]--;
                    if(indegree[elem]==0) {
                        q.push(elem);
                    }
                }
            }
        }
        std::sort(result.begin(),result.end());
        return result;        
    }
};