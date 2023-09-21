class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        vals = set()
        for x in nums:
            if x in vals:
                return True
            vals.add(x)
        return False