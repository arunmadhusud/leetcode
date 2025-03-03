class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 !=0) return false;
        std::stack<char> st;
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if(st.empty()) return false;
                if((ch == ')' && st.top()!='(') || (ch == '}' && st.top()!='{') || (ch == ']' && st.top()!='[')) return false;
                else st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};