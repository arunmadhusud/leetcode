class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 1; i<=n; i++) res = res^i;
        for(int elem : nums) res = res^elem;
        return res;
        
    }
};