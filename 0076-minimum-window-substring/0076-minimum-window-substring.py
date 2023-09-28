from collections import defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        mp = [0] * 128
        l = r = 0
        matches = 0
        minLen = float('inf')
        minStart = 0

        for c in t:
            mp[ord(c)] += 1

        while r < len(s):
            if mp[ord(s[r])] > 0:
                matches += 1
            mp[ord(s[r])] -= 1

            while matches == len(t):
                if r - l + 1 < minLen:
                    minLen = r - l + 1
                    minStart = l

                mp[ord(s[l])] += 1
                if mp[ord(s[l])] > 0:
                    matches -= 1
                l += 1

            r += 1

        return "" if minLen == float('inf') else s[minStart:minStart + minLen]