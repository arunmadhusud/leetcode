class NumArray {
public:
    vector<int> sum_array;
    NumArray(vector<int>& nums) {
        sum_array = nums;
        for (int i = 1; i < sum_array.size(); i++){
            sum_array[i] += sum_array[i-1];
        }        
    }
    
    int sumRange(int left, int right) {
        if (left==0) return (sum_array[right]);
        return (sum_array[right] - sum_array[left-1]);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */