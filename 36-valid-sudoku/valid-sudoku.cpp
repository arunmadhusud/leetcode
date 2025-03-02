class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::map<int,unordered_set<char>> r_map;
        std::map<int,unordered_set<char>> c_map;
        std::map<pair<int,int>, unordered_set<char>> rc_map;

        for (int i = 0; i< 9; i++){
            for(int j = 0; j < 9; j++){
                char elem = board[i][j];
                if (elem == '.') continue;
                else{
                    if(r_map[i].find(elem)!=r_map[i].end()) return false;
                    if(c_map[j].find(elem)!=c_map[i].end()) return false;
                    int r = i/3;
                    int c = j/3;
                    if(rc_map[{r,c}].find(elem)!=rc_map[{r,c}].end()) return false;
                    r_map[i].insert(elem);
                    c_map[j].insert(elem);
                    rc_map[{r,c}].insert(elem);
                }
            }
        }

        return true;
        
    }
};