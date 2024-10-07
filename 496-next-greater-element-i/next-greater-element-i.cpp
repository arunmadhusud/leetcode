class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(nums1.size(),-1);
    stack<int> elem_stack;
    unordered_map<int,int> greatMP;
    for(int elem: nums2){
        while(!elem_stack.empty() && elem_stack.top() < elem){
            greatMP[elem_stack.top()] = elem;
            elem_stack.pop();
        }
        elem_stack.push(elem);
    }

    for (int i = 0; i < nums1.size(); i++){
        if(greatMP.find(nums1[i])!= greatMP.end()) result[i] = greatMP[nums1[i]];
    }
    return result;

  }
};