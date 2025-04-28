class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<int> result;
        for(int i =0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(pq.size()<k) pq.push({it->second,it->first});
            else if(it->second > pq.top().first){
                pq.pop();
                pq.push({it->second,it->first});
            }
        }

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
        
    }
};