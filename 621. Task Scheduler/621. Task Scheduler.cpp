class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count the frequency of each task

        unordered_map<char, int> taskCount;

        for (char task : tasks) {

            taskCount[task]++;

        }

        

        // Step 2: Find the maximum frequency

        int maxFreq = 0;

        for (auto& entry : taskCount) {

            maxFreq = max(maxFreq, entry.second);

        }

        

        // Step 3: Count how many tasks have the maximum frequency

        int maxFreqCount = 0;

        for (auto& entry : taskCount) {

            if (entry.second == maxFreq) {

                maxFreqCount++;

            }

        }
        // Step 4: Calculate the intervals needed

        int partCount = maxFreq - 1;  // Number of parts (gaps between max frequency tasks)

        int partLength = n - (maxFreqCount - 1);  // Length of each part

        int emptySlots = partCount * partLength;  // Total empty slots

        int remainingTasks = tasks.size() - maxFreq * maxFreqCount;  // Remaining tasks to place

        int idles = max(0, emptySlots - remainingTasks);  // Idle slots required

        

        // Total intervals is the sum of task size and idles

        return tasks.size() + idles;

    
    }
};