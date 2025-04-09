// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int low = 0;
//         int high = intervals.size()-1;
//         int mid;
//         vector<vector<int>> result;
//         if (intervals.size()==0) {
//             result.push_back(newInterval);
//             return result;
//         }
//         while (low <=high){
//             mid = low  + (high-low)/2;
//             if (intervals[mid][0] > newInterval[0]) high = mid -1;
//             else if (intervals[mid][1] < newInterval[0]) low = mid + 1;
//             else break;
//         }
//         int merge_idx;
//         int merge_val;
//         for (int i = mid; i < intervals.size(); i++){

//             if (i == mid && intervals[i][1]>=newInterval[1]){
//                 merge_idx = i;
//                 merge_val = intervals[i][1];
//                 break;
//             }
//             // else if (intervals[i][1] < newInterval[1] && intervals[i+1][0] > newInterval[1]){
//             //     merge_idx = i;
//             //     merge_val = newInterval[1];
//             //     break;
//             // }
//             else if (intervals[i][1] > newInterval[1]){
//                 merge_idx = i;
//                 merge_val = intervals[i][1] ;
//                 break;
//             }
//             else if (intervals[i][0] >= newInterval[1]){
//                 merge_idx = i-1;
//                 merge_val = newInterval[1] ;
//                 break;
//             }
//         }

//         for  (int i = 0; i<mid; i++) result.push_back(intervals[i]);
//         vector<int> tmp;
//         tmp.push_back(intervals[mid][0]);
//         tmp.push_back(merge_val);
//         result.push_back(tmp);
//         for (int i = merge_idx+1;i< intervals.size(); i++) result.push_back(intervals[i]);
        
//         return result;

        
//     }
// };

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // if (intervals.size()==0) {
        //     result.push_back(newInterval);
        //     return result;
        // }

        while(i < n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }
        

        return result;
    }
};