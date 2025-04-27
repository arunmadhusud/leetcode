class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(V);
        vector<int> indegree(V,0);
        std::queue<int> q;
        
        for(int i = 0; i<prerequisites.size(); i++){
            adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]] ++;
        }
        
        for (int i = 0; i<V; i++) {
            if (indegree[i]==0) q.push(i);
        }
        
        std::vector<int> topo;
        while(!q.empty()){
            int curr =  q.front();
            q.pop();
            topo.push_back(curr);
            for (int elem : adj_list[curr]){
                indegree[elem]--;
                if (indegree[elem]==0) q.push(elem);
            }
        }
        
        if(topo.size()!=V) return {};
        std::reverse(topo.begin(),topo.end());
        return topo;        
    }
};