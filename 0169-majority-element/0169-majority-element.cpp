class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0], cnt=0;
        for(const int &e: nums) {
            if(e==ele)
                cnt++;
            else {
                if(cnt==0)
                    ele = e, cnt++;
                else
                    cnt--;
            }
        }
        return ele;
    }
};