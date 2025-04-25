// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> sums(nums.size(),nums[0]);
//         int max_idx = 0;
//         int min_idx = 0;
//         int max_sum = sums[0];
//         int min_sum = INT_MAX;

//         for (int i = 1; i < nums.size(); i++){
//             sums[i] = sums[i-1] + nums[i];
//             if(sums[i]>max_sum) {
//                 max_idx = i;
//                 max_sum = sums[i];
//             }
//         }

//         for (int j = 0; j <= max_idx ; j++){
//             if(sums[j] < min_sum){
//                 min_idx = j;
//                 min_sum = sums[j];
//             }
//         }
        
//         int sum = 0;
//         int start_idx = min_idx;
//         std::cout << min_idx << max_sum;
//         if  (nums[min_idx] <= 0 && nums.size()!=1) start_idx =  min_idx+1;
//         for (int k = start_idx; k <= max_idx; k++) sum = sum + nums[k];

//         return sum;
//     }
// };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr_sum = max(nums[i], curr_sum+nums[i]);
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;

    }
};
