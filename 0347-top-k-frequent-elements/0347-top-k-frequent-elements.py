class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for _ in range(len(nums)+1)]

        for x in nums:
          count[x] = 1 + count.get(x, 0)
        
        for x, c in count.items():
          freq[c].append(x)

        res = []
        for i in range(len(freq)-1, 0, -1):
          for n in freq[i]:
            res.append(n)
            if len(res)==k:
              return res