#define am(x, y) (((x) + (y)) % MOD)
#define sm(x, y) am(x, -y + MOD)
#define mm(x, y) (((x) * (y)) % MOD)
#define dm(x, y) mm(x, inv(y))
const int MOD = 1e9 + 7;