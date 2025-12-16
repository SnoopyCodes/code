#define long long long

#define am(x, y) (((x) + (y)) % MOD)
#define sm(x, y) am(x, -y + MOD)
#define mm(x, y) (((x) * (y)) % MOD)
#define dm(x, y) mm(x, inv(y))
const int MOD = 1e9 + 7;

int Add(int &a, int b) { return a -= ((a += b) >= MOD) * MOD; }
int add(int a, int b) { return Add(a, b); }

int Sub(int &a, int b) { return a += ((a -= b) < 0) * MOD; }
int sub(int a, int b) { return Sub(a, b); }

int Mul(int &a, int b) { return a = (long) a * b % MOD; }
int mul(int a, int b) { return Mul(a, b); }

long exp(long x, long p) { return p ? mul(exp(mul(x, x), p / 2), p & 1 ? x : 1) : 1; }


int inv(int x) { return exp(x, MOD - 2); }


int Div(int &a, int b) { return Mul(a, inv(b)); }
int div(int a, int b) { return Div(a, b); }