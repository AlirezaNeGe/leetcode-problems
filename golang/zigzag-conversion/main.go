package main

import (
	"fmt"
	"strings"
	"time"
)

func convert(s string, numRows int) string {
	numZag := numRows - 2
	rowsMap := make(map[int][]rune, numRows)
	sLength := len(s)
	i := 0

	l := 0
	for l < sLength {
		if i < numRows {
			rowsMap[i] = append(rowsMap[i], rune(s[l]))
			i++
			l++
		} else {
			i--
			for j := range numZag {
				if l < sLength {
					rowsMap[i-j-1] = append(rowsMap[i-j-1], rune(s[l]))
					l++
				}
			}
			i = 0
		}
	}
	newString := strings.Builder{}

	for i = 0; i < numRows; i++ {
		for _, c := range rowsMap[i] {
			_, _ = newString.WriteString(string(c))
		}
	}

	return newString.String()
}

func main() {
	now := time.Now()
	result := convert("PAYPALISHIRING", 4)
	end := time.Since(now)
	fmt.Println("time: ", end)
	fmt.Println("result: ", result)

}
