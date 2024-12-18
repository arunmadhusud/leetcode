class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> substring;
        int start = 0;
        int maxLength = 0;
        for (char elem : s){
            while(substring.find(elem)!=substring.end())
            {
                substring.erase(s[start]);
                start++;
            }
            substring.insert(elem);
            maxLength = max(maxLength,(int)substring.size());
        }
        return maxLength;        
    }
};