class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int N = nums.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            // if (nums[low] <= nums[high]) return nums[low];
            // Find previous and next indices using modulo to handle boundaries
            int prev = (mid + N - 1) % N;
            int next = (mid + 1) % N;
            
            // Check if the mid element is the smallest
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                return nums[mid];
            }
            if (nums[mid] <= nums[high]) high = mid - 1;
            else low = mid +1;
        }
        return nums[low];
        
    }
};