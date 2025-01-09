class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<vector<int>> ans;
        std::vector<int> ds;
        std::vector<bool> freq(nums.size(),false);
        recur(ds,nums,ans,freq);
        return ans;
        
    }

    void recur(std::vector<int>& ds,vector<int>& nums,std::vector<vector<int>>& ans,std::vector<bool>& freq ){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i< nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = true;
                recur(ds,nums,ans,freq);
                freq[i] = false; 
                ds.pop_back();               
            }
        }

    }
};