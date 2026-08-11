#include <vector>
#include <queue>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        std::priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) { // Only push tasks that actually exist
                pq.push(count);
            }
        }

        int totalTime = 0;

        while (!pq.empty()) {
            std::vector<int> temp;
            int cycleSize = n + 1; // Each cycle allows up to n + 1 tasks
            int tasksProcessed = 0;

            for (int i = 0; i < cycleSize; ++i) {
                if (!pq.empty()) {
                    int topFreq = pq.top();
                    pq.pop();
                    
                    if (topFreq - 1 > 0) {
                        temp.push_back(topFreq - 1);
                    }
                    tasksProcessed++;
                }
            }

            // Put remaining task frequencies back into the max-heap
            for (int remainingFreq : temp) {
                pq.push(remainingFreq);
            }

            // If heap is empty, we are done! Only add actual tasks processed.
            // If heap is NOT empty, this full round takes (n + 1) cycles (tasks + idle).
            if (pq.empty()) {
                totalTime += tasksProcessed;
            } else {
                totalTime += cycleSize;
            }
        }

        return totalTime;
    }
};