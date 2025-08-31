#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;
#define add push_back
#define deg(x) ((int) (x).size())
int query(const string &s) {
    cout << "? " << s << endl;
    int x; cin >> x;
    return x;
}

void answer(const string &s) {
    cout << "! " << s << endl;
}

bool solve() {
    int N; cin >> N;
    string s = to_string(N);
    for (int i = 1; i <= N; i++) {
        s += " " + to_string(i);
    }
    vv<int> nodes_in_len(N + 1);
    for (int i = 0; i < N; i++) {
        int res = query(to_string(i + 1) + " " + s);
        if (res == -1) { return false; }
        nodes_in_len.at(res - 1).add(i);
    }
    int most = 0;
    for (int i = 0; i <= N; i++) {
        if (!deg(nodes_in_len[i])) {
            most = i;
            break;
        }
    }
    vt<int> path;
    path.add(nodes_in_len.at(most - 1)[0]);
    for (int i = most - 2; i > -1; i--) {
        int u = path.back();
        for (int v : nodes_in_len[i]) {
            int res = query(to_string(u + 1) + " 2 " + to_string(u + 1) + " " + to_string(v + 1));
            if (res == -1) { return false; }
            if (res > 1) {
                path.add(v);
                break;
            }
        }
    }

    string ans = to_string(most);
    for (int u : path) {
        ans += " " + to_string(u + 1);
    }
    answer(ans);
    return true;
}

int main() {
    int T; cin >> T; while(T--) { if (!solve()) { break; } }
}