class Solution {

    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest/minutesToDie+1;
        var x = 0;
        while(Math.pow(states, x)<buckets) {
            ++x;
        }
        return x;
    }
}