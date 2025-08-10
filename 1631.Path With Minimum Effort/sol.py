class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row, col = len(heights), len(heights[0])

        minHeap = [[0, 0 , 0]] # [diff, row, col] 

        visited = set()
        


        while minHeap:
            dif, r, c = heapq.heappop(minHeap)

            if (r, c) in visited:
                continue 
            visited.add((r,c))
            if (r,c)  == (row-1, col-1):
                return dif 

            dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

            for dr, dc in dir:
                if r+dr in range(row)  and c +dc in range(col) and (r+dr, c+dc) not in visited :
                    heapq.heappush(minHeap,[max(dif, abs(heights[r][c]-heights[r+dr][c+dc])), r+dr, c+dc])
                    