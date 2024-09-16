class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long max_sum = 0;
        int n = nums.size();
        if (k > n) return 0;  // Return 0 if k is greater than the array size

        unordered_map<int, int> num_count;  // Changed to map for efficient count tracking
        long long current_sum = 0;
        int start = 0, end = 0;

        // Find the first valid subarray with exactly k distinct elements
        while (end < n) {   
            current_sum += nums[end];
            num_count[nums[end]]++;

            if (end - start + 1 > k) {
                current_sum -= nums[start];
                if (--num_count[nums[start]] == 0) {
                    num_count.erase(nums[start]);
                }
                start++;
            }

            if (end - start + 1 == k && num_count.size() == k) {
                max_sum = max(max_sum, current_sum);
            }

            end++;
        }

        return max_sum;
    }
};