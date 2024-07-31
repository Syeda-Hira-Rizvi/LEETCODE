class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If the total sum is not divisible by k, it's not possible to partition

        if (totalSum % k != 0) return false;

        int target = totalSum / k;

        vector<bool> visited(nums.size(), false);

        // Sort the array in descending order to optimize the backtracking process

        sort(nums.rbegin(), nums.rend());

        // Early exit if the largest number is greater than the target sum

        if (nums[0] > target) return false;

        return backtrack(nums, visited, k, 0, 0, target);

    }

private:

    bool backtrack(vector<int>& nums, vector<bool>& visited, int k, int currentSum, int start, int target) {

        // If we have successfully created k - 1 subsets, the last subset will automatically have the required sum

        if (k == 1) return true;
        // If current subset sum equals the target, start a new subset

        if (currentSum == target) return backtrack(nums, visited, k - 1, 0, 0, target);

        for (int i = start; i < nums.size(); ++i) {

            if (!visited[i] && currentSum + nums[i] <= target) {

                // Mark the element as visited

                visited[i] = true;

                // Recursively try to form the subset

                if (backtrack(nums, visited, k, currentSum + nums[i], i + 1, target)) return true;

                // Unmark the element as visited (backtrack)

                visited[i] = false;

                // Optimization: If a subset starts with this element and fails, no point in trying the same number again.

                if (currentSum == 0) return false;

            }

        }

        return false;
    }
};