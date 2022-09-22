class Solution {
public:
	int strStr(string haystack, string needle) {

		int n = haystack.length();
		int m = needle.length();

		if (m == 0 || n == 0)
			return -1;

		int lps[m], i = 1, prev = 0;
		lps[0] = 0;
		while (i < m) {
			if (needle[i] == needle[prev]) {
				lps[i] = prev + 1;
				prev++;
				i++;
			}
			else {
				if (prev == 0) {
					lps[i] = 0;
					i++;
				}
				else {
					prev = lps[prev - 1];
				}
			}
		}
		int j = 0; //needle
		i = 0; //haystack
		while (i < n) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				if (j == 0) i++;
				else j = lps[j - 1];
			}
			if (j == m) return i - m;
		}
		return -1;
	}
};