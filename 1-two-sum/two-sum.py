class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        result = []
        for i in range(len(nums)):
            d = target - nums[i]
            if d in mp:
                return [i,mp[d]]

            else:
                mp[nums[i]] = i
        return result
                
        