package main

import "fmt"

func removeDuplicates(nums []int) int {
	numsLength := len(nums)

	j := 1
	for i := 1; i < numsLength; i++ {
		if nums[i] != nums[i-1] {
			nums[j] = nums[i]
			j++
		}
	}
	return j
}

func main() {
	nums := []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
	fmt.Println("reslut: ", removeDuplicates(nums))
}
