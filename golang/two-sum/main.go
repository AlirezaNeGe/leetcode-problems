package main

import "fmt"

func twoSum(nums []int, target int) []int {
	differenceMap := make(map[int]int)
	result := make([]int, 0)

	for i, v := range nums {
		differenceMap[v] = i
	}

	for i, v := range nums {
		if index, ok := differenceMap[target-v]; ok && index != i {
			result = append(result, i, index)
			break
		}
	}

	return result
}

func main() {
	nums := []int{3, 2, 4}
	target := 6
	fmt.Println(twoSum(nums, target))
}
