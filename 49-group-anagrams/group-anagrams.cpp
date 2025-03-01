class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string,vector<string>> mp;
        vector<vector<string>> result;
        for(int i =0; i < strs.size(); i++){
            std::string str_cp(strs[i]);
            std::sort(str_cp.begin(),str_cp.end());
            mp[str_cp].push_back(strs[i]);
        }

        for(auto elem:mp){
            result.push_back(elem.second);
        }

        return result;
        
    }
};