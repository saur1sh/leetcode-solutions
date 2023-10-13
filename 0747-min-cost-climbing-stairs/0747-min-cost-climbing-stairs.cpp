class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int two = 0, one = cost.back(), curr = 0;
        for(int i=cost.size()-2; i>=0; i--) {
            curr = min(cost[i]+two, cost[i]+one);
            two = one;
            one = curr;
        }
        return min(one, two);
    }
};