class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = 0;
        int window_size = s1.size();
        std::unordered_map<char,int> freq_mp;
        std::unordered_map<char,int> window_freq_mp;
        for (int i = 0; i < s1.size(); i++) freq_mp[s1[i]]++;

        while(r<s2.size()){
            window_freq_mp[s2[r]]++;
            if (r >= window_size) {
                char left_char = s2[l];
                window_freq_mp[left_char]--;
                if (window_freq_mp[left_char] == 0) {
                    window_freq_mp.erase(left_char);
                }
                l++;
            }
            if(window_freq_mp==freq_mp) return true;
            r++;
        }
        return false;
        
    }
};