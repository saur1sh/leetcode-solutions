class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        n = len(grid)
        m = len(grid[0])

        vis = set()

        def dfs(r: int, c: int):
            if (r<0 or r>=n or c<0 or c>=m or grid[r][c]==0 or (r, c) in vis):
                return 0
            vis.add((r, c))
            counts = 0
            for rx, ry in dirs:
                counts += dfs(rx+r, ry+c)
            return 1 + counts
        
        maxi = 0

        for r in range(n):
            for c in range(m):
                if grid[r][c]==1 and (r, c) not in vis:
                    maxi = max(maxi, dfs(r, c))
        return maxi