class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3) return result;  // If there are less than 3 numbers, no triplet can be formed

        sort(nums.begin(), nums.end());  // Sort the array

        for (int i = 0; i < nums.size() - 2; ++i) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate elements

            int left = i + 1;

            int right = nums.size() - 1;

            int target = -nums[i];

            while (left < right) {

                int sum = nums[left] + nums[right];

                if (sum == target) {

                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the left pointer

                    while (left < right && nums[left] == nums[left + 1]) ++left;

                    // Skip duplicates for the right pointer

                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;

                    --right;
                    } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
                    
    }
};