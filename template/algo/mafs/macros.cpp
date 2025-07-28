#define long long long

#define am(x, y) (((x) + (y)) % MOD)
#define sm(x, y) am(x, -y + MOD)
#define mm(x, y) (((x) * (y)) % MOD)
#define dm(x, y) mm(x, inv(y))
const int MOD = 1e9 + 7;

long exp(long x, long p) { return p ? mm(exp(mm(x, x), p / 2), (p & 1 ? x : 1)) : 1; }

int inv(int x) { return exp(x, MOD - 2); }
