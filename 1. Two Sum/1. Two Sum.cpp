class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index;

        

        for (int i = 0; i < nums.size(); ++i) {

            int complement = target - nums[i];

            

            // Check if the complement is already in the map

            if (num_to_index.find(complement) != num_to_index.end()) {

                return {num_to_index[complement], i};

            }

            

            // Store the index of the current number in the map

            num_to_index[nums[i]] = i;

        }

        

        // If no solution is found, return an empty vector

        // (However, the problem guarantees that exactly one solution exists)

        return {};
    }
};