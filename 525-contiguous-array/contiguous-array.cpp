class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::map<int,int> sum_idx;
        // To handle the case where the array contains equal number of zeros and 1s
        sum_idx[0] = -1;
        int sum = 0;
        int max_l = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]==0) sum--;
            else sum++;
            if(sum_idx.find(sum)!=sum_idx.end())
            {
                max_l = max(max_l,i-sum_idx[sum]);
            }
            else sum_idx[sum] = i;
        }
        return max_l;
    }
};