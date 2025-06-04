class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        int n = nums.size()-1;
        for(int i = 0 ; i <= n; i++){            
            if(i > max_jump) return false;
            max_jump = max(max_jump, nums[i]+i);
            if(max_jump >= n) return true;
        }
        return false;        
    }
};
