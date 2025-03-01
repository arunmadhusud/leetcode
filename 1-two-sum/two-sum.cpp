class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_set<int> diff;
        std::unordered_map<int,int> mp;
        std::vector<int> result;
        for(int i = 0; i< nums.size(); i++){
            int d = target-nums[i];
            if(diff.find(d)!=diff.end()){
                result.push_back(i);
                result.push_back(mp[d]);
                return result;
            }
            else {
                diff.insert(nums[i]);
                mp[nums[i]] = i;
            }
        }
        return result;
    }
};