class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def merge(arr: list, l: int, m: int, r: int):
            left, right = arr[l:m+1], arr[m+1:r+1]
            i, j, k = l, 0, 0
            while j<len(left) and k<len(right):
                if left[j] <= right[k]:
                    arr[i] = left[j]
                    j += 1
                else:
                    arr[i] = right[k]
                    k += 1
                i += 1
            while j<len(left):
                arr[i] = left[j]
                j += 1
                i += 1
            while k<len(right):
                arr[i] = right[k]
                k += 1
                i += 1
            

        def merge_sort(arr: list, l: int, r: int):
            if l==r:
                return arr
            mid = (l+r)//2
            merge_sort(arr, l, mid)
            merge_sort(arr, mid+1, r)
            merge(arr, l, mid, r)
            return arr
        
        merge_sort(nums, 0, len(nums)-1)

        return nums