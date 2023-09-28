class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128, 0);
        int l = 0, r = 0, matches = 0;
        int minLen = INT_MAX, minStart = 0;
        
        for (char &c : t) {
            mp[c]++;
        }

        while (r < s.length()) {
            if (mp[s[r]] > 0) {
                matches++;
            }
            mp[s[r]]--;

            while (matches == t.length()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }

                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    matches--;
                }
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }

};