class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0, f=0;
        while(true) {
            f = nums[nums[f]];
            s = nums[s];
            if(s==f)
                break;
        }
        s = 0;
        while(s!=f) {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};