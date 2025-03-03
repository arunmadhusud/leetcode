class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        vector<int> result;

        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum == target) {
                result.push_back(i+1);
                result.push_back(j+1);
                break;
            }

            if (sum > target) j--;
            if (sum < target) i++;
        }

        return result;

        
    }
};