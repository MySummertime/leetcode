
from heapq import heappush, heappop


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
class MedianFinder:
    def __init__(self):
        self.maxpq = []
        self.minpq = []

    # store the num into maxpq
    # while keeping the size of maxpq >= size of minpq
    def addNum(self, num: int) -> None:
        heappush(self.maxpq, -num)
        heappush(self.minpq, -heappop(self.maxpq))
        if len(self.minpq) > len(self.maxpq):
            heappush(self.maxpq, -heappop(self.minpq))

    def findMedian(self) -> float:
        if len(self.maxpq) > len(self.minpq):
            return -self.maxpq[0]
        return (-self.maxpq[0] + self.minpq[0]) / 2

