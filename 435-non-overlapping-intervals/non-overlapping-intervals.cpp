bool comp(const vector<int>&A,const vector<int>&B ){
    return A[1]<B[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int endRange = intervals[0][1];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0]>=endRange){
                endRange = intervals[i][1];
            }
            else count++;
        }
        return count;        
        
    }
};