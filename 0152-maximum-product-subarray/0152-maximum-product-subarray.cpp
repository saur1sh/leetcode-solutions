class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod = 1;
        for(const int &e: nums) {
            prod *= e;
            maxi = max(prod, maxi);
            if(prod==0) {
                prod = 1;
            }
        }
        prod = 1;
        for(int i=nums.size()-1; i>=0; i--) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if(prod==0) {
                prod = 1;
            }
        }
        return maxi;
    }
};