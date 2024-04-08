package main

import "fmt"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	tempX := x
	result := 0
	for tempX != 0 {
		rightDigit := tempX % 10
		result = result*10 + rightDigit
		tempX /= 10
	}

	if result == x {
		return true
	}
	return false
}

func main() {
	result := isPalindrome(-121)
	fmt.Println("r: ", result)
}
