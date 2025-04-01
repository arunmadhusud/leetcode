class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mon_st;
        unordered_map<int, int> nge_map;
        vector<int> res(nums1.size(),-1);

        for(int i = nums2.size()-1 ; i >=0 ; i--){
            while (!mon_st.empty() && nums2[mon_st.top()] <= nums2[i]){
                mon_st.pop();
            }
            nge_map[nums2[i]] = mon_st.empty() ? -1 : nums2[mon_st.top()];
            mon_st.push(i);
        }
        for (int i = 0; i < nums1.size() ; i++)
        {
            res[i] = nge_map[nums1[i]];
        }

        return res;
        
    }
};