class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> cumSumFreq;

        cumSumFreq[0] = 1; // To handle the case where a subarray starts from index 0

        int cumSum = 0;

        int count = 0;

        

        for (int num : nums) {

            cumSum += num;

            if (cumSumFreq.find(cumSum - k) != cumSumFreq.end()) {

                count += cumSumFreq[cumSum - k];

            }

            cumSumFreq[cumSum]++;

        }

        

        return count;
    }
};