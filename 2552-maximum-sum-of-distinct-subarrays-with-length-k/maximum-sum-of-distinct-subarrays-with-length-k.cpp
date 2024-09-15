class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long max_sum = 0;  // To store the maximum sum
        long long current_sum = 0;  // To store the current window sum
        int n = nums.size();
        
        if (k > n) return 0;  // If k is greater than the array size, return 0

        unordered_set<int> dup_check;  // Set to check for duplicates
        int start = 0;

        for (int end = 0; end < n; ++end) {
            // If the element is already in the set, slide the window from the left until it's not
            while (dup_check.find(nums[end]) != dup_check.end()) {
                dup_check.erase(nums[start]);  // Remove the leftmost element from the set
                current_sum -= nums[start];  // Subtract its value from the sum
                start++;
            }

            // Add the new element to the set and sum
            dup_check.insert(nums[end]);
            current_sum += nums[end];

            // If the window size equals k, update max_sum and slide the window
            if (end - start + 1 == k) {
                max_sum = std::max(max_sum, current_sum);
                
                // Slide the window: remove the start element from set and sum
                dup_check.erase(nums[start]);
                current_sum -= nums[start];
                start++;
            }
        }

        return max_sum;
    }
};
