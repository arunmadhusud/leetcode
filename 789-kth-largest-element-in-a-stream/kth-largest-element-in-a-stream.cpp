class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int pq_size;
    KthLargest(int k, vector<int>& nums) {
        pq_size = k;
        for (int elem : nums){
            if(pq.size()<pq_size) pq.push(elem);
            else{
                if(pq.top()<elem){
                    pq.pop();
                    pq.push(elem);
                }
            }
        }   
        
    }
    
    int add(int val) {
        if(pq.size()<pq_size) pq.push(val);
        else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */