package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	var combinations [][]int
	var backtrack func(start int, curr []int)

	backtrack = func(start int, curr []int) {
		if len(curr) == 3 {
			tmp := make([]int, len(curr))
			copy(tmp, curr)
			combinations = append(combinations, tmp)
			return
		}

		for i := start; i < len(nums); i++ {
			curr = append(curr, nums[i])
			backtrack(i+1, curr)
			curr = curr[:len(curr)-1]
		}
	}

	backtrack(0, []int{})

	combinationLen := len(combinations)
	var triplets [][]int

	for i := range combinationLen {
		combination := combinations[i]
		sum := 0
		for _, v := range combination {
			sum += v
		}
		if sum == 0 {
			triplets = append(triplets, combination)
		}
	}

	tripletsLen := len(triplets)
	if tripletsLen == 1 {
		return triplets
	}

	for i := 0; i < len(triplets)-1; {
		tripletOne := triplets[i]
		for k := i + 1; k < len(triplets); {
			tripletTwo := triplets[k]
			sort.Ints(tripletOne)
			sort.Ints(tripletTwo)

			isEqualCount := 0
			for j := range tripletOne {
				if tripletOne[j] == tripletTwo[j] {
					isEqualCount++
				}
			}
			if isEqualCount == 3 {
				triplets = append(triplets[:k], triplets[k+1:]...)
			} else {
				k++
			}
		}
		i++
	}
	return triplets
}

func newThreeSum(nums []int) [][]int {
	sort.Ints(nums)
	numsLength := len(nums)
	var triplets [][]int

	for i := 0; i < numsLength; i++ {
		next := i + 1
		last := numsLength - 1

		for next < last {
			sum := nums[i] + nums[next] + nums[last]
			if sum == 0 {
				triplet := []int{nums[i], nums[next], nums[last]}
				triplets = append(triplets, triplet)

				// skip the duplicate
				for next < last && nums[next] == triplet[1] {
					next++
				}
				for next < last && nums[last] == triplet[2] {
					last--
				}
			} else if sum < 0 {
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

func main() {
	nums := []int{-1, 0, 1, 2, -1, -4}
	result := newThreeSum(nums)
	fmt.Println("result: ", result)
}
