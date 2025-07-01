class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)

        for s in strs:
            freq = [0] * 26
            for c in s:
                freq[ord(c)-ord('a')] +=1
                
            key = ""
            for f in freq:
                key += str(f) +'#'
            
            mp[key].append(s)

           
        return list(mp.values())
        