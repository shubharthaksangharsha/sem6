from typing import List

def convert_to_words(s: str) -> List[str]:
    ans = []
    s += ' '
    temp = ''

    for i in s:
        if i == ' ':
            ans.append(temp)
            temp = ''
        else:
            temp += i

    return ans

if __name__ == '__main__':
    print(convert_to_words(input("Enter a string: ")))

