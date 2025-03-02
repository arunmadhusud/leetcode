class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> zero_idx;        
        for(int i = 0; i<nums.size(); i++){
            if (nums[i]!=0) product *= nums[i];
            else zero_idx.push_back(i);
        }
        if(zero_idx.size() > 1) product = 0;
        vector<int> result(nums.size(),0);
        if(zero_idx.size()>0){            
            for(auto elem : zero_idx) result[elem] = product;
            return result;
        }

        for(int i = 0; i< nums.size();i++ ){
            result[i] = product/nums[i];
        }
        return result;
        
    }
};