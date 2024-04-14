from typing import List


class Solution:
    def intToRoman(self, num: int) -> str:
        values: List[int] = [1000, 900, 500,
                             400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        romans: List[str] = ["M", "CM", "D", "CD", "C",
                             "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

        values_length = len(values)
        roman_str: str = ""
        for i in range(values_length):
            value: int = values[i]
            roman: str = romans[i]
            while num >= value:
                num -= value
                roman_str += roman

        return roman_str


def main():
    solution = Solution()
    print(solution.intToRoman(58))


if __name__ == "__main__":
    main()
