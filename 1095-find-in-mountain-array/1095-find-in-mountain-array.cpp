/**
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
     int findInMountainArray(int target, MountainArray &a)
    {
        int n = a.length();
        int peak = -1;
        if (a.get(0) > a.get(1))
            peak = 0;
        else if (a.get(n - 1) > a.get(n - 2))
            peak = n - 1;
        else
        {
            int low = 1, high = n - 2;
            while (low <= high)
            {
                int mid = (low + high) >> 1;
                if (a.get(mid) < a.get(mid + 1))
                {
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            peak = low;
        }
        int low = 0, high = peak;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (a.get(mid) < target)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (low>=0 && a.get(low) == target)
            return low;
        low = peak, high = n-1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (a.get(mid) > target)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        // return low;
        if ( low<n && a.get(low) == target)
            return low;
        return -1;
    }
};