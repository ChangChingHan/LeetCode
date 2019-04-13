# https://leetcode.com/problems/first-bad-version/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 0) return 0;
        int lower = 1;
        int upper = n;
        int mid = 1;
        
        while (lower <  upper) {
            mid = lower + (upper-lower)/2; 
            if (isBadVersion(mid)) {
                upper = mid;
            } else {
                lower = mid + 1;
            }
        }
        return lower;
    }
};
