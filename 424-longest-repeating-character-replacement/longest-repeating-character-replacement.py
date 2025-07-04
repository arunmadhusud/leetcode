class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        left, max_freq, max_length = 0, 0, 0

        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right],0)+1
            max_freq = max(max_freq,freq[s[right]])

            window_size = right - left + 1

            while window_size - max_freq > k and left <= right:
                freq[s[left]] -=1
                left +=1
                window_size = right - left + 1
                max_freq = max(freq.values()) if freq else 0

            
            max_length = max(max_length,right - left + 1)
        
        return max_length





            


        