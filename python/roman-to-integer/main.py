from typing import Dict


class Solution:
    def romanToInt(self, s: str) -> int:

        roman_dict: Dict[str, int] = {
            "I": 1,
            "IV": 4,
            "V": 5,
            "IX": 9,
            "X": 10,
            "XL": 40,
            "L": 50,
            "XC": 90,
            "C": 100,
            "CD": 400,
            "D": 500,
            "CM": 900,
            "M": 1000,
        }

        len_str = len(s)
        result: int = 0
        for i in range(len_str):
            roman = roman_dict[s[i]]
            if i < len_str - 1 and roman < roman_dict[s[i+1]]:
                result -= roman
            else:
                result += roman

        return result


def main():
    solution = Solution()
    print(solution.romanToInt("III"))


if __name__ == "__main__":
    main()
