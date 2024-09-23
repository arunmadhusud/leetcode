class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> subString;
        int start = 0;
        int maxLength = 0;
        for (char elem : s){
            if(subString.find(elem) == subString.end())
            {
                subString.insert(elem);
            }
            else
            {
                while(subString.find(elem) != subString.end()){
                    subString.erase(s[start]);
                    start++;
                }
                subString.insert(elem);
            }
            maxLength = max(maxLength,(int)subString.size());
        }
        return maxLength;



        
    }
};