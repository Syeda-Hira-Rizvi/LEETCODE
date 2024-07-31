class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {

            return false; // If lengths are different, they can't be anagrams

        }

        unordered_map<char, int> charCount; // HashMap to store character count

        // Count characters in string s

        for (char c : s) {

            charCount[c]++;

        }

        // Decrement count for characters in string t

        for (char c : t) {

            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {

                return false; // If a character in t is not found in s or count goes below zero, they are not anagrams

            }

            charCount[c]--;

        }

        return true; // If all characters are matched and counts are equal, they are anagrams

    }
};