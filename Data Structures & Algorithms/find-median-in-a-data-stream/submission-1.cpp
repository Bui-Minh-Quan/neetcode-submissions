#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap;                            // Stores lower half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Stores upper half

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // 1. Add to maxHeap (lower half)
        maxHeap.push(num);

        // 2. Balance: ensure top of maxHeap <= top of minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // 3. Keep size property: maxHeap can have at most 1 more element than minHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If odd total size, median is top of maxHeap
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // If even total size, median is average of both tops
        return (maxHeap.top() + (double)minHeap.top()) / 2.0;
    }
};