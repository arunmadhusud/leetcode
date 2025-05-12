class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose
        for(int i = 0; i < matrix.size(); i++){
            for (int j = i+1; j < matrix[0].size(); j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        // reverse vector
        for (int i = 0; i < matrix.size(); ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};