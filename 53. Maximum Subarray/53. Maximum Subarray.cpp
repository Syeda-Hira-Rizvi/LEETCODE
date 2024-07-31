class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;  // Handle edge case where the array is empty
        
        int max_current = nums[0];
        int max_global = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            max_current = std::max(nums[i], max_current + nums[i]);
            if (max_current > max_global) {
                max_global = max_current;
            }
        }
        
        return max_global;
    }
};