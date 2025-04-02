class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> char_set;
        int l = 0;
        int r = 0;
        int max_len = 0;
        int n = s.size();
        while(r < n ){
            while(char_set.find(s[r])!=char_set.end()){
                char_set.erase(s[l]);
                l++;
            }
            if (char_set.find(s[r])==char_set.end()){
                max_len = max(max_len,r-l+1);
                char_set.insert(s[r]);
            }
            r++;
        }
        return max_len;
        
    }
};