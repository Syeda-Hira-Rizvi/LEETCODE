// API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;

        int right = n;

        
        while (left < right) {

            int mid = left + (right - left) / 2;  // Avoid potential overflow with (left + right) / 2

            if (isBadVersion(mid)) {

                right = mid;  // The first bad version is in the left half or is mid

            } else {

                left = mid + 1;  // The first bad version is in the right half

            }

        }

        // At this point, left == right, which is the first bad version

        return left;
    }
};