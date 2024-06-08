class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char elem : s)
        {
            if(elem == '(' || elem == '{' || elem == '[')
            {
                stack.push(elem);
            }
            else
            {
                if (stack.empty()) return false;
                char stack_elem = stack.top();
                if ((elem == ')' && stack_elem != '(') || 
                    (elem == '}' && stack_elem != '{') || 
                    (elem == ']' && stack_elem != '['))
                {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};