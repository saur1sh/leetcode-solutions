from collections import defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        mp = defaultdict(int)
        mp2 = defaultdict(int)
        
        for c in t:
            mp[c] += 1
        
        l = 0
        r = 0
        matches = len(mp)
        
        ans = s + "1"
        counter = 0
        
        while r < len(s):
            mp2[s[r]] += 1
            
            if mp2[s[r]] == mp[s[r]]:
                counter += 1
            
            if counter == matches:
                while counter == matches:
                    if r - l + 1 < len(ans):
                        ans = s[l:r + 1]
                    
                    if mp[s[l]] == mp2[s[l]]:
                        counter -= 1
                    
                    mp2[s[l]] -= 1
                    l += 1
            
            r += 1
        
        return "" if ans[-1] == '1' else ans