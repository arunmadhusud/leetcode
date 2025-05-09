class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }

        vector<int> result;
        int i = 0;
        int start = 0;
        int end = 0;
        while (i < s.size()) {
            end = max(end,last[s[i]]);
            if (i==end){
                result.push_back(end-start+1);
                start = i+1;
            }
            i++;
        }

        return result;
    }
};
