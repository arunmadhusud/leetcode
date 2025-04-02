class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int l = 0;
        int r = 0;
        for(r = 0; r < k ; r++){
            sum = sum + nums[r];
        }
        double max_sum = sum;
        int  n = nums.size();
        while (r < n){
            sum = sum - nums[l];
            l++;
            sum = sum + nums[r];
            max_sum = max(max_sum,sum);
            r++;            
        }
        return max_sum/k;



    }
};