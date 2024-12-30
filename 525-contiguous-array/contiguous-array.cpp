class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int,int> sum_idx;
        int sum = 0;
        sum_idx[sum] = -1;
        int max_length = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]==0) sum--;
            else sum++;
            if(sum_idx.find(sum)!=sum_idx.end())
            {
                max_length = std::max(max_length, i - sum_idx[sum]);
            }
            else sum_idx[sum] = i;
        }
        return max_length;

    }
};