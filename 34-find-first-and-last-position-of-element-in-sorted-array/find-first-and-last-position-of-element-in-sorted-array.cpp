class Solution {
public:
    int findOccur(vector<int>& nums, int target, bool firstOccur){
        int low = 0;
        int high = nums.size() - 1;
        int result = -1;
        while (low <= high){
            int mid  = low + (high - low)/2;
            if (nums[mid] == target) {
                result = mid;
                if (firstOccur) high = mid -1;
                else low = mid + 1;

            }
            else if (nums[mid] > target) high = mid - 1;
            else low = mid+1;
        }

        return  result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int firstIdx = findOccur(nums, target, true);
        int lastIdx = findOccur(nums, target, false);
        result.push_back(firstIdx);
        result.push_back(lastIdx);
        return result;        
    }
        
};