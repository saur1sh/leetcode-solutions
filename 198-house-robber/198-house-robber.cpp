class Solution {
    int mem[100]={-1};
    
public:
    int rob(vector<int>& nums) {
        int rob1=0, rob2=0, temp;
        for(int i=0; i<nums.size(); i++){
            temp = max(nums[i]+rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};