class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        

        // Traverse through both strings using the two pointers

        while (i < s.size() && j < t.size()) {

            if (s[i] == t[j]) {

                i++;

            }

            j++;

        }

        

        // If we've traversed all of s, it's a subsequence of t

        return i == s.size();
    }
};