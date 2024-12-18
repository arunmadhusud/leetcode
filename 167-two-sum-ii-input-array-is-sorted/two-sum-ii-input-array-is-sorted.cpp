class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        int i = 0;
        int j = nums.size()-1;
        while(i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
            else if (nums[i] + nums[j] > target) j--;
            else if (nums[i] + nums[j] < target) i++;
        }
        return result;
        
    }
};