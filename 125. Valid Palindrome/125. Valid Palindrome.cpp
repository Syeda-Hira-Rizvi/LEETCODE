class Solution {
public:
    bool isPalindrome(string s) {
       // Step 1: Normalize the string

        string cleaned = "";

        for (char c : s) {

            if (isalnum(c)) {

                cleaned += tolower(c);

            }

        }

        

        // Step 2: Use two pointers to check if the string is a palindrome

        int left = 0, right = cleaned.size() - 1;

        

        while (left < right) {

            if (cleaned[left] != cleaned[right]) {

                return false;

            }

            left++;

            right--; 
            }
        
        return true;
    }
};