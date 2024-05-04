package main

import "fmt"

func removeDuplicates(nums []int) int {
	numsLength := len(nums)
	i := 1
	j := 1
	for i < numsLength-1 {
		fmt.Println("first i: ", i)
		for nums[i] == nums[i-1] {
			i++
			fmt.Println("second i: ", i)
			fmt.Println("nums: ", nums)
		}
		nums[j+1] = nums[i]
		fmt.Println("j: ", i)
		j++
		i++
	}

	fmt.Println("finals nums: ", nums)
	return j
}

func main() {

	nums := []int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
	fmt.Println("reslut: ", removeDuplicates(nums))
}
