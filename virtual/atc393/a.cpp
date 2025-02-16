#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string a, t; cin >> a >> t;
    if (a == "sick" && t == "sick") { cout << 1 << endl; }
    else if (a == "sick") { cout << 2 << endl; }
    else if (t == "sick") { cout << 3 << endl; }
    else { cout << 4 << endl; }
}