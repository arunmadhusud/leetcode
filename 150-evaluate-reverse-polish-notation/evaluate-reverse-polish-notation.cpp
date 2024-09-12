class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") 
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (s == "+") st.push(b+a);
                if (s == "-") st.push(b-a);
                if (s == "/") st.push(b/a);
                if (s == "*") st.push(b*a);
            }
            else st.push(stoi(s));
        }
        return st.top();
        
    }
};