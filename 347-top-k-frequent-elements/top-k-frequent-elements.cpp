class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        for(int i =0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        for (const auto &elem : mp) {
            std::cout << elem.first << " -> " << elem.second << std::endl;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }

        for(int i =0; i<k && (!pq.empty()); i++){
            result.push_back(pq.top().second);
            pq.pop();

        }

        return result;
        
    }
};