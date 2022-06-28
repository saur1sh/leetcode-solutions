class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, len=0;
        set <int> s1;
        for(int r=0; r<s.length(); r++){
            while(s1.count(s[r])){
                s1.erase(s[l]);
                l++;
            }
            s1.insert(s[r]);
            len = max(len, r-l+1);
        }
        return len;
    }
};