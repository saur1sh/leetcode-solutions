class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums2.length < nums1.length)
            return intersection(nums2, nums1);
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums1.length; i++) {
            mp.put(nums1[i], mp.getOrDefault(nums1[i], 0) + 1);
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums2.length; i++) {
            if (mp.getOrDefault(nums2[i], 0) > 0) {
                ans.add(nums2[i]);
                mp.put(nums2[i], 0);
            }
        }
        return ans.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}