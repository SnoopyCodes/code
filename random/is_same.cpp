#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    ifstream oin("out.txt");
    ifstream sin("solout.txt");
    for (int i = 0; i < 300; i++) {
        string a, b;
        getline(oin, a);
        getline(sin, b);
        if (a != b) {
            cout << "tc " << i + 1 << "\n";
            cout << a << " " << b << "\n";
        }
    }
}