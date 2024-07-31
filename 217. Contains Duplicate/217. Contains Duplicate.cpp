class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> numMap;

        // Iterate through each number in the array

        for (int num : nums) {

            // Check if the number is already in the hashmap

            if (numMap.find(num) != numMap.end()) {

                // If it is, we found a duplicate

                return true;

            }

            // Otherwise, add the number to the hashmap

            numMap[num] = true;

        }

        // If we finish the loop without finding duplicates, return false

        return false;
    }
};