class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m1;
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            if(m1.find(target-nums[i])!=m1.end()){
                arr.push_back(m1[target-nums[i]]);
                arr.push_back(i);
                break;
            }
            else
                m1[nums[i]] = i;
        }
        return arr;
    }
};