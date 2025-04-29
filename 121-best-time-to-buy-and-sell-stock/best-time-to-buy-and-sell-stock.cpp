class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  l = 0;
        int  r = 1;
        int max_profit = 0;
        int n = prices.size();

        while(r < n){
            if (prices[r] < prices[l]) {
                l = r; 
            } else {
                max_profit = max(max_profit, prices[r] - prices[l]);
            }
            r++;
        }

        return max_profit;
        
    }
};