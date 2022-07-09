class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        int temp, one=1, two=1, ans;
        for(int i=n-2; i>=0; i--){
            ans = one + two;
            temp = one;
            one = ans;
            two = temp;
        }
        return ans;
    }
};