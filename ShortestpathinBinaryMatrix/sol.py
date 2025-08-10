class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = []
        visited = set()
        q.append((0,0, 1))
        visited.add((0,0))
        if grid[0][0] == 1:
            return -1


        while q:
            r, c, length = q.pop(0)

            
            if r == n -1 and c == n-1:
                return length
            dir = [[0, 1], [1, 0],[0, -1], [-1, 0],[1, 1], [1, -1],[-1, 1], [-1, -1]]
            for dr, dc in dir:
                if r+dr in range(n) and c +dc in range(n) and (r+dr,c+dc) not in visited and grid[r+dr][c+dc] == 0:
                    q.append((r+dr, c+dc, length+1))
                    visited.add((r+dr, c+dc))
        return -1