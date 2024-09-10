class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> num_count;
        for (int i = 0; i < nums.size(); i++) {
            num_count[nums[i]]++;  // Count frequency of each number
        }
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        for (pair<int,int> elem : num_count)
        {
            pq.push({elem.second,elem.first});
        }
        while(k-- && !pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
 
    }
};