class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        l = cnt = curr = 0
        threshold *= k
        for r, x in enumerate(arr):
            windowSize = r-l+1
            curr += x
            if windowSize==k:
                if curr>=threshold:
                    cnt+=1
                    print(l, r)
                curr-=arr[l]
                l+=1
            
        return cnt