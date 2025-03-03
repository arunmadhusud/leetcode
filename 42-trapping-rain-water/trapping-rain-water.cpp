class Solution {
public:
    // int findMaxleft(vector<int>& height, int i) {
    //     int m = 0;  
    //     for(int j = 0; j < i; j++) {
    //         m = max(m, height[j]);
    //     }
    //     return m;
    // }

    // int findMaxright(vector<int>& height, int i) {
    //     int m = 0;
    //     for(int j = i + 1; j < height.size(); j++) {
    //         m = max(m, height[j]);
    //     }
    //     return m;
    // }

    int trap(vector<int>& height) {
        if(height.size() < 3) return 0; 
        vector<int> prefixMax(height.size(),0);
        vector<int> suffixMax(height.size(),0);
        prefixMax[0] = height[0];
        for(int i = 1; i<height.size(); i++){
            prefixMax[i] = max(prefixMax[i-1],height[i]);         
        }
        suffixMax[height.size()-1] = height[height.size()-1];
        for(int j = height.size()-2; j>=0; j--){
            suffixMax[j] = max(suffixMax[j+1],height[j]);         
        }
        int vol = 0;
        for(int i = 1; i < height.size()-1; i++) {
            int maxLeft = prefixMax[i-1];
            int maxRight = suffixMax[i+1];
            int water = min(maxLeft, maxRight) - height[i];

            if (water > 0) vol += water;
        }
        return vol;
    }
};
