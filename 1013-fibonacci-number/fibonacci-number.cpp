// class Solution {
// public:
//     int fib(int n) {
//         vector<int> mem(n+1,0);
//         return fibHelper(n, mem);
//     }

//     int fibHelper(int n, vector<int>& mem){
//         if(mem[n]!=0) return mem[n];
//         if (n<2) return n;
//         int result = fibHelper(n-1,mem) + fibHelper(n-2,mem);
//         mem[n] = result;
//         return result;
        
//     }
// };

class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        vector<int> table(2,0);
        table[1] = 1;
        int prev;
        for(int i = 2; i <=n; i++){
            prev = table[1];
            table[1] = table[0]+table[1];
            table[0] = prev;
        }
        return table[1];        
    }
};