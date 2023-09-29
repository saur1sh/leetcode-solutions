class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false;
        bool dec = false;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int curr = prev - nums[i];
            if (!inc && !dec) {
                if (curr == 0) {
                    prev = nums[i];
                } else {
                    prev = nums[i];
                    if (curr > 0)
                        dec = true;
                    else 
                        inc = true;
                }
            }
            else if ((inc && curr <= 0) || (dec && curr >= 0)) {
                prev = nums[i];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
