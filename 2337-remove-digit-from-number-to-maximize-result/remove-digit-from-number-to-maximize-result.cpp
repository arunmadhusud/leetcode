class Solution {
public:
    string removeDigit(string number, char digit) {
        std::vector<string> poss;
        string tmp = "";
        string max_s = "";
        int length = number.size();
        for(int i = 0; i < number.size(); i++){
            if (number[i] == digit){
                tmp += number.substr(0,i) + number.substr(i+1);
                if(tmp > max_s) max_s = tmp;
                tmp = "";
            }
        }

        return max_s;

        
    }
};