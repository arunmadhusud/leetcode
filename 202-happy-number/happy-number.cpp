class Solution {
public:
    bool isHappy(int n) {
        int slwptr = n;
        int fstptr = n;
        while(fstptr!=1){
            slwptr = sumNum(slwptr);
            fstptr = sumNum(sumNum(fstptr));
            if(fstptr==1) return true;
            if(fstptr==slwptr) return false;
        }
        return true;        
    }
    int sumNum(int num){
        int sum = 0;
        while(num!=0){
            int digit = num % 10;
            sum += digit * digit;
            num = num /10;
        }
        return sum;
    }
};