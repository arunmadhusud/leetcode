class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::unordered_set<int> u_set;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++ ){
            if(prev>=nums.size()-1) return true;
            if(i>prev) return false;
            prev = max(prev,i+nums[i]);
        }
        return true;

        
    }
};