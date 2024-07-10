// #include <vector>
// #include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> output;
        for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
            auto it_vec = std::find(itr+1, nums.end(), target - (*itr));
            if (it_vec != nums.end()) {
                output.push_back(std::distance(nums.begin(), itr));
                output.push_back(std::distance(nums.begin(), it_vec));
                break;
            }
        }
        return output;
    }
};
