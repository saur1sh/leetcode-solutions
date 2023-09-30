static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<=k)
            return false;
        unordered_set<string> st;
        for(int i=0; i<s.length()-k+1; i++) {
            st.insert(s.substr(i, k));
        }
        return st.size()==pow(2,k) ? true : false;
    }
};