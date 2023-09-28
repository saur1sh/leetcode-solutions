class Solution {
public:

	size_t hashAnagram(const string& str) {
		string sortedStr = str;
		sort(sortedStr.begin(), sortedStr.end());
		return hash<string> {}(sortedStr);
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<size_t, vector<int>> mp;
		for (int i = 0; i < strs.size(); i++) {
			unsigned long long x = hashAnagram(strs[i]);
			mp[x].push_back(i);
		}
		vector<vector<string>> ans;
		for (auto &it : mp) {
			vector<string> temp;
			for (const auto &it2 : it.second) {
				temp.push_back(strs[it2]);
			}
			ans.push_back(temp);
		}
		return ans;
	}
};