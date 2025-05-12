class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;
        if((dividend < 0 && divisor>0) || (dividend > 0 && divisor<0)) sign = false;
        long q = 0;
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        while (n>=d){
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            q += (1<<count);
            n -= (d<<count);
        }
        if(q==(1<<31) && sign ) return INT_MAX;
        if(q==(1<<31) && !sign) return INT_MIN;
        return sign? q : -q;
        
    }
};