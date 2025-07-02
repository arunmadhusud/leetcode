class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        min_elem = float('inf')

        while low<=high:
            mid = low + (high-low)//2
            if nums[mid] >= nums[low]: # left side is sorted
                min_elem = min(min_elem,nums[low])
                low = mid+1
            elif nums[mid] < nums[high]:
                min_elem = min(min_elem,nums[mid])
                high = mid-1
            
        return min_elem

        