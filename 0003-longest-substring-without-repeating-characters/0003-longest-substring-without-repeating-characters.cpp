class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, maxi=0;
        unordered_map<char, int> mp;
        for(int r=0; r<s.length(); r++) {
            char c = s[r];
            mp[c]++;
            int windowSize = r-l+1;
            if(mp[c]==1) {
                maxi = max(maxi, windowSize);
            }
            else {
                while(l!=r) {
                    if(s[l]==c) {
                        mp[s[l++]]--;
                        break;
                    }
                    else {
                        mp[s[l++]]--;
                    }
                }
            }
        }
        return maxi;
    }
};