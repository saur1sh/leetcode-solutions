class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i=0; i<nums.size()-2; i++) {
            int l=i+1, r=nums.size()-1;
            while(l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum==0) {
                    st.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                if(sum>0) {
                    r--;
                }
                if(sum<0) {
                    l++;
                }
            }
        }
        vector<vector<int>> ans;
        for(const auto &e: st) {
            ans.push_back(e);
        }
        return ans;
    }
};