class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        std::unordered_map<int,int> count;
        count[5] = 0;
        count[10] = 0;
        count[20] = 0;
        for (int i = 0; i < bills.size(); i++){
            if(bills[i]==5) count[5]++;
            if(bills[i]==10){
                if(!count[5]) return false;
                else{
                    count[10]++;
                    count[5]--;
                }
            }
            if(bills[i]==20){
                if(count[10] && count[5]){
                    count[10]--;
                    count[5]--;
                    count[20]++;
                }
                else if(count[5]>2){
                    int i = 0;
                    while(i<3){
                        count[5]--;
                        i++;
                    }
                    count[20]++;
                }
                else return false;
            }
        }

        return true;

        
    }
};