class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the overflow case upfront
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;  // Prevent overflow
        }

        bool sign = true;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            sign = false;
        }

        long q = 0;
        long n = abs((long)dividend);
        long d = abs((long)divisor);

        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            q += (1L << count);
            n -= (d << count);
        }

        if (q >= (1L << 31)) {
            return sign ? INT_MAX : INT_MIN;
        }

        return sign ? q : -q;
    }
};
