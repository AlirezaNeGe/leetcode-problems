package main

import "fmt"

func generateParenthesis(n int) []string {
	var result []string
	var backtrack func(left, right int, s string)

	backtrack = func(left int, right int, s string) {
		if len(s) == 2*n {
			result = append(result, s)
			return
		}
		if left < n {
			backtrack(left+1, right, s+"(")
		}
		if right < left {
			backtrack(left, right+1, s+")")
		}
	}
	backtrack(0, 0, "")

	return result
}

func main() {
	result := generateParenthesis(3)
	fmt.Println("result: ", result)
}
