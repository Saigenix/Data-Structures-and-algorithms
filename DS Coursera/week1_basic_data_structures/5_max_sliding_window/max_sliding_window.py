# python3


def max_sliding_window_naive(nums, k):
    n = len(nums)
    seen = []
    ans = []
    for i in range(n):
        if seen and seen[0] == i-k:
            seen.pop(0)

        while seen and nums[seen[-1]] < nums[i]:
            seen.pop()

        seen.append(i)
        if i >= k-1:
            ans.append(nums[seen[0]])
    return ans


if __name__ == '__main__':
    n = int(input())
    input_sequence = [int(i) for i in input().split()]
    assert len(input_sequence) == n
    window_size = int(input())

    print(*max_sliding_window_naive(input_sequence, window_size))
