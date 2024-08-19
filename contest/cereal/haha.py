def max_pancakes_for_lura(n, pancakes):
    # Calculate prefix sums
    prefix_sum = [0] * n
    prefix_sum[0] = pancakes[0]
    for i in range(1, n):
        prefix_sum[i] = prefix_sum[i-1] + pancakes[i]
    
    # Maximum Lura can get if she starts at position i
    max_lura = 0
    
    for i in range(n):
        # Lura starts at position i
        total_lura = 0
        for j in range(i, n + i):
            cur_idx = j % n
            total_lura += pancakes[cur_idx]
            # Lura collects from i to cur_idx, Oscar starts at cur_idx + 1
            remaining_pancakes = prefix_sum[(cur_idx + 1) % n - 1] - (prefix_sum[i-1] if i > 0 else 0)
            max_lura = max(max_lura, total_lura - remaining_pancakes)
    
    return max_lura

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        pancakes = list(map(int, input().split()))
        print(max_pancakes_for_lura(n, pancakes))

# Example use case:
solve()