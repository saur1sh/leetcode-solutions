class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mt;
        for(const char &e: t)
            mt[e]++;
        unordered_map<char, int> ms;
        int l=0, mini=-1, tl=t.length();
        int matches = 0, ind=0;
        for(int r=0; r<s.length(); r++) {
            //acquire
            ms[s[r]]++;
            if(ms[s[r]]<=mt[s[r]])
                matches++;
            if(matches==tl) {
                if(mini==-1 || r-l+1<mini)
                    mini = r-l+1, ind=l;
                //release
                while(l<=r && matches==tl) {
                    if(r-l+1<mini)
                        mini = r-l+1, ind=l;
                    if(ms[s[l]]==mt[s[l]])
                        matches--;
                    ms[s[l++]]--;
                }
            }
        }
        return (mini==-1) ? "" : s.substr(ind, mini);
    }
};
