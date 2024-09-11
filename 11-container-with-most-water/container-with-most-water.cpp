#include <vector>
#include <algorithm> // for std::max

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0; // To keep track of the maximum area

        while (i < j) {
            // Calculate the current area
            int width = j - i;
            int height_min = std::min(height[i], height[j]);
            int area = width * height_min;

            // Update the maximum area
            max_area = std::max(max_area, area);

            // Move the pointer that points to the shorter line
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }

        return max_area;
    }
};
