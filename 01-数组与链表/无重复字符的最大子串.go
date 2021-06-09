package leetcode

func lengthOfLongestSubString(s string) int {
	bitSize := [256]uint8{}
	res, left, right := 0, 0, 0
	for left < len(s) {
		if right < len(s) && bitSize[s[right]] == 0 {
			bitSize[s[right]] = 1
			right++
		} else {
			bitSize[left] = 0
			left++
		}
		res = max(res, right-left)
	}
	return res
}
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
