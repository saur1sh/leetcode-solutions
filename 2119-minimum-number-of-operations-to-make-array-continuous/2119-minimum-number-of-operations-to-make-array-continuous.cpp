class Solution {
public:
    int minOperations(vector<int>& nums) {
        int m = nums.size(), res = m;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int r = 0, n = nums.size();
        for(int l=0; l<n; l++) {
            r = upper_bound(nums.begin(), nums.end(), nums[l]+m-1)-nums.begin();
            res = min(res, m-(r-l));
        }
        return res;
    }
};