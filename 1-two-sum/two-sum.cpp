class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // std::unordered_set<int> diff;
        std::unordered_map<int,int> mp;
        std::vector<int> result;
        for(int i = 0; i< nums.size(); i++){
            int d = target-nums[i];
            if(mp.find(d)!=mp.end()){
                result.push_back(i);
                result.push_back(mp[d]);
                return result;
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return result;
    }
};