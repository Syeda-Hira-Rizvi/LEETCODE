class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     // Result vector to store the shuffled elements

        std::vector<int> result;

        // Reserve space for 2n elements to optimize performance

        result.reserve(2 * n);

        

        // Two pointers

        int i = 0;     // Pointer to the start of the first half

        int j = n;     // Pointer to the start of the second half

        

        // Iterate over the range of 2n elements

        for (int k = 0; k < n; ++k) {

            // Add elements from the first half and second half alternately

            result.push_back(nums[i]);

            result.push_back(nums[j]);

            // Move the pointers forward

            i++;

            j++;

        }

        

        return result;   
    }
};