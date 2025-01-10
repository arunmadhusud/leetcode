class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<vector<int>> ans;
        std::vector<int> ds;
        std::vector<bool> freq(nums.size(), false);  // To track used elements
        recur(0, nums, ds, ans, freq);
        return ans;
    }

    void recur(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            // return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {  // Only proceed if the element has not been used
                freq[i] = true;   // Mark as used
                ds.push_back(nums[i]);  // Include the element

                recur(index + 1, nums, ds, ans, freq);  // Recur for the next element

                // Backtrack by undoing the previous choice
                ds.pop_back();
                freq[i] = false;  // Mark as unused
            }
        }
    }
};
