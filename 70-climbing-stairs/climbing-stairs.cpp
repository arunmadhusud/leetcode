class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;  // There is one way to climb 0 or 1 step

        vector<int> table(2, 0); // Size of 2 to hold steps for last and second last step
        table[0] = 1; // Ways to climb 0 steps
        table[1] = 1; // Ways to climb 1 step
        
        // Use a variable to temporarily hold the previous value
        int prev;
        
        // Start the loop from 2 to n (inclusive)
        for (int i = 2; i <= n; i++) {
            prev = table[1];                 // Store the second last step
            table[1] = table[0] + table[1];  // Calculate current steps
            table[0] = prev;                  // Update second last step
        }
        
        return table[1];  // Return the total ways to climb n steps
    }
};
