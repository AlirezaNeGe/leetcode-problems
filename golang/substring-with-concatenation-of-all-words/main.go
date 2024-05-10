package main

import (
	"fmt"
)

func strStr(haystack string, needle string) []int {
	var indices []int
	needleLength := len(needle)
	haystackLength := len(haystack)
	firstChar := needle[0]
	for i, r := range haystack {
		if r == rune(firstChar) {
			if i+needleLength <= haystackLength && haystack[i:i+needleLength] == needle {
				// return i
				indices = append(indices, i)
			}
		}
	}
	return indices
}

func generatePermutations(arr []string, start, end int, permutations *[]string) []string {
	if start == end {
		permutation := ""
		for _, p := range arr {
			permutation += p
		}
		*permutations = append(*permutations, permutation)
	} else {
		for i := start; i <= end; i++ {
			arr[start], arr[i] = arr[i], arr[start]
			generatePermutations(arr, start+1, end, permutations)
			arr[start], arr[i] = arr[i], arr[start]
		}
	}
	return *permutations
}

func findSubstring(s string, words []string) []int {
	var permutations []string
	var indices []int
	uniqueIndices := make(map[int]struct{})
	permutaitons := generatePermutations(words, 0, len(words)-1, &permutations)
	for _, p := range permutaitons {
		fmt.Println("p:", p)
		// re := regexp.MustCompile(p)
		// index := re.FindAllIndex([]byte(s), -1)
		index := strStr(s, p)
		for _, i := range index {
			if _, ok := uniqueIndices[i]; !ok {
				indices = append(indices, i)
				uniqueIndices[i] = struct{}{}
			}
		}
	}
	return indices
}

func main() {
	words := []string{"foo", "bar"}
	s := "barfoothefoobarman"
	result := findSubstring(s, words)
	fmt.Println("permutations: ", result)
}
