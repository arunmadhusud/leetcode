class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> str_cpy = strs;
        vector<vector<string>> output;
        map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string sorted_str = str_cpy[i];
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(strs[i]);
        }

        for (auto& elem : mp) {
            output.push_back(elem.second);
        }

        return output;
    }
};