package main

import "fmt"

func hasDuplicateChars(s string) bool {
	charMap := make(map[rune]bool)
	for _, char := range s {
		if charMap[char] {
			return true
		}
		charMap[char] = true
	}
	return false
}

func lengthOfLongestSubstring(s string) int {
	l := len(s)
	currentLength := 0
	maxLength := 0
	if l == 0 {
		return 0
	}

	occurrenceMap := make(map[rune]int)
	j := 0
	for i, c := range s {
		if _, ok := occurrenceMap[c]; ok {
			if occurrenceMap[c]+1 > j {
				j = occurrenceMap[c] + 1
			}
			occurrenceMap[c] = i
		} else {
			occurrenceMap[c] = i
		}

		currentLength = (i - j) + 1
		if currentLength > maxLength {
			maxLength = currentLength
		}
	}
	return maxLength
}

func main() {
	s := "abba"
	fmt.Println(lengthOfLongestSubstring(s))
}
