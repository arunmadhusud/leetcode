class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for (int i = 0; i< nums.size(); i++)
        {
            int num_diff = target - nums[i];
            auto it_vec = std::find(nums.begin() + i + 1, nums.end(), num_diff);
            if (it_vec!= nums.end())
            {
                indices.push_back(i);
                indices.push_back(it_vec - nums.begin() );
                return indices;
            }
        }
    return indices;
    }
};