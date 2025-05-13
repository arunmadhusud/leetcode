class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        recur(0, nums, ans, ds);
        return ans;
    }

    void recur(int index, std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& ds) {
        // Add the current subset to the result
        ans.push_back(ds);

        // Generate all subsets starting from the current index
        for (int i = index; i < nums.size(); i++) {
            ds.push_back(nums[i]);         // Include nums[i] in the current subset
            recur(i + 1, nums, ans, ds);  // Recurse to the next elements
            ds.pop_back();                // Backtrack and remove nums[i]
        }
    }
};
