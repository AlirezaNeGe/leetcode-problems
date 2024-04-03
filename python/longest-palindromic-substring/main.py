class Solution:
    def longestPalindrome(self, s: str) -> str:
        length: int = len(s)
        if length == 1:
            return s
        max_length: int = 0
        longest_palindrom: str = ""

        for i in range(length-1):
            for j in range(i, length):
                substring = s[i:j+1]
                if substring == substring[::-1] and \
                        len(substring) > max_length:
                    longest_palindrom = substring
                    max_length = len(substring)

        return longest_palindrom


def main():
    solution = Solution()
    print(solution.longestPalindrome("abad"))


if __name__ == "__main__":
    main()
