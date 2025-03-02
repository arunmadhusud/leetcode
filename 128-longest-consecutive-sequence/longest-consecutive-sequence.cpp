class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::priority_queue<int,vector<int>, std::greater<int>> pq;
        for(int i = 0; i< nums.size(); i++) pq.push(nums[i]);
        int count = 0;
        int max_count = 0;
        int prev,curr;
        if(pq.size() > 0)
        {
            prev = pq.top();
            pq.pop();
            count = 1;
            max_count = 1;
        }
        while(!pq.empty()){
            curr = pq.top();
            if ((curr-prev) > 1) count = 1;
            else if(curr!=prev) count++;
            prev = curr;
            pq.pop();
            max_count = max(count,max_count);            
        }

        return max_count;
        
    }
};