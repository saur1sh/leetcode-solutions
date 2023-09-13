class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int count[1024] = {};
        count[0] = 1;
        int mask=0;
        long long res = 0;
        for(const char &e: word) {
            mask ^= 1<<(e-'a');
            res += count[mask];
            for(int i=0; i<10; i++) {
                res += count[mask^(1<<i)];
            }
            count[mask]++;
        }
        return res;
    }
};