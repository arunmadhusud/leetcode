class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for (size_t i=0; i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int count = INT_MAX;
        int result;
        for (int i = 0; i < n; i++){
            int tmp = dijkstra(i,adj,distanceThreshold);
            if ( tmp <= count) {
                count = min(count,tmp);
                result = i;
            }
        }

        return result;

        
    }

    int dijkstra(int k, vector<vector<pair<int,int>>>& adj, int& distanceThreshold){
        vector<int> dst(adj.size(),INT_MAX);
        dst[k] = 0;
        std::priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [curr_dist,curr_node] = pq.top();
            pq.pop();

            for(const auto& [elem_node,elem_dst] : adj[curr_node]){
                if (dst[elem_node]>dst[curr_node]+elem_dst) {
                    dst[elem_node]=dst[curr_node]+elem_dst;
                    pq.push({dst[elem_node],elem_node});
                }
            }
        }
        int count = 0;
        for (int i = 0; i< dst.size(); i++){
            if(dst[i]<=distanceThreshold) count++;
        }
        return count;

    }
};