class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        
        flag = len(s)
        if flag == 0:
            return True

        for i in range(len(t)):
            if t[i] == s[len(s) - flag]:
                flag -= 1
            if flag == 0:
                return True
        if flag > 0:
            return False