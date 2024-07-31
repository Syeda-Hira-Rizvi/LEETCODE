class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {

            return false;

        }

        int reversed = 0;

        int original = x;

        

        while (x != 0) {

            int digit = x % 10;

            

            // Check for potential overflow before multiplying by 10 and adding digit

            if (reversed > (INT_MAX - digit) / 10) {

                return false;  // Overflow would occur

            }

            

            reversed = reversed * 10 + digit;

            x /= 10;

        }

        

        return reversed == original;
    }
};