class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> mon_st;
        vector<int> res(nums.size(),-1);
        
        int n = nums.size();
        for(int idx = 2*n-1 ; idx >=0 ; idx--){
            int i = idx % n;
            while (!mon_st.empty() && mon_st.top() <= nums[i]){
                mon_st.pop();
            }
            if(idx < n) res[i] = mon_st.empty() ? -1 : mon_st.top();
            mon_st.push(nums[i]);
        }

        return res;
        
    }
};