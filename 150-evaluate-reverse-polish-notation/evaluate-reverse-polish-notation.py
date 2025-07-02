class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for elem in tokens:
            if elem=="+" or elem=="-" or elem=="*" or elem=="/":
                b = st[-1]
                st.pop()
                a = st[-1]
                st.pop()
                if elem=="+": st.append(a+b)
                elif elem=="-": st.append(a-b)
                elif elem=="*": st.append(a*b)
                elif elem=="/": st.append(int(a/b))
            else: st.append(int(elem))
        
        return st[0]
        