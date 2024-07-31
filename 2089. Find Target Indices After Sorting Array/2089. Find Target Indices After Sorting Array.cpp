class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Step 1: Sort the nums array

        std::sort(nums.begin(), nums.end());
        

        // Step 2: Find the target indices

        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {

            if (nums[i] == target) {

                result.push_back(i);

            }

        }

        // Step 3: Return the result

        return result;
    }
};