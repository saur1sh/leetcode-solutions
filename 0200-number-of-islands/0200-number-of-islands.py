class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0
        n = len(grid)
        m = len(grid[0])
        vis = set()
        islands=0

        dirs = [[1,0], [0, 1], [-1, 0], [0, -1]]

        def dfs(r: int, c: int):
            if( r>=n or c>=m or r<0 or c<0 or grid[r][c]=="0" or (r, c) in vis ):
                return
            vis.add((r, c))
            for rx, rc in dirs:
                dfs(rx+r, rc+c)

        for i in range(n):
            for j in range(m):
                if grid[i][j]=="1" and (i, j) not in vis:
                    dfs(i, j)
                    islands+=1
        return islands