class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int N = nums.size();
        int min_elem;
        int min_idx;
        int result = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if (nums[low] <= nums[high])
            {
                min_elem = nums[low];
                min_idx = low;
                break;
            }
            int prev = (mid + N - 1) % N;
            int next = (mid + 1) % N;
            
            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])            
            {
                min_elem = nums[mid];
                min_idx = mid;
                break;
            }
            if (nums[mid] <= nums[high]) high = mid - 1;
            else low = mid +1;
        }
        
        // Determine which part of the array to search
        if (target >= nums[min_idx] && target <= nums[N - 1]) {
            low = min_idx;
            high = N - 1;
        } else {
            low = 0;
            high = min_idx - 1;
        }

        // Perform binary search on the chosen part
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;


        
    }
};