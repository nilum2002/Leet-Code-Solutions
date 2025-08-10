class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:  
        col =  set()
        posDia = set() # r + c
        negDia = set() # r - c 
        res = []

        board = [["."]*n for i in range(n)]


        def backtrack(r):
            if r == n :
                copy = ["".join(row) for row in board]
                res.append(copy)
                return 
            for c in range(n):
                if c not in col and r + c not in posDia and r-c not in negDia :
                    col.add(c)
                    posDia.add(r+c)
                    negDia.add(r-c)
                    board[r][c] = "Q"
                    backtrack(r+1)
                    # remove for next iteration 
                    col.remove(c)
                    posDia.remove(r+c)
                    negDia.remove(r-c)
                    board[r][c] = "."
        backtrack(0)
        return res
