class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
            std::unordered_map<int, int> indexMap;  // Map to store the latest index of each element
     

        for (int i = 0; i < nums.size(); ++i) {

            // Check if the current element has been seen before and the difference in indices is within k

            if (indexMap.find(nums[i]) != indexMap.end() && i - indexMap[nums[i]] <= k) {

                return true;

            }

            // Update the map with the current index of the element

            indexMap[nums[i]] = i;

        }


        return false;  // No such pair found
    }
};