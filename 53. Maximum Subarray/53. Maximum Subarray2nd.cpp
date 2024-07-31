class Solution {
public:

int maxSubArray(vector<int>& nums) {

    // To find the maximum sum possible

    int max_so_far = nums[0];

    // To store the maximum found at a position

    int curr_max = nums[0];

    for (int i = 1; i < nums.size(); i++) {

        // Equivalent to step 3

        curr_max = max(nums[i], nums[i] + curr_max);

        // Equivalent to step 4

        max_so_far = max(curr_max, max_so_far);

    }

    return max_so_far;

}
    };