class Solution {
public:
    int fib(int n) {
        vector<int> mem(n+1,0);
        return fibHelper(n, mem);
    }

    int fibHelper(int n, vector<int>& mem){
        if(mem[n]!=0) return mem[n];
        if (n<2) return n;
        int result = fibHelper(n-1,mem) + fibHelper(n-2,mem);
        mem[n] = result;
        return result;
        
    }
};