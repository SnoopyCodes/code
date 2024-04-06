#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

ll N, K, M;

bool check(ll X) {
    ll giv = 0;
    for (ll i = 0; i < K; i++) {
        ll Y = (N - giv) / X;
        if (Y < M) {
            return giv + M * (K - i) >= N;
        }
        giv += Y;
    }
    return giv >= N;
}

int main() {
    ifstream fin("loan.in");
    ofstream fout("loan.out");

    fin >> N >> K >> M;
    ll l = 1, r = N;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    fout << l << endl;

    fin.close();
    fout.close();

    return 0;
}