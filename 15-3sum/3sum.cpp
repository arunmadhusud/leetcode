#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> fin_result;

        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicate values for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int k = i + 1;
            int j = nums.size() - 1;

            while (k < j) {
                int sum = nums[i] + nums[k] + nums[j];
                if (sum > 0) {
                    --j;
                } else if (sum < 0) {
                    ++k;
                } else {
                    // Add the valid triplet
                    fin_result.push_back({nums[i], nums[k], nums[j]});
                    
                    // Skip duplicate values for the second number
                    while (k < j && nums[k] == nums[k + 1]) {
                        ++k;
                    }
                    // Skip duplicate values for the third number
                    while (k < j && nums[j] == nums[j - 1]) {
                        --j;
                    }
                    
                    // Move past the current duplicates
                    ++k;
                    --j;
                }
            }
        }

        return fin_result;
    }
};
