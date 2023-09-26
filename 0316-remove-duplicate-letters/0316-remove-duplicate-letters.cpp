class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {};
        int vis[26] = {};
        for(const auto &e: s) {
            freq[e-'a']++;
        }
        stack <char> st;
        for(const auto &e: s) {
            if(!vis[e-'a']) {
                while(!st.empty() && e<st.top() && freq[st.top()-'a']>=1) {
                    vis[st.top()-'a'] = 0;
                    st.pop();
                }
                st.push(e);
                vis[e-'a'] = 1;
            }
            freq[e-'a']--;
        }
        string ans ="";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};