class Solution {
public:
    int minDeletions(string s) {
        // Frequency array to count the occurrences of each character

        vector<int> freq(26, 0);

        for (char c : s) {

            freq[c - 'a']++;

        }

        

        // Sort frequencies in descending order

        sort(freq.begin(), freq.end(), greater<int>());

        

        int deletions = 0;

        // Set the maximum allowed frequency

        int maxFreqAllowed = s.size();

        

        for (int f : freq) {

            if (f == 0) break; // If the frequency is zero, no need to process further

            if (f > maxFreqAllowed) {

                deletions += f - maxFreqAllowed;

                f = maxFreqAllowed;

            }

            maxFreqAllowed = max(0, f - 1);

        }     

        return deletions;
    }
};