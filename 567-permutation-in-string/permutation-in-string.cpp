class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = s1.size()-1;
        std::unordered_map<char,int> freq_mp;
        std::unordered_map<char,int> window_freq_mp;
        for (int i = 0; i < s1.size(); i++) freq_mp[s1[i]]++;

        while(r<s2.size()){
            for (int i = l; i <= r; i++) window_freq_mp[s2[i]]++;
            if(window_freq_mp==freq_mp) return true;
            window_freq_mp = {};
            l++;
            r++;
        }
        return false;
        
    }
};