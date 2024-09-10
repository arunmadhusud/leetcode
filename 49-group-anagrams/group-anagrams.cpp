class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::map<std::string, std::vector<std::string>> anagram_map;
        std::vector<std::vector<std::string>> result;

        // Group words by their sorted form
        for (int i = 0; i < strs.size(); ++i) {
            std::string str_copy = strs[i];
            std::sort(str_copy.begin(), str_copy.end()); // Sort the string to use as a key
            anagram_map[str_copy].push_back(strs[i]);
        }

        // Collect groups of anagrams
        for (const auto& entry : anagram_map) {
            result.push_back(entry.second); // Add the vector of anagrams to the result
        }

        return result;
    }
};