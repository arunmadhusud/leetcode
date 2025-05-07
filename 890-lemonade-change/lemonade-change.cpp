class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0;
        int count_10 = 0;
        int count_20 = 0;
        for (int i = 0; i < bills.size(); i++){
            if(bills[i]==5) count_5++;
            if(bills[i]==10){
                if(!count_5) return false;
                else{
                    count_10++;
                    count_5--;
                }
            }
            if(bills[i]==20){
                if(count_10 && count_5){
                    count_10--;
                    count_5--;
                    count_20++;
                }
                else if(count_5>2){
                    int i = 0;
                    while(i<3){
                        count_5--;
                        i++;
                    }
                    count_20++;
                }
                else return false;
            }
        }

        return true;

        
    }
};