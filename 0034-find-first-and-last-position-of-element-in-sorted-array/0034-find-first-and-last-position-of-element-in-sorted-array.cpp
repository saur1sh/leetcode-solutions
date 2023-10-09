class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lh = lower_bound(nums.begin(), nums.end(), target);
        auto rh = upper_bound(nums.begin(), nums.end(), target);
        int l = lh-nums.begin();
        int r = rh-nums.begin();
        if(lh==rh)
            return {-1, -1};
        return {l, r-1};
    }
};