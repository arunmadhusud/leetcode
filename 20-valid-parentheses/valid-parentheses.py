class Solution:
    def isValid(self, s: str) -> bool:
        if len(s)%2 !=0 : return False
        st = []
        for ch in s:
            if ch=='(' or ch=='{' or ch=='[' : st.append(ch)
            else:
                if len(st)==0: return False
                elif ch == ')' and st[-1]!='(': return False
                elif ch == '}' and st[-1]!='{': return False
                elif ch == ']' and st[-1]!='[': return False
                else: st.pop()
        
        if len(st)!=0: return False
        return True
