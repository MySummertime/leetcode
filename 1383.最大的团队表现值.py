
import heapq
from typing import List

class Solution:
    # priority queue
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        vec = []
        ans = ssum = 0
        # customized sort: efficiency descending
        for e, s in sorted(zip(efficiency, speed), reverse=1):
            # simulate a less-than priority queue of speed
            heapq.heappush(vec, s)
            ssum += s
            if len(vec) > k:
                ssum -= heapq.heappop(vec)
            ans = max(ans, ssum * e)
        return ans % (10 ** 9 + 7)
