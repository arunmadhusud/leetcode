class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int N = nums.size();
        int min_elem;
        int min_idx;
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
                min_idx = low;
                break;
            }
            if (nums[mid] <= nums[high]) high = mid - 1;
            else low = mid +1;
        }
        return min_elem;
        
    }
};