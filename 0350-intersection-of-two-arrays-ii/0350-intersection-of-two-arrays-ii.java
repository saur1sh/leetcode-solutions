class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        if (nums2.length < nums1.length) {
            return intersect(nums2, nums1);
        }
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums1.length; i++) {
            mp.put(nums1[i], mp.getOrDefault(nums1[i], 0) + 1);
        }

        List<Integer> common = new ArrayList<>();
        for (int i = 0; i < nums2.length; i++) {
            int count = mp.getOrDefault(nums2[i], 0);
            if (count > 0) {
                common.add(nums2[i]);
                mp.put(nums2[i], count - 1);
            }
        }

        return common.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }
}