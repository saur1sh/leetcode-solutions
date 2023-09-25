class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for(const auto &e: s)
          freq[e-'a']++;
        for(const auto &e: t) {
          freq[e-'a']--;
          if(freq[e-'a']==-1)
            return e;
        }
        for(int i=0; i<26; i++) {
          if(freq[i]<0)
            return freq[i];
        }
        return '0';
    }
};