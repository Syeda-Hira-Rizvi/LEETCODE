class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        int n = s.length();

        

        // 1. Ignore leading whitespace

        while (i < n && s[i] == ' ') {

            i++;

        }

        // 2. Determine the sign

        int sign = 1;

        if (i < n && (s[i] == '-' || s[i] == '+')) {

            if (s[i] == '-') {

                sign = -1;

            }

            i++;

        }

        // 3. Read the integer value

        int result = 0;
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow and underflow
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // Apply the sign
        return result * sign;
        
    }
};