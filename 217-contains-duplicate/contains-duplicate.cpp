class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> num_set;
        for (int i = 0; i < nums.size(); i++)
        {
            num_set.insert(nums[i]);
        }
        if(num_set.size()!= nums.size())
        {
            return true;
        }
        return false;        
    }
};