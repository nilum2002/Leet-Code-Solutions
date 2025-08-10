class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        adj = {
            0 : [1, 3],
            1: [0, 2, 4], 
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4] 
        }

        b = "".join([str(c) for row in board for c in row])
        q = []
        q.append((b.index("0"),b, 0)) # i , board, length
        visited = set()
        visited.add(b)


        while q:
            idx, board, length = q.pop(0)

            if board == "123450":
                return length 
            b_arr = list(board)
            for j in adj[idx]:
                new_b_arr = b_arr.copy()
                new_b_arr[idx], new_b_arr[j] = new_b_arr[j], new_b_arr[idx]
                new_b = "".join(new_b_arr)
                if new_b not in visited:
                    q.append((j , new_b, length+1))
                    visited.add(new_b)
        return -1
