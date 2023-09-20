class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        tar, n = 0, len(nums)
        for num in nums:
            tar += num
        tar -= x
        if(tar==0):
            return n
        l, maxLen, curr = 0, 0, 0
        for r in range(len(nums)):
            curr += nums[r]
            while(l<=r and curr>tar):
                curr -= nums[l]
                l+=1
            if curr==tar:
                maxLen = max(r-l+1, maxLen)
        return n-maxLen if maxLen!=0 else -1