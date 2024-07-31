class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        

        // Try every possible length of the substring

        for (int len = 1; len <= n / 2; ++len) {

            // Check if length len can divide the string's length without remainder

            if (n % len == 0) {

                string substring = s.substr(0, len);

                string repeated = "";

                

                // Repeat the substring n / len times

                for (int i = 0; i < n / len; ++i) {

                    repeated += substring;

                }

                

                // Check if the repeated string matches the original string

                if (repeated == s) {

                    return true;

                }

            }

        }
    return false;
        
    }
};