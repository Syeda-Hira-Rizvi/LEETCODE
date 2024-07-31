class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Calculate the expected sum of numbers from 0 to n

        int expected_sum = n * (n + 1) / 2;

        

        // Calculate the actual sum of numbers in the array

        int actual_sum = 0;

        for (int num : nums) {

            actual_sum += num;

        }

        

        // The missing number is the difference between the expected sum and the actual sum

        return expected_sum - actual_sum;
    }
};