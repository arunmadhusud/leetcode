class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        
        // Building the adjacency list
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        // Use long long for distance and path count to avoid overflow
        vector<long long> dst(n, LLONG_MAX);
        vector<int> paths(n, 0);

        // Initializing the source node
        dst[0] = 0;
        paths[0] = 1;

        // Priority queue for Dijkstra's algorithm (min-heap)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        // Dijkstra's algorithm to find the shortest path and count the paths
        while (!pq.empty()) {
            int curr_node = pq.top().second;
            long long curr_dist = pq.top().first;  // Use long long for current distance
            pq.pop();

            for (auto& elem : adj[curr_node]) {
                int elem_node = elem.first;
                long long elem_dist = elem.second;  // Use long long for edge distance

                // If we find another shortest path to the node, update paths count
                if (dst[elem_node] == (curr_dist + elem_dist)) {
                    paths[elem_node] = (paths[elem_node] + paths[curr_node]) % MOD;
                }
                // If a shorter path is found, update the distance and reset path count
                else if (dst[elem_node] > curr_dist + elem_dist) {
                    dst[elem_node] = curr_dist + elem_dist;
                    pq.push({dst[elem_node], elem_node});
                    paths[elem_node] = paths[curr_node];
                }
            }
        }

        return paths[n - 1];
    }
};