class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0, maxi=0;
        for(int r=0; r<s.length(); r++) {
            char ch = s[r];
            mp[ch]++;
            int sz = r-l+1;
            if(mp[ch]==1)
                maxi = max(maxi, sz);
            else {
                while(l<=r) {
                    if(s[l]==ch) {
                        mp[s[l]]--;
                        l++;
                        break;
                    }
                    else
                        mp[s[l++]]--;
                }
            }
        }
        return maxi;
    }
};