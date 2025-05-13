class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        std::vector<bool> flag(nums.size(),false);
        recur(nums,ans,ds,flag);
        return ans;
        
    }
    void recur(std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& ds,std::vector<bool>& flag) {      
  
        if(ds.size()==nums.size()) ans.push_back(ds);
        for(int i = 0; i < nums.size(); i++){
            if(flag[i]) continue;
            ds.push_back(nums[i]);
            flag[i] = true;
            recur(nums, ans, ds,flag);
            ds.pop_back();
            flag[i] = false;
           }
   
    }
};