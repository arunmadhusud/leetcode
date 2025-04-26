class Solution {
public:
    string removeDigit(string number, char digit) {
        int idx = -1;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                idx = i;
                if (i+1 < number.size() && number[i+1] > digit) {
                    break; // better to remove earlier if next digit is bigger
                }
            }
        }
        // remove the digit at idx
        return number.substr(0, idx) + number.substr(idx+1);
    }
};
