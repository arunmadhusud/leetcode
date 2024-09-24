class Solution {
public:
    bool isHappy(int n) {
        int slwptr = n;
        int fastptr = n;
        while(fastptr!=1){
            slwptr = sumNum(slwptr);
            fastptr = sumNum(sumNum(fastptr));
            if (fastptr==1) return true;
            if(slwptr==fastptr) return false;
        }
        return true;
        
    }
    int sumNum(int n){
        int sum = 0;
        while(n!=0){
            int digit = n % 10;
            sum += digit*digit;
            n = n / 10;
        }
        return sum;
        
    }
};