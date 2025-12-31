#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

struct bt {
    array<bt*, 2> c{};
    bool end = false;
    int val;
    bt(int x):val(x) {}
    void ins(int x, int b) {
        if (val == x) {
            end = true;
        }   else {
            bool is_set = x >> b & 1;

            if (!c[is_set]) {
                c[is_set] = new bt(val << 1 | is_set);
            }
            c[is_set]->ins(x, b - 1);
        }
    }

    bt *find(int x, int b) {
        if (val == x) {
            return this;
        }
        return c[x >> b & 1]->find(x, b - 1);
    }

};


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}