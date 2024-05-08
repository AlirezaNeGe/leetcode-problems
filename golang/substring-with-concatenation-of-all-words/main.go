package main

import (
	"fmt"
	"regexp"
)

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
		re := regexp.MustCompile(p)
		index := re.FindAllIndex([]byte(s), -1)
		for _, i := range index {
			if _, ok := uniqueIndices[i[0]]; !ok {
				indices = append(indices, i[0])
				uniqueIndices[i[0]] = struct{}{}
			}
		}
	}
	return indices
}

func main() {
	words := []string{"a", "a"}
	s := "aaa"
	result := findSubstring(s, words)
	fmt.Println("permutations: ", result)
}
