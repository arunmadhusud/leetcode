class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::queue<pair<string,int>> q;
        q.push({beginWord,1});
        std::unordered_set st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            auto& curr= q.front();
            string word = curr.first;            
            int steps = curr.second;
            q.pop();
            if(word==endWord) return steps;
            
            string original_char = word;
            for(int i = 0; i< word.size();i++){                
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if (st.count(word)){
                        q.push({word,steps+1});
                        st.erase(word);
                    } 
                }
                word = original_char;
            }
        }

        return 0;
        
    }
};