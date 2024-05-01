package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val {
		l1.Next = mergeTwoLists(l1.Next, l2)
		return l1
	}
	l2.Next = mergeTwoLists(l1, l2.Next)
	return l2
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	for len(lists) > 1 {
		newList := mergeTwoLists(lists[0], lists[1])
		lists = append(lists, newList)
		lists = lists[2:]
	}
	return lists[0]
}

func main() {
	// Create the first linked list: 1 -> 2 -> 3 -> nil
	list1 := &ListNode{Val: 1}
	list1.Next = &ListNode{Val: 2}
	list1.Next.Next = &ListNode{Val: 3}

	// Create the second linked list: 4 -> 5 -> 6 -> nil
	list2 := &ListNode{Val: 4}
	list2.Next = &ListNode{Val: 5}
	list2.Next.Next = &ListNode{Val: 6}

	// Create the second linked list: 4 -> 5 -> 6 -> nil
	list3 := &ListNode{Val: 7}
	list3.Next = &ListNode{Val: 8}
	list3.Next.Next = &ListNode{Val: 9}

	lists := []*ListNode{list1, list2, list3}
	result := mergeKLists(lists)
	fmt.Println("result: ", result)
}
