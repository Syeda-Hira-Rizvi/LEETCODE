#include <queue>

class RecentCounter {
public:
    std::queue<int> queue;

    RecentCounter() {
        // Constructor doesn't need to do anything special in C++
    }

    int ping(int t) {
        // Add the current timestamp to the queue
        queue.push(t);

        // Remove timestamps that are older than 3000 milliseconds from the current timestamp
        while (!queue.empty() && queue.front() < t - 3000) {
            queue.pop();
        }

        // The size of the queue is the number of recent pings
        return queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */