class Solution {
public:

    static bool cmp(const string &a, const string &b) {
        return a.length()<b.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), Solution::cmp);
        unordered_map<string, int> mp;
        int maxi = 1;
        for(const auto &e: words) {
            mp[e] = 1;
            for(int i=0; i<e.size(); i++) {
                string prev = e.substr(0, i) + e.substr(i+1);
                if(mp.find(prev)!=mp.end()) {
                    mp[e] = max(mp[e], mp[prev]+1);
                }
            }
            maxi = max(maxi, mp[e]);
        }
        return maxi;
    }
};