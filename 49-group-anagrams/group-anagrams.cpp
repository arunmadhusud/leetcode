class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // std::unordered_map<std::string,vector<string>> mp;
        // vector<vector<string>> result;
        // for(int i =0; i < strs.size(); i++){
        //     std::string str_cp(strs[i]);
        //     std::sort(str_cp.begin(),str_cp.end());
        //     mp[str_cp].push_back(strs[i]);
        // }
        // for (auto it = mp.begin(); it!=mp.end(); it++){
        //     result.push_back(it->second);
        // }

        // return result;
        
        std::unordered_map<std::string,vector<string>> mp;
        vector<vector<string>> result;

        for (string s : strs){
            vector<int> freq(26,0);
            for (char c : s)freq[c-'a']++;
            string key="";
            for (int k : freq) key+= to_string(k) + '#';
            mp[key].push_back(s);
        }

        for(auto elem : mp) result.push_back(elem.second);
        return result;
        

        
    }
};