class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        r = 0
        max_len = 0
        n = len(s)
        while r < n:
            while s[r] in charSet:
                charSet.remove(s[l])
                l+=1
            charSet.add(s[r])
            r+=1
            max_len = max(len(charSet),max_len)
        
        return max_len

        