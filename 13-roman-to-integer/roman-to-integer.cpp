class Solution {

public:

    int romanToInt(string s) {

        // Mapping of Roman numerals to their integer values

        unordered_map<char, int> roman = {

            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},

            {'C', 100}, {'D', 500}, {'M', 1000}

        };

        // Initialize result variable to store the integer value of the Roman numeral

        int result = 0;

        // Get the length of the input string

        int n = s.length();

        

        // Iterate through each character in the string

        for (int i = 0; i < n; ++i) {

            // If the current character value is less than the next character value,

            // subtract the current character value from the result

            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {

                result -= roman[s[i]];

            } else {

                // Otherwise, add the current character value to the result

                result += roman[s[i]];

            }

        }

        

        // Return the final computed integer value

        return result;

    }

};