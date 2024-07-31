class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
    // Initialize the largest and second largest numbers

        int max1 = 0;

        int max2 = 0;

        

        // Iterate through the array to find the largest and second largest numbers

        for (int num : nums) {

            if (num > max1) {

                max2 = max1; // Update second largest

                max1 = num;  // Update largest

            } else if (num > max2) {

                max2 = num; // Update second largest if num is not larger than max1

            }

        }  

        // Return the maximum product (max1 - 1) * (max2 - 1)

        return (max1 - 1) * (max2 - 1);

    }
};