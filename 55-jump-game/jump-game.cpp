class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::unordered_set<int> u_set;
        int max_jump = nums[0];
        for(int i = 1; i < nums.size(); i++ ){
            if(max_jump>=nums.size()-1) return true;
            if(i>max_jump) return false;
            max_jump = max(max_jump,i+nums[i]);
        }
        return true;

        
    }
};