class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort the events by their start day

        sort(events.begin(), events.end());

        // Priority queue to keep track of events' end days

        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, n = events.size(), day = 0, res = 0;

        // Iterate until all events are processed or the priority queue is empty

        while (!pq.empty() || i < n) {

            // If the priority queue is empty, move the day to the next event's start day

            if (pq.empty()) {

                day = events[i][0];

            }

            // Add all events that start on the current day to the priority queue

            while (i < n && events[i][0] <= day) {

                pq.push(events[i][1]);

                i++;

            }
           
            // Attend the event that ends the earliest (top of the priority queue)
            pq.pop();
            res++;
            day++;

            // Remove events from the priority queue that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return res;
    }
};