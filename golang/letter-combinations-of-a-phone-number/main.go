package main

import "fmt"

func letterCombinations(digits string) []string {

	digitMap := map[rune][]rune{
		'2': {'a', 'b', 'c'},
		'3': {'d', 'e', 'f'},
		'4': {'g', 'h', 'i'},
		'5': {'j', 'k', 'l'},
		'6': {'m', 'n', 'o'},
		'7': {'p', 'q', 'r', 's'},
		'8': {'t', 'u', 'v'},
		'9': {'w', 'x', 'y', 'z'},
	}

	var result []string
	if len(digits) == 0 {
		return result
	}

	var backtrack func(digits string, index int, combination string)
	backtrack = func(digits string, index int, combination string) {
		if index >= len(digits) {
			result = append(result, combination)
			return
		}
		s := digitMap[rune(digits[index])]
		for _, c := range s {
			backtrack(digits, index+1, combination+string(c))
		}
	}

	backtrack(digits, 0, "")

	return result
}

func main() {
	digits := "23"
	result := letterCombinations(digits)
	fmt.Println("result: ", result)
}
