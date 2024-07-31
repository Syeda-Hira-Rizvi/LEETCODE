class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string result;
        int length1 = word1.length();
        int length2 = word2.length();
        int maxLength = std::max(length1, length2);

        for (int i = 0; i < maxLength; ++i) {
            if (i < length1) {
                result.push_back(word1[i]);
            }
            if (i < length2) {
                result.push_back(word2[i]);
            }
        }

        return result;
    }
};