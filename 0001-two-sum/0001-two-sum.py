class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        vals = {}
        for i, x in enumerate(nums):
            if vals.get(target-x) != None:
                res = []
                res.append(vals.get(target-x))
                res.append(i)
                return res
            else:
                vals[x] = i