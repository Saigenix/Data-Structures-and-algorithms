# python3

from collections import namedtuple

Bracket = namedtuple("Bracket", ["char", "position"])


def are_matching(left, right):
    return (left + right) in ["()", "[]", "{}"]


def find_mismatch(text):
    num = 0
    opening_brackets_stack = []
    for i, next in enumerate(text):
        if next in "([{":
            # Process opening bracket, write your code here
            opening_brackets_stack.append(Bracket(next,i))
            # num+=1

        if next in ")]}":
            # Process closing bracket, write your code here
            if len(opening_brackets_stack) == 0:
                num = 1+i
                return num
            if are_matching(opening_brackets_stack[-1].char, next):
                opening_brackets_stack.pop()
                # num-=1
            else:
                num = i+ 1
                return num
    if len(opening_brackets_stack) == 0:
        return "Success"
    else:
        return opening_brackets_stack[-1].position+1


def main():
    text = input()
    mismatch = find_mismatch(text)
    print(mismatch)
    # Printing answer, write your code here


if __name__ == "__main__":
    main()
