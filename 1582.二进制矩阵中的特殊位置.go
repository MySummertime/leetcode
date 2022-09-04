// simulate
func numSpecial(mat [][]int) (ans int) {
	for i, row := range mat {
		cnt := 0
		// count the frequency of 1 in each column
		for _, n := range row {
			cnt += n
		}
		if i == 0 {
			cnt--
		}
		// record the frequency of 1 in each column at the first row
		if cnt > 0 {
			for j, m := range row {
				if m == 1 {
					mat[0][j] += cnt
				}
			}
		}
	}
	// traverse the first row to get the quantity of special element
	for _, i := range mat[0] {
		if i == 1 {
			ans++
		}
	}
	return
}