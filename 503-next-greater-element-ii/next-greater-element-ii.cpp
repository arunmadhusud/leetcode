class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(),-1);
        stack<int> stIdx;
        int n = nums.size();

        for(int i = 0; i <  2 * n; i++){
            int num = nums[i % n];
            while(!stIdx.empty() && nums[stIdx.top()]<num){
                result[stIdx.top()] = num;
                stIdx.pop();
            }
            if(i<n) stIdx.push(i);
        }

        return result;
        
    }
};