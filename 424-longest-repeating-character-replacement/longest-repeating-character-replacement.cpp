class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int max_f  = 0, max_length = 0;
        int length = 0, window_size= 0;
        std::unordered_map<char,int> freq_mp;

        while(r < s.size()){
            freq_mp[s[r]]++;
            max_f = max(max_f,freq_mp[s[r]]);
            window_size = r-l+1;
            while(window_size - max_f > k && l<=r){
                freq_mp[s[l]]--;
                max_f = 0;
                for(const auto& elem : freq_mp) max_f = max(max_f,elem.second);
                l++; 
                window_size = r-l+1;            
            }
            length = r-l+1;
            max_length = max(length,max_length);
            r++;
        }
        return max_length;
        
        
    }
};