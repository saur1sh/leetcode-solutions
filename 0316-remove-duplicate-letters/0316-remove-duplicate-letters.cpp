class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {};
        int vis[26] = {};
        for(const auto &e: s) {
            freq[e-'a']++;
        }
        string st;
        for(const auto &e: s) {
            if(!vis[e-'a']) {
                while(!st.empty() && e<st.back() && freq[st.back()-'a']>=1) {
                    vis[st.back()-'a'] = 0;
                    st.pop_back();
                }
                st.push_back(e);
                vis[e-'a'] = 1;
            }
            freq[e-'a']--;
        }
        return st;
    }
};