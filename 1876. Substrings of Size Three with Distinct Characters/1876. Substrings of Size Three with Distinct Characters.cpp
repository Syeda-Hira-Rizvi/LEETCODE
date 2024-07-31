class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3) {

            return 0;  // If the string is shorter than 3 characters, return 0

        }  

        int count = 0;
      

        // Iterate through the string, stopping 2 characters before the end

        for (int i = 0; i < s.length() - 2; ++i) {

            // Extract the substring of length 3 starting at index i

            string substr = s.substr(i, 3);
           

            // Check if all characters in the substring are unique

            if (substr[0] != substr[1] && substr[1] != substr[2] && substr[0] != substr[2]) {

                ++count;

            }

        }

        
        return count;
    }
};