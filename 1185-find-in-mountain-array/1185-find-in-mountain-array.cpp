/*
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 0, high = mountainArr.length() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int curr = mountainArr.get(mid);
            int next = mountainArr.get(mid + 1);
            if (curr < next) {
                if (curr == target) {
                    return mid;
                }
                if (next == target) {
                    return mid + 1;
                }
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        // low has peak stored
        int peak = low;
        high = peak;
        low = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (target > mountainArr.get(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = peak+1;
        high = mountainArr.length() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (target < mountainArr.get(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};