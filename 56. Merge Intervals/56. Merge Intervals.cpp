class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        
        // Sort intervals based on the starting point

        sort(intervals.begin(), intervals.end());

        
        vector<vector<int>> merged;
    

        for (const auto& interval : intervals) {

            // If merged is empty or there is no overlap, add the interval

            if (merged.empty() || merged.back()[1] < interval[0]) {

                merged.push_back(interval);

            } else {

                // There is overlap, merge the current interval with the last one in merged

                merged.back()[1] = max(merged.back()[1], interval[1]);

            }

        }

            return merged;
    }
};