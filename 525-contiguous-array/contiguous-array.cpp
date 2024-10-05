class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;  // Initialize sum to 0
        map<int, int> sum_idx;
        sum_idx[0] = -1;  // Handle case when the entire subarray from start has equal 0's and 1's
        
        int max_l = 0;  // Variable to store maximum length
        
        for (int i = 0; i < nums.size(); i++) {
            // Increment sum for 1, decrement for 0
            if (nums[i] == 0) {
                sum--;
            } else {
                sum++;
            }
            
            // If the current sum has been seen before, calculate the length of the subarray
            if (sum_idx.find(sum) != sum_idx.end()) {
                max_l = max(max_l, i - sum_idx[sum]);
            } else {
                // Store the first occurrence of the sum
                sum_idx[sum] = i;
            }
        }
        
        return max_l;
    }
};
