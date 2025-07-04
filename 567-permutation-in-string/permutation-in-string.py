class Solution:
    # O(n*mlogm)solution
    # def checkInclusion(self, s1: str, s2: str) -> bool:
    #     s1_sorted = sorted(s1)
    #     for i in range(len(s2)-len(s1)+1):
    #         if sorted(s2[i:i+len(s1)])== s1_sorted:
    #             return True
    #     return False

    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_freq = Counter(s1)
        left, right = 0, 0
        window_freq = {}
        
        while(right<len(s2)):
            window_freq[s2[right]] = window_freq.get(s2[right],0)+1
            window_size = right-left+1            
            if window_size > len(s1):
                window_freq[s2[left]]-=1
                if window_freq[s2[left]]==0: window_freq.pop(s2[left])
                left+=1
            if window_freq==s1_freq: return True
            right+=1
        
        return False

                

        