class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};    

        // Mapping from digit to corresponding letters

        vector<string> digitToLetters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> result;

        string currentCombination;

        

        // Start backtracking

        backtrack(result, digitToLetters, digits, 0, currentCombination);

        

        return result;

    }


private:

    void backtrack(vector<string>& result, const vector<string>& digitToLetters, 

                   const string& digits, int index, string& currentCombination) {

        // If the current combination length is equal to digits length, add to result

        if (index == digits.size()) {

            result.push_back(currentCombination);

            return;

        }
        // Get the letters corresponding to the current digit

        string letters = digitToLetters[digits[index] - '2'];

        

        // Explore each letter for the current digit

        for (char letter : letters) {

            currentCombination.push_back(letter);

            backtrack(result, digitToLetters, digits, index + 1, currentCombination);

            currentCombination.pop_back(); // backtrack

        }
    }
};