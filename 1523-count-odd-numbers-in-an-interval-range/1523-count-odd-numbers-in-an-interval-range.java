class Solution {
    public int countOdds(int low, int high) {
        int n1 = (high%2==0) ? high/2 : (high+1)/2;
        int n2 = (low%2==0) ? low/2 : (low+1)/2;
        return (low%2==1) ? n1-n2+1 : n1-n2;
    }
}