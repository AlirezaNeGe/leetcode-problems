package main

import "fmt"

func strStr(haystack string, needle string) int {
	needleLength := len(needle)
	haystackLength := len(haystack)
	firstChar := needle[0]
	for i, r := range haystack {
		if r == rune(firstChar) {
			if i+needleLength <= haystackLength && haystack[i:i+needleLength] == needle {
				return i
			}
		}
	}
	return -1
}

func main() {
	haystack := "aaasadbutsad"
	needle := "sad"
	result := strStr(haystack, needle)
	fmt.Println("result: ", result)
}
