package main

import (
	"fmt"
)

func longestCommonPrefix(strs []string) string {
	lenStrs := len(strs)
	if lenStrs == 1 {
		return strs[0]
	}

	firstString := strs[0]
	lenFirst := len(firstString)
	longestPrefix := ""

outerLoop:
	for i := 0; i < lenFirst; i++ {
		prefix := firstString[0 : i+1]
		for j := 1; j < lenStrs; j++ {
			str := strs[j]
			if len(str) <= i {
				break outerLoop
			}

			if prefix != str[0:i+1] {
				break outerLoop
			}
		}
		longestPrefix = prefix
	}
	return longestPrefix
}

func main() {
	strs := []string{"flower", "flow", "flight"}

	fmt.Println(longestCommonPrefix(strs))
}
