def greedy_cut(a, b):
    moves = 0
    while a != b:
        # Always use the smaller side to make the square
        if a < b:
            moves += 1
            b = b - a
        else:
            moves += 1
            a = a - b
    return moves

# Example usage
a, b = map(int, input().split())
print(greedy_cut(a, b))