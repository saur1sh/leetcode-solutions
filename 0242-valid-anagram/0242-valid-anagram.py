class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        sHash = {}
        tHash = {}
        for x in s:
            sHash[x] = 1 + sHash.get(x, 0)
        for x in t:
            tHash[x] = 1 + tHash.get(x, 0)
        for key, val in tHash.items():
            if val != sHash.get(key, -1):
                return False
        return True