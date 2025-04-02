class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int  l = 0;
        int  r = 1;
        int max_profit = 0;
        int n = prices.size();

        while(r < n){
            while(prices[r]<prices[l]){
                l++;                
            }
            if(prices[r]>prices[l]){
                max_profit = max(max_profit,prices[r]-prices[l]);
            }
            r++;
        }

        return max_profit;
        
    }
};