
// binary search
func specialArray(nums []int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))
	for l, r := 1, len(nums); l <= r; {
		m := (l + r) >> 1
		if nums[m - 1] >= m {
			if m == len(nums) || nums[m] < m {
				return m
			} else {
				l = m + 1
			}
		} else {
			r = m - 1
		}
	}
	return -1
}