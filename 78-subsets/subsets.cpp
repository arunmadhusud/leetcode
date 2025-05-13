class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        recur(0, nums, ans, ds);
        return ans;
    }

    void recur(int index, std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& ds) {        
        if(index==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        recur(index + 1, nums, ans, ds);
        ds.pop_back(); 
        recur(index + 1, nums, ans, ds);
    
    }
};
