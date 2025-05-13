class Solution {
public:
    void findCombination(int idx, int target, vector<int>& num, vector<vector<int>>& ans, vector<int>&ds){
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        for(int i = idx; i < num.size(); i++){
            if(i > idx && num[i]==num[i-1]) continue;
            if (num[i]> target) break;
            ds.push_back(num[i]);
            findCombination(i+1,target-num[i],num,ans,ds);
            ds.pop_back();

        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;        
    }
};