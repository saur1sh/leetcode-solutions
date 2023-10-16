class Solution {
public:

	vector<vector<string>> groupAnagrams(vector<string>& st) {
		map<string, vector<string>> mp;
        for (auto &e : st) {
            string t = e;
            sort(t.begin(), t.end());
            mp[t].push_back(e);
        }
        vector<vector<string>> ans;
        for (const auto &[e, t] : mp) {
            vector<string> temp;
            for (const auto &str : t) {
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        return ans;
	}
};