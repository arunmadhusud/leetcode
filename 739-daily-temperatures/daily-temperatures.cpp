class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mon_st;
        vector<int> res(temperatures.size(),-1);
        
        int n = temperatures.size();
        for(int i = n-1 ; i >=0 ; i--){
            while (!mon_st.empty() && temperatures[mon_st.top()] <= temperatures[i]){
                mon_st.pop();
            }
            res[i] = mon_st.empty() ? 0 : mon_st.top() - i;
            mon_st.push(i);
        }

        return res;      
        
    }
};