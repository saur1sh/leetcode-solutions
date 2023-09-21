class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        vals = {}
        for i, x in enumerate(nums):
            if vals.get(target-x) != None:
                res = [vals[target-x], i]
                return res
            else:
                vals[x] = i