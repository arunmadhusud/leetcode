class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int first_occ = firstOccur(nums, target);
        int last_occ = lastOccur(nums, target);
        result.push_back(first_occ);
        result.push_back(last_occ);
        return result;
        
    }
    int lastOccur(vector<int>& a, int target)
    {
        int start = 0;
        int end = a.size()-1;
        int result = -1;
        while (start <= end)
        {
            int mid = start + (end-start)/2;
            if (a[mid] < target) start = mid + 1;
            if (a[mid] > target) end = mid - 1;
            if (a[mid]==target)
            {
                result = mid;
                start = mid + 1;
            }
        }
        return result;
    }
    int firstOccur(vector<int>& a, int target)
    {
        int start = 0;
        int end = a.size()-1;
        int result = -1;
        while (start <= end)
        {
            int mid = start + (end-start)/2;
            if (a[mid] < target) start = mid + 1;
            if (a[mid] > target) end = mid - 1;
            if (a[mid]==target)
            {
                result = mid;
                end = mid - 1;
            }
        }
        return result;
    }
};