class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> st;
        for(auto elem : tokens){
            if(elem== "+" || elem=="-" || elem=="*" || elem=="/"){
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();
                if(elem=="+") st.push(to_string(a+b));
                if(elem=="-") st.push(to_string(a-b));
                if(elem=="*") st.push(to_string(a*b));
                if(elem=="/") st.push(to_string(a/b));
            }
            else st.push(elem);
        }
        return stoi(st.top());       
        
    }
};