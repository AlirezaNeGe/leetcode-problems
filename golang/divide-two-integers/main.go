package main

import (
	"fmt"
	"math"
)

func divide(dividend int, divisor int) int {
	quotient := 0
	answer := 0
	absDiviend := int(math.Abs(float64(dividend)))
	absDivisor := int(math.Abs(float64(divisor)))
	isPositive := false
	if (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0) {
		isPositive = true
	}

	for {
		if absDiviend-absDivisor >= 0 {
			quotient += 1
			absDiviend -= absDivisor
		} else {
			if isPositive {
				answer = quotient
				break
			}
			answer = -quotient
			break
		}
	}
	if answer > math.MaxInt32 {
		return math.MaxInt32
	} else if answer < math.MinInt32 {
		return math.MinInt32
	}
	return answer

}

func main() {
	dividend := 7
	divisor := -3
	fmt.Println("result: ", divide(dividend, divisor))
}
