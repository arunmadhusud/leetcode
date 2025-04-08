class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // std::unordered_set<char> char_st;
        // for (int i = 0; i < s1.size(); i++) char_st.insert(s1[i]);
        // std::unordered_map<char,int> freq_mp;
        // for (int i = 0; i < s1.size(); i++) freq_mp[s1[i]]++;
        int l = 0;
        int r = s1.size()-1;
        while(r<s2.size()){
            int count = 0;
            std::unordered_map<char,int> freq_mp;
            for (int i = 0; i < s1.size(); i++) freq_mp[s1[i]]++;
            for (int i = l; i <= r; i++){
                if(freq_mp.find(s2[i])!=freq_mp.end()) freq_mp[s2[i]]--;
            }
            for(const auto elem : freq_mp){
                if (elem.second!=0) count++;
            }
            if (count == 0) return true;
            l++;
            r++;
        }
        return false;
        
    }
};