class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<bool> dfs_path(V, false);
        vector<int>  check(V, -1);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, dfs_path, adj, check);
            }
        }
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }

    bool dfs(int node, vector<bool>& visited,vector<bool>& dfs_path, vector<vector<int>>& adj,vector<int>&  check) {
        visited[node] = true;
        dfs_path[node] = true;
        for (int elem : adj[node]){
            if (!visited[elem]){
                if(dfs(elem,visited,dfs_path, adj,check)) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(dfs_path[elem]){ 
                return true;
            }
            }
        check[node] = 1;
        dfs_path[node] = false;
        return false;
    }
        
};