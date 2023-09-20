class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        if(len(nums)==1):
            return 0
        curr, cnt = 0, 0
        prev=nums[0]
        for i in range(2, len(nums)):
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]):
                curr+=1
                cnt+=curr
            else:
                curr=0
        return cnt


        