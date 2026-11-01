
class MedianFinder {
    // Max heap: stores the smaller half
    priority_queue<int> smallHeap;

    // Min heap: stores the larger half
    priority_queue<int, vector<int>, greater<int>> largeHeap;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // Step 1: Insert into the appropriate heap
        if (smallHeap.empty() || num <= smallHeap.top()) {
            smallHeap.push(num);
        } else {
            largeHeap.push(num);
        }

        // Step 2: Balance the sizes of the heaps
        if ((int)smallHeap.size() - (int)largeHeap.size() >   1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        } 
        else if ((int)largeHeap.size() - (int)smallHeap.size() >   1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian() {
        // Odd number of elements
        if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        }

        if (largeHeap.size() > smallHeap.size()) {
            return largeHeap.top();
        }

        // Even number of elements
        return (smallHeap.top() + (double)largeHeap.top()) / 2.0;
    }
};
