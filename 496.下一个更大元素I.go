
// monotonic stack & hash map
func nextGreaterElement(subset []int, nums []int) []int {
	stk := []int {}
	m := map[int]int {}
	// construct a monotinic stack
	for i := len(nums) - 1; i >= 0; i-- {
		// guarantee to choose the greater element to the right of the current
		for len(stk) > 0 && stk[len(stk) - 1] < nums[i] {
			stk = stk[: len(stk) - 1]
		}
		if len(stk) > 0 {
			m[nums[i]] = stk[len(stk) - 1]
		} else {
			m[nums[i]] = -1
		}
		stk = append(stk, nums[i])
	}
	ans := make([]int, len(subset))
	for i, num := range subset {
		ans[i] = m[num]
	}
	return ans
}