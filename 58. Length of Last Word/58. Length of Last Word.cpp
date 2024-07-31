class Solution {
public:
    int lengthOfLastWord(string s) {
        unordered_map<int, char> charMap;

        int n = s.length();

        for (int i = 0; i < n; i++) {

            charMap[i] = s[i];

        }

        int length = 0;

        bool inWord = false;

        for (int i = n - 1; i >= 0; i--) {

            if (charMap[i] != ' ') {

                length++;

                inWord = true;

            } else if (inWord) {

                break;

            }

        }

        return length;
    }
};