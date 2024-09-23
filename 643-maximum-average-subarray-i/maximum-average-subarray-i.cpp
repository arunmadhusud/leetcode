class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int start = 0;
        for (int i=0; i < k; i++){
            sum +=nums[i];
        }
        double max_sum = sum;
        for (int i=k; i < nums.size();i++){
            sum += nums[i]-nums[start];
            max_sum = max(max_sum,sum);
            start++;
        }
        return max_sum/k;


        
    }
};