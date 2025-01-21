class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i< flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        std::queue<tuple<int,int,int>> q;
        q.push({0,src,0});

        std::vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto [stop,curr,cost] = q.front();
            q.pop();
            // int stop = curr.first;
            if (stop>k) break;

            for (auto elem : adj[curr]){
                if(dist[elem.first]> cost+elem.second)
                {
                    q.push({stop+1,elem.first,cost+elem.second});
                    dist[elem.first] = cost+elem.second;
                }
            }

        }

        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
        
    }
};