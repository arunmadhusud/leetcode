class Solution {
public:
    
    void findCombination(int idx, int target, vector<int>& num, vector<vector<int>>& ans, vector<int>&ds){
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        if(idx<0) return;
        if(num[idx]<=target){
            ds.push_back(num[idx]);
            findCombination(idx,target-num[idx],num,ans,ds);
            ds.pop_back();
        }
        findCombination(idx-1,target,num,ans,ds);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size()-1;
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(n,target,candidates,ans,ds);
        return ans;        
    }
};