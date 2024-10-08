class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(),-1);
        stack<int> stIdx;
        unordered_map<int,int> grtMP;
        
        for(int i = 0; i < nums2.size(); i++){
            while(!stIdx.empty() && nums2[stIdx.top()] < nums2[i]){
                grtMP[nums2[stIdx.top()]] = nums2[i];
                stIdx.pop();
            }
            stIdx.push(i);
        }

        for(int i = 0; i < nums1.size(); i++){
            if(grtMP.find(nums1[i])!=grtMP.end()) result[i] = grtMP[nums1[i]];
        }
        return result;
        
    }
};