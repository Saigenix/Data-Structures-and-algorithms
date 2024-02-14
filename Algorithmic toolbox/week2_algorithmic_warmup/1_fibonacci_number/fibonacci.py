def fibonacci_number(n):
    if n <= 1:
        return n

    return fibonacci_number(n - 1) + fibonacci_number(n - 2)

### Test

# if n ≤1:
# return n
# else:
# return FibRecurs(n −1) + FibRecurs(n −2)



if __name__ == '__main__':
    input_n = int(input())
    print(fibonacci_number(input_n))
