class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        rows , cols = len(image), len(image[0])
        original_color = image[sr][sc]



        visited = set()
       



        def bfs(i, j):
            q = []

            q.append((i, j))
            visited.add((i,j))

            while q:
            
                r , c =  q.pop(0)
                image[r][c] = color
                dir = [[1, 0],[-1, 0], [0, 1],[0, -1]]
                for dr, dl in dir:
                    if r + dr  in range(rows) and c + dl in range(cols) and (r+dr, c+dl) not in visited and image[r+dr][c + dl] == original_color:
                        
                        visited.add((r+dr, c+dl))
                        q.append((r+dr, c+dl))
                        
        bfs(sr, sc)
        return image 
        