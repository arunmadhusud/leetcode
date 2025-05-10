bool comp(const vector<int>&A,const vector<int>&B ){
    return A[0]<B[0];
}

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> result;
        if(intervals.size()<=1) return intervals;        
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){                        
            if(intervals[i][0] > end){
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];                
            }
            else end = max(end,intervals[i][1]);        
        }
        result.push_back({start,end});
        return result;         
    }
};