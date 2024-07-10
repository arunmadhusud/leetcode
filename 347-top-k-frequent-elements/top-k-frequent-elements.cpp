class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        multimap<int, int, greater<int>> mp_r;
        vector<int> output;

        // Count frequencies
        for (int elem : nums) {
            mp[elem]++;
        }

        // Reverse map to sort by frequency
        for (const auto& elem : mp) {
            mp_r.insert({elem.second, elem.first});
        }

        // Collect the top k frequent elements
        auto it = mp_r.begin();
        for (int i = 0; i < k && it != mp_r.end(); ++i, ++it) {
            output.push_back(it->second);
        }

        return output;
    }
};