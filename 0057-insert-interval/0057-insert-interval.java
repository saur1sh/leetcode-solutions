class Solution {
    public int[][] insert(int[][] arr, int[] newInterval) {
        int[][] ans = new int[arr.length + 1][]; 
        int id = 0;
        int i = 0;
        
        while (i < arr.length && arr[i][1] < newInterval[0]) {
            ans[id++] = arr[i++];
        }
        
        while (i < arr.length && arr[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(arr[i][0], newInterval[0]);
            newInterval[1] = Math.max(arr[i][1], newInterval[1]);
            i++;
        }
        ans[id++] = newInterval;
        
        if (i < arr.length) {
            int remaining = arr.length - i;
            System.arraycopy(arr, i, ans, id, remaining);
            id += remaining;
        }
        
        return Arrays.copyOf(ans, id);
    }
}