class Solution {
public:
    int climbStairs(int n) {
       return fib(n+1);
    }
    int fib(int n) {
        if (n < 2) return n;
        
        vector<int> table(2, 0); // Size of 2 to hold fib(n-2) and fib(n-1)
        table[1] = 1; // base case: fib(1) = 1
        
        // Use a variable to temporarily hold the previous value
        int prev;
        
        for (int i = 2; i <= n; i++) {
            prev = table[1];                  // Store the current fib(n-1)
            table[1] = table[0] + table[1];  // Calculate fib(n)
            table[0] = prev;                  // Update fib(n-2)
        }
        
        return table[1]; // Return the nth Fibonacci number
    }
};