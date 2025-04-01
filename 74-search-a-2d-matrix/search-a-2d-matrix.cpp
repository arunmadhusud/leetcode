class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high){
            int mid  = low + (high - low)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] > target) high = mid - 1;
            else low = mid+1;
        }

        return  false;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int n = matrix[0].size()-1;
        while (low <= high){
            int mid  = low + (high - low)/2;
            if (matrix[mid][0] <= target && matrix[mid][n]>=target) return search(matrix[mid],target);
            if (matrix[mid][0] > target) high = mid - 1;
            else low = mid+1;
        }

        return  false;
        
    }
};