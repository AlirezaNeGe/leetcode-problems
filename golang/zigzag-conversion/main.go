package main

import "fmt"

func convert(s string, numRows int) string {
	numZag := numRows - 2
	rowsMap := make(map[int][]rune, numRows)
	sLength := len(s)
	i := 0
	newString := ""

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

	for i = 0; i < numRows; i++ {
		for _, c := range rowsMap[i] {
			newString += string(c)
		}
	}

	return newString
}

func main() {
	result := convert("PAYPALISHIRING", 4)
	fmt.Println(result)
}
