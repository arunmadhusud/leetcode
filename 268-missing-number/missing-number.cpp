class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res;
        if(n%4==0) res = n;
        if(n%4==1) res = 1;
        if(n%4==2) res = n+1;
        if(n%4==3) res = 0;
        for(int elem : nums) res = res^elem;
        return res;
        
    }
};