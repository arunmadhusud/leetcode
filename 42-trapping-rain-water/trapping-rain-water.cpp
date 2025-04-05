class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        for (int i = 1 ; i < n; i++){
            leftMax[i] = max(leftMax[i-1],height[i-1]);
        }
        for (int i = n-2 ; i >=0; i--){
            rightMax[i] = max(rightMax[i+1],height[i+1]);
        }

        int vol = 0;
        for (int i = 1;i < n-1; i++ ){
            int min_h = min (leftMax[i], rightMax[i]);
            vol += max(0, min_h - height[i]);
        }

        return vol;

        
    }
};
