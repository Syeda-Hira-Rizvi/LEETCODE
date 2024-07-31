class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // Power of three must be positive

        while (n % 3 == 0) {

            n /= 3;

        }

        return n == 1;
    }
};