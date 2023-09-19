class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for x in nums:
            idx = abs(x)
            if nums[idx]<0:
                return idx
            nums[idx] = -nums[idx]
        return len(nums)