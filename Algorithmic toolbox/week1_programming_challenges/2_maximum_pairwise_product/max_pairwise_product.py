def max_pairwise_product(numbers):
    n = len(numbers)
    max_product = 0
    numbers.sort()
    return numbers[len(numbers)-1] * numbers[len(numbers)-2]


if __name__ == '__main__':
    _ = int(input())
    input_numbers = list(map(int, input().split()))
    print(max_pairwise_product(input_numbers))
