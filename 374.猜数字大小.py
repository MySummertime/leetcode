
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    # binary search
    def guessNumber(self, n: int) -> int:
        return self.binarySearch(1, n)

    def binarySearch(self, l: int, r: int) -> int:
        while l < r:
            m = l + ((r - l) >> 1)
            # guess is lower
            if guess(m) == 1:
                l = m + 1
            # guess is higher or just perfect
            else:
                r = m
        return r if guess(r) == 0 else -1