class Solution {
public:
    int heightChecker(vector<int>& heights) {
       // Step 1: Create a copy of the heights array and sort it to get the expected order

        std::vector<int> expected = heights;

        std::sort(expected.begin(), expected.end());

        // Step 2: Count the number of mismatches between heights and expected

        int mismatchCount = 0;

        for (int i = 0; i < heights.size(); ++i) {

            if (heights[i] != expected[i]) {

                ++mismatchCount;

            }
        }     

        // Step 3: Return the count of mismatches

        return mismatchCount; 
    }
};