class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, res=0;
        unordered_map<int, int> mp;
        for(const int &e: nums) {
            sum+=e;
            if(sum==k)
                res++;
            if(mp.count(sum-k))
                res+=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};