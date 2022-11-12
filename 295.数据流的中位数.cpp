
#include <queue>
#include <vector>
#include <functional>

using std::priority_queue;
using std::vector;


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
public:
    // priority queue
    MedianFinder() {}

    // push the num into maxpq
    // keep maxpq larger than minpq by 1
    void addNum(int num) {
        maxpq.push(num);
        minpq.push(maxpq.top());
        maxpq.pop();
        if (minpq.size() > maxpq.size()) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }

    double findMedian() {
        if (maxpq.size() > minpq.size()) {
            return maxpq.top();
        }
        return (maxpq.top() + minpq.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, std::less<>> maxpq;
    priority_queue<int, vector<int>, std::greater<>> minpq;
};