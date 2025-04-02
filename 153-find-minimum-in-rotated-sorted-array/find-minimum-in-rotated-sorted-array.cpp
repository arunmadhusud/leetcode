class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int min_elem = INT_MAX;

        while (low <= high){
            int mid  = low + (high - low)/2;
            if (nums[mid] >= nums[low]){
                min_elem = min(min_elem,nums[low]);
                low = mid + 1;
            }
            if (nums[mid] < nums[high]) {
                min_elem = min(min_elem,nums[mid]);
                high = mid-1;
            }
        }

        return  min_elem;
        
    }
};