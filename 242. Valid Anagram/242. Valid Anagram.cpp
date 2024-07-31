class Solution {
public:
    bool isAnagram(string s, string t) {
   
        if (s.length() != t.length()) {

            return false; // If lengths are different, they can't be anagrams

        }

        
        int charCount[26] = {0}; // Array to store character count

        

        // Count characters in string s

        for (char c : s) {

            charCount[c - 'a']++;

        }

        

        // Decrement count for characters in string t

        for (char c : t) {

            if (charCount[c - 'a'] == 0) {

                return false; // If a character in t is not found in s, they are not anagrams

            }

            charCount[c - 'a']--;

        }

        

        return true; // If all characters are matched and counts are equal, they are anagrams

    }

};

    