class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;
        for(int elem: stones) pq.push(elem);
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int diff = a-b;
            if(diff!=0) pq.push(diff);
        }
        if(!pq.empty()) return pq.top();
        return 0;
        
    }
};