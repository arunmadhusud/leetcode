class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize result array with -1
        stack<int> elem_stack;  // Monotonic decreasing stack to store indices
        
        // Traverse the array twice to simulate the circular behavior
        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];  // Circular array, use modulo to wrap around
            
            // If the current element is greater than the element at the index stored at the top of the stack
            while (!elem_stack.empty() && nums[elem_stack.top()] < num) {
                result[elem_stack.top()] = num;  // Update the result for the index at the top
                elem_stack.pop();
            }
            
            // Only push indices in the first pass (first n elements)
            if (i < n) {
                elem_stack.push(i);
            }
        }
        
        return result;  // Return the result array
    }
};
