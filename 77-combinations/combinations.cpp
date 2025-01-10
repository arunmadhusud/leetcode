class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> ds;
        recur(0,n,k,results,ds);
        return results;        
    }

    void recur(int idx, int& n, int& k,vector<vector<int>>& results,vector<int>& ds){
        if (ds.size()==k){
            results.push_back(ds);
            return;
        }
        for (int i = idx; i < n; i++){
            ds.push_back(i+1);
            recur(i+1,n,k,results,ds);
            ds.pop_back();
        }
    }
};