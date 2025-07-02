class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums)-2):
            j = i+1
            k = len(nums) -1
            if i>0 and nums[i]==nums[i-1]: continue
            while j < k:
                sumV = nums[i] + nums[j] + nums[k]
                if sumV==0:
                    result.append([nums[i],nums[j],nums[k]])
                    while j<k and nums[j]==nums[j+1]: j+=1
                    while j<k and nums[k]==nums[k-1]: k-=1
                    j+=1
                    k-=1
                elif sumV > 0: k-=1
                else: j+=1
        
        return result


        