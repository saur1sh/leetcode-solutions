class Solution:
    


    def knightProbability(self, n: int, k: int, row: int, col: int) -> float:
        if k==0:
            return 1.0
        curr = [[0.0 for _ in range(n)] for _ in range(n)]
        curr [row][col] = 1
        dr = [-2, -1, 2, 1, 1, 2, -2, -1]
        dc = [-1, -2, 1, 2, -2, -1, 1, 2]
        
        for x in range(k):
            newMat = [[0.0 for _ in range(n)] for _ in range(n)]
            for x in range(n):
                for y in range(n):
                    if curr[x][y]!=0:
                        for i in range(8):
                            rx = x + dr[i]
                            ry = y + dc[i]
                            if(rx>=0 and rx<n and ry<n and ry>=0):
                                newMat[rx][ry] += curr[x][y]/8.0
            curr = newMat

        ans=0.0
        for i in range(n):
            for j in range(n):
                ans += curr[i][j]
        return ans