class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> result;
        while (i<j)
        {
            if ((numbers[i] + numbers[j]) > target)
            {
                j--;
            }
            else if ((numbers[i] + numbers[j]) < target)
            {
                i++;
            }
            else {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
        }
        return result;
        
    }
};