class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        recur(0, nums, ans, ds);
        return ans;
    }

    void recur(int index, std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& ds) {       
   
        ans.push_back(ds);
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            recur(i + 1, nums, ans, ds);
            ds.pop_back();
           }
   
    }
        
};