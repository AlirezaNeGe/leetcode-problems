package main

import "fmt"

func isValid(s string) bool {
	var charStack []rune
	if len(s) == 1 {
		return false
	}

	for _, c := range s {
		switch c {
		case '(':
			charStack = append(charStack, c)
		case ')':
			if len(charStack) > 0 && charStack[len(charStack)-1] == '(' {
				charStack = charStack[:len(charStack)-1]
			} else {
				return false
			}
		case '[':
			charStack = append(charStack, c)
		case ']':
			if len(charStack) > 0 && charStack[len(charStack)-1] == '[' {
				charStack = charStack[:len(charStack)-1]
			} else {
				return false
			}
		case '{':
			charStack = append(charStack, c)
		case '}':
			if len(charStack) > 0 && charStack[len(charStack)-1] == '{' {
				charStack = charStack[:len(charStack)-1]
			} else {
				return false
			}
		}
	}
	if len(charStack) == 0 {
		return true
	}
	return false
}

func main() {
	s := "()[]{}"
	fmt.Println(isValid(s))
}
