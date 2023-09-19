class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        dc = set()
        for x in nums:
            if x in dc:
                return x
            dc.add(x)