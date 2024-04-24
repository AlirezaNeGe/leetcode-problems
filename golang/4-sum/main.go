package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int, target int) [][]int {
	numsLength := len(nums)
	var triplets [][]int

	for i := 0; i < numsLength; i++ {
		next := i + 1
		last := numsLength - 1

		for next < last {
			sum := nums[i] + nums[next] + nums[last]
			if sum == target {
				triplet := []int{nums[i], nums[next], nums[last]}
				triplets = append(triplets, triplet)

				// skip the duplicate
				for next < last && nums[next] == triplet[1] {
					next++
				}
				for next < last && nums[last] == triplet[2] {
					last--
				}
			} else if sum < target {
				next++
			} else {
				last--
			}
		}
		for i+1 < numsLength && nums[i+1] == nums[i] {
			i++
		}
	}
	return triplets
}

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	lengthNum := len(nums)
	var quadruplets [][]int

	for i := 0; i < lengthNum; i++ {
		newTarget := target - nums[i]
		triplets := threeSum(nums[i+1:], newTarget)
		for _, triplet := range triplets {
			quadruplets = append(quadruplets, []int{nums[i], triplet[0], triplet[1], triplet[2]})
		}
		// remove duplicate
		for i < lengthNum-1 && nums[i] == nums[i+1] {
			i++
		}
	}
	return quadruplets
}

func main() {
	nums := []int{5, 5, 3, 5, 1, -5, 1, -2}
	target := 4
	fmt.Println(fourSum(nums, target))
}
