class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        for(auto elem : tokens){
            if(elem== "+" || elem=="-" || elem=="*" || elem=="/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(elem=="+") st.push(a+b);
                else if(elem=="-") st.push(a-b);
                else if(elem=="*") st.push(a*b);
                else if(elem=="/") st.push(a/b);
            }
            else st.push(stoi(elem));
        }
        return st.top();       
        
    }
};