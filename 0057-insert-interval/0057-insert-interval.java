class Solution {
    public int[][] insert(int[][] arr, int[] newInterval) {
        int[][] ans = new int[arr.length + 1][2];
        int id = 0;
        int i = 0;
        while (i < arr.length && arr[i][1] < newInterval[0]) {
            ans[id][0] = arr[i][0];
            ans[id++][1] = arr[i][1];
            i++;
        }
        while (i < arr.length && arr[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(arr[i][0], newInterval[0]);
            newInterval[1] = Math.max(arr[i][1], newInterval[1]);
            i++;
        }
        ans[id][0] = newInterval[0];
        ans[id++][1] = newInterval[1];
        while (i < arr.length) {
            ans[id][0] = arr[i][0];
            ans[id++][1] = arr[i][1];
            i++;
        }
        return Arrays.copyOf(ans, id);
    }
}