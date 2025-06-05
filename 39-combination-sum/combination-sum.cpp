class Solution {
public:
    
    void findCombination(int idx, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>&ds){
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if(nums[i] > target) continue;
            ds.push_back(nums[i]);        
            findCombination(i, target - nums[i],nums, ans, ds);  
            ds.pop_back(); 
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;        
    }
};