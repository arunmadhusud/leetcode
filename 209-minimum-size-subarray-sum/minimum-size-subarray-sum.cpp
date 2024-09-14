class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0, end = 0;
    int sum = 0;
    int min_length = nums.size()+1;  // Initialize to something larger than the array size
    int n1 = nums.size();
    while (end < n1)
    {
        // Expand the window by adding elements to the sum
        while (sum < target && end < n1)
        {
            sum += nums[end]; 
            end++;
        }

        // Shrink the window to find the smallest subarray with sum > x
        while (sum >= target && start < end)
        {   
            int length = end - start;
            min_length = std::min(min_length, length);

            sum -= nums[start];
            start++;
        }
    }

    // Return the minimum length found, or 0 if no valid subarray is found
    return (min_length == n1+1) ? 0 : min_length;
    }
};