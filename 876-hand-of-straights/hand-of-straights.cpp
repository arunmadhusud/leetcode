class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n < groupSize || n % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        sort(hand.begin(), hand.end()); 

        for (int i = 0; i < n; i++) {
            if (count[hand[i]] == 0) continue; 

            int curr = hand[i];
            int num = 0;
            while (num < groupSize && count[curr] > 0) {
                count[curr]--;
                num++;
                curr++;
            }
            if (num != groupSize) return false; 
        }

        return true;
    }
};
