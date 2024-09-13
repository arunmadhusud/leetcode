class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if (nums[low] <= nums[high]) return nums[low];
            if (nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) return nums[mid];
            if (nums[mid] <= nums[high]) high = mid - 1;
            else low = mid +1;
        }
        return nums[low];
        
    }
};