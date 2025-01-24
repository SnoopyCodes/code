from functools import lru_cache
#chat, obviously
N = int(input())
sushi_list = list(map(int, input().split()))

# Count how many dishes have exactly 1, 2, or 3 pieces
count = [0, 0, 0]  # count[i] = how many dishes have (i+1) pieces
for s in sushi_list:
    count[s-1] += 1

@lru_cache(None)
def dp(a, b, c):
    """
    a = number of dishes with exactly 1 piece
    b = number of dishes with exactly 2 pieces
    c = number of dishes with exactly 3 pieces
    Returns the expected number of additional die rolls needed 
    from this state.
    """
    if a < 0 or b < 0 or c < 0:
        return 0  # Not a valid state, return 0 or handle gracefully
    if a == 0 and b == 0 and c == 0:
        return 0  # No sushi left, 0 more rolls needed

    # total number of dishes with sushi
    tot = a + b + c

    # The formula:
    # dp(a,b,c) = ( N + a*dp(a-1,b,c) + b*dp(a+1,b-1,c) + c*dp(a,b+1,c-1) ) / tot
    # Explanation:
    #   1) Each roll adds "1" to expected count, so the numerator has N for each state,
    #      but we factor out tot eventually => it's effectively "N / tot + ..."
    #   2) a*(dp(a-1,b,c)) accounts for picking a dish with 1 piece.
    #   3) b*(dp(a+1,b-1,c)) accounts for picking a dish with 2 pieces.
    #   4) c*(dp(a,b+1,c-1)) accounts for picking a dish with 3 pieces.
    #   5) Probability of picking a dish with 0 pieces => we stay in (a,b,c),
    #      which is implicitly handled by the formula re-derivation.

    res = N
    if a > 0:
        res += a * dp(a-1, b, c)
    if b > 0:
        res += b * dp(a+1, b-1, c)
    if c > 0:
        res += c * dp(a, b+1, c-1)

    return res / tot

# Compute the expected number of rolls
a, b, c = count
answer = dp(a, b, c)

print(f"{answer:.9f}")  # print with desired precision
