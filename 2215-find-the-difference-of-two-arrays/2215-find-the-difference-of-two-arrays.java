class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        int[] ar1 = new int[2001];
        int[] ar2 = new int[2001];
        int off = 1000;
        for (int i = 0; i < nums1.length; i++) {
            ar1[nums1[i] + off] = 1;
        }
        for (int j = 0; j < nums2.length; j++) {
            ar2[nums2[j] + off] = 1;
        }
        List<Integer> on1 = new ArrayList<>();
        List<Integer> on2 = new ArrayList<>();
        for (int i = 0; i <= 2000; i++) {
            if (ar1[i] != 0 && ar2[i] == 0) {
                on1.add(i - off);
            } else if (ar1[i] == 0 && ar2[i] != 0) {
                on2.add(i - off);
            }
        }
        return List.of(on1, on2);
    }
}