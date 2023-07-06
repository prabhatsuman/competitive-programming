def count_colorings(N, K):
    total_colorings = K ** N  # Total number of colorings without the extra condition

    for i in range(1, N+1):
        for j in range(1, K+1):
            valid_colorings = 0
            for color in range(1, K+1):
                if abs(color - j) < K and abs(i - color) < K:
                    valid_colorings += 1

            total_colorings -= valid_colorings - 1  # Subtract the invalid colorings

    return total_colorings


for _ in range(int(input())):
    n, m = map(int, input().split())
    print(count_colorings(n, m))
