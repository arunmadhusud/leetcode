class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj_list(V);
        vector<int> indegree(V,0);
        std::queue<int> q;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj_list[b].push_back(a);   
            indegree[a]++; 
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
        
        if(topo.size()!=V) return false;
        return true;
        
    }
};