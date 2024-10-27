class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        queue<std::pair<int,int>> q;
        int actColor = image[sr][sc];
        q.push({sr,sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        while(!q.empty()){
            std::pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            // Check all four neighbors
            if (r - 1 >= 0 && !visited[r - 1][c] && image[r - 1][c] == actColor) { // Up
                q.push({r - 1, c});
                visited[r - 1][c] = true;
                image[r - 1][c] = color;
            }
            if (r + 1 < image.size() && !visited[r + 1][c] && image[r + 1][c] == actColor) { // Down
                q.push({r + 1, c});
                visited[r + 1][c] = true;
                image[r + 1][c] = color;
            }
            if (c - 1 >= 0 && !visited[r][c - 1] && image[r][c - 1] == actColor) { // Left
                q.push({r, c - 1});
                visited[r][c - 1] = true;
                image[r][c - 1] = color;
            }
            if (c + 1 < image[0].size() && !visited[r][c + 1] && image[r][c + 1] == actColor) { // Right
                q.push({r, c + 1});
                visited[r][c + 1] = true;
                image[r][c + 1] = color;
            }

        }
        return image;

        
    }
};