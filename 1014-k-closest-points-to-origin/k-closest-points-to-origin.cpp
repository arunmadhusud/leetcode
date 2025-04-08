class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // std::priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, std::greater<pair<int,vector<int>>>> pq;
        vector<vector<int>> result;
        std::priority_queue<pair<int,vector<int>>> pq;
        for(vector<int> elem : points){
            int dist = elem[0]*elem[0] + elem[1]*elem[1] ;           
            if(pq.size()<k) pq.push({dist,elem});
            else {
                if(pq.top().first > dist) {
                    pq.pop();
                    pq.push({dist,elem});
                }
            }
        }
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
        
    }
};