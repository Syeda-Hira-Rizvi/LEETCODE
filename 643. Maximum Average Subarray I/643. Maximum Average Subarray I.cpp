class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Calculate the sum of the first window of size k

        double windowSum = 0;

        for (int i = 0; i < k; ++i) {

            windowSum += nums[i];

        }

        
        // Initialize the maximum sum as the sum of the first window

        double maxSum = windowSum;

        
        // Slide the window over the array

        for (int i = k; i < nums.size(); ++i) {

            windowSum += nums[i] - nums[i - k];

            maxSum = std::max(maxSum, windowSum);

        }
      

        // Return the maximum average

        return maxSum / k;
    }
};