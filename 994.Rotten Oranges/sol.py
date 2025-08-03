class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        colms = len(grid[0])
        visited = set()
        q = []
        time = 0
        fresh = 0
        for i in range(rows):
            for j in range(colms):
                if grid[i][j] == 2 :
                    q.append((i, j, 0))
                    
                if grid[i][j] == 1:
                    fresh += 1

        dir = [[-1, 0], [1, 0], [0,-1], [0, 1]]

        while q:
            r, c , t = q.pop(0)
            time = max(t, time)
            for dr, dc in dir:
                if r+dr in range(rows) and c+dc in range(colms) and (r+dr, c+dc) not in visited and grid[r+dr][c+dc] == 1:
                    fresh -= 1
                    q.append((r+dr, c+dc, t+1))
                    visited.add((r+dr, c+dc))
                    

        if (not fresh):
            return time 
        else:
            return -1
            
