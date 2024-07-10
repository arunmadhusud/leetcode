class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int, std::greater<int>> new_set(nums.begin(),nums.end());
        if (new_set.size() == nums.size()) return false;
        else return true;
        
    }
};