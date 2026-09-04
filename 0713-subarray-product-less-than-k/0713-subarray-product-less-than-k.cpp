class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        if (k <= 1) {
            return 0;
        }
        int prod = 1, count = 0;
        while (j < n) {
            prod *= nums[j];
            while (prod >= k) {
                prod /= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};