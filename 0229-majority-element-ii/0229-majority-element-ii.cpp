class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int a=-1, b=-1, ca=0, cb=0;
        for(const int &e: nums) {
            if(e==a) ca++;
            else if(e==b) cb++;
            else if(ca==0) a=e, ca++;
            else if(cb==0) b=e, cb++;
            else ca--, cb--;
        }
        ca = cb = 0;
        for(const int &e: nums) {
            if(e==a) ca++;
            else if(e==b) cb++;
        }
        if(ca>nums.size()/3) ans.push_back(a);
        if(cb>nums.size()/3) ans.push_back(b);
        return ans;
    }
};