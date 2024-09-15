class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long max_sum = 0;
        int n = nums.size();
        if (k > n) return 0;  // Return 0 if k is greater than array size

        unordered_set<int> dup_check;
        long long current_sum = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            // If current element is a duplicate, adjust the window
            while (dup_check.find(nums[end]) != dup_check.end()) {
                dup_check.erase(nums[start]);
                current_sum -= nums[start];
                start++;
            }

            // Add the current element
            dup_check.insert(nums[end]);
            current_sum += nums[end];

            // Check if we have a window of size k with all distinct elements
            if (end - start + 1 == k) {
                max_sum = max(max_sum, current_sum);
                // Prepare to slide the window
                dup_check.erase(nums[start]);
                current_sum -= nums[start];
                start++;
            }
        }

        return max_sum;
    }
};
