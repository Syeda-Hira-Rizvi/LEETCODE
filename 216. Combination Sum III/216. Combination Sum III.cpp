class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;

        vector<int> combination;

        backtrack(result, combination, k, n, 1);

        return result;

    }

    
private:

    void backtrack(vector<vector<int>>& result, vector<int>& combination, int k, int n, int start) {

        // Base case: if the combination size is k and the sum is n

        if (combination.size() == k && n == 0) {

            result.push_back(combination);

            return;

        }
        

        // If the combination size exceeds k or the sum exceeds n, return

        if (combination.size() > k || n < 0) {

            return;

        }

        // Explore each number from 'start' to 9

        for (int i = start; i <= 9; ++i) {

            combination.push_back(i);

            backtrack(result, combination, k, n - i, i + 1);

            combination.pop_back();  // backtrack

        }
        
    }
};