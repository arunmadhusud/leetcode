class MinStack:

    def __init__(self):
        self.st = []
        self.min_elem = float('inf')      

    def push(self, val: int) -> None:
        if len(self.st)==0: self.min_elem = val
        else: self.min_elem = min(self.st[-1][1], val)
        self.st.append([val,self.min_elem])
        

    def pop(self) -> None:
        self.st.pop()

    def top(self) -> int:
        return self.st[-1][0]
        

    def getMin(self) -> int:
        return self.st[-1][1]

        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()