class Solution:
    def numIslands(self, grid: List[List[str]]) -> int: 
        if not grid:
            return 0
        
        n = len(grid)
        m = len(grid[0])
        visited = set()

        count = 0

        def bfs(r,c):
            q = []
           
        
            visited.add((r,c))
            q.append((r,c))


            while q:
                row, col = q.pop(0)
                dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for dr, dc in dir :
                    
                    if ((row + dr ) in range(n)) and ((col+dc) in range(m))  and ((row+dr, col+dc) not in visited)and grid[row+dr][col+dc] == "1":
                        visited.add((row+dr, col+dc))
                        q.append((row+dr, col+dc))




        for i in range(n):
            for j in range(m):
                if (grid[i][j] == "1" and (i, j) not in visited):
                    bfs(i, j)
                    count += 1

        return count
        