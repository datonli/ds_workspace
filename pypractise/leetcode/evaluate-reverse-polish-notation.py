class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack = []
        for token in tokens:
            if token in "+-*/":
                stack.append(self.caculate(token,int(stack.pop()),int(stack.pop())))
            else:
                stack.append(int(token))

        return stack.pop()

    def caculate(self,token,m,n):
        if token == '+':
            return m + n
        elif token == '-':
            return n - m
        elif token == '*':
            return m*n
        elif token == '/':
            return int((n+0.0)/(m+0.0))

if __name__ == '__main__':
    tests = [["18"],["10","6","9","3","+","-11","*","/","*","17","+","5","+"]];
    so = Solution()
    for test in tests:
        print so.evalRPN(test)