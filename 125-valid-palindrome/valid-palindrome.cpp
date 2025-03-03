class Solution {
public:
    bool isPalindrome(string s) {
        string s_new="";
        for(char ch:s){
            if(isalnum(ch)){
                s_new+=tolower(ch);
            } 
        }
        // std::cout << s_new;
        int i = 0;
        int j = s_new.size()-1;
        while(i<j){
            if(s_new[i]!=s_new[j]) return false;
            i++;
            j--;
        }
        return true;
        
    }
};