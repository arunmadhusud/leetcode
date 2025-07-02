class Solution:
    def searchRow(self, nums:List[int], target:int) -> bool:
        low = 0
        high = len(nums)-1

        while low<=high:
            mid = low + (high-low)//2
            if nums[mid]==target: return True
            elif nums[mid]>target: high = mid-1
            else: low = mid+1
        
        return False

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low = 0
        high = len(matrix)-1
        n = len(matrix[0])-1

        while low <= high:
            mid = low + (high-low)//2
            if matrix[mid][0] <= target and matrix[mid][n] >= target:
                return self.searchRow(matrix[mid], target)
            elif matrix[mid][0] > target: high = mid-1
            else: low = mid +1
        
        return False
        