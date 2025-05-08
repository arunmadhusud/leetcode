class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;       
        int start = 0;
        int end = 0;
        int jumps = 0;
        int farthest = 0;
        int prevfarthest = -1;
        while(end <= n -1){
            for (int i = start; i <= end; i++){
                farthest = max(farthest, i + nums[i]);
                if(farthest >= n-1 ){
                    return jumps+1;
                }
            }
            if(farthest==prevfarthest) return -1;
            start = end + 1;
            end = farthest;
            jumps++;
        }
        return jumps;

    }
};






// True DP(bottom up)
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,INT_MAX);
//         dp[0] = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(j <= i + nums[i]) dp[j] = min(dp[j],1+dp[i]);
//             }
//         }
//         return dp[n-1];

//     }
// };







// Recursion with memoization
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         return findMin(nums,0,dp);        
//     }

//     int findMin(vector<int>& nums, int idx,vector<int>& dp ){
//         if (dp[idx]!=-1) return dp[idx];
//         if(idx>=nums.size()-1) return 0;
//         int minJumps = INT_MAX;
//         for(int i = 1; i <= nums[idx] && idx + i < nums.size(); i++){
//             int next = findMin(nums, idx + i, dp);
//             if (next != INT_MAX)
//                 minJumps = min(minJumps, 1 + next);
//         }        
//         return dp[idx] = minJumps;
//     }
// };





// Recursion (TLE)
/***
class Solution {
public:
    int jump(vector<int>& nums) {
        return findMin(nums,0);        
    }

    int findMin(vector<int>& nums, int idx){
        if(idx>=nums.size()-1) return 0;
        int minJumps = INT_MAX;
        for(int i = 1; i <= nums[idx] && idx + i < nums.size(); i++){
            int next = findMin(nums, idx + i);
            if (next != INT_MAX)
                minJumps = min(minJumps, 1 + next);
        }
        return minJumps;
    }
};
***/
