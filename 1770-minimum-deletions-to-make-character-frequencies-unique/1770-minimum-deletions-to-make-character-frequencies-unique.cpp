class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(const auto &e: s) {
            mp[e]++;
        }
        vector<int> v;
        for(const auto &e: mp) {
            v.push_back(e.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        set<int> st;
        int deletes = 0;
        for(int i=0; i<v.size(); i++) {
            int t = v[i];
            int dels=0;
            while(true) {
                if(t==0) {
                    break;
                }
                if(st.find(t)==st.end()) {
                    st.insert(t);
                    break;
                }
                else{
                    t--;
                    dels++;
                }
            }
            deletes+=dels;
        }
        return deletes;
    }
};