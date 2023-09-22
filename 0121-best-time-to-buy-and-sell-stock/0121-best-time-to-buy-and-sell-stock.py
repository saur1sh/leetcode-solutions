class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest = -1
        maxProfit = 0
        for x in prices:
            if lowest>x or lowest==-1:
                lowest = x
            else:
                maxProfit = max(x-lowest, maxProfit)
        return maxProfit