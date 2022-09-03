// sort & prefix sum & binary search
func answerQueries(nums []int, queries []int) []int {
	sort.Ints(nums)
    // prefix sum in place
	for i := 1; i < len(nums); i++ {
		nums[i] += nums[i - 1]
	}
    // binary search in place
	for i, q := range queries {
		queries[i] = sort.SearchInts(nums, q + 1)
	}
	return queries
}