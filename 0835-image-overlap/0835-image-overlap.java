class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        int maxi = 0;
        for (int i = -n + 1; i < n; i++) {
            for (int j = -n + 1; j < n; j++) {
                maxi = Math.max(countOverlaps(img1, img2, i, j, n), maxi);
            }
        }
        return maxi;
    }

    public int countOverlaps(int[][] img1, int[][] img2, int xOff, int yOff, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = i + xOff;
                int y = j + yOff;
                if (x >= 0 && y >= 0 && x < n && y < n) {
                    if (img1[i][j] == 1 && img2[x][y] == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}