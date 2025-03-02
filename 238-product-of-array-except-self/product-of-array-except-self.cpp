class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zero_count = 0;
        // vector<int> zero_idx; 

        for(int i = 0; i<nums.size(); i++){
            if (nums[i]!=0) product *= nums[i];
            else zero_count++;
        }

        vector<int> result(nums.size(),0);
        if(zero_count > 1) return result;        
        if(zero_count==1){            
            for(int i = 0; i< nums.size();i++ ){
                if(nums[i]==0) result[i] = product;
            }
            return result;
        }
        for(int i = 0; i< nums.size();i++ ){
            result[i] = product/nums[i];
        }
        return result;
        
    }
};