#include <bits/stdc++.h>

using namespace std;

struct Gru {
    vector<int> minions;
};
vector<Gru> company;
vector<int> minions;
int countMinions(int x) {
    int count = 0;
    for (int i = 0; i < company[x].minions.size(); i++) {
        count += countMinions(company[x].minions[i]);
    }
    minions[x] = count;
    return ++count;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    company.resize(N);
    minions.resize(N);
    for (int i = 1; i < N; i++) {
        int gru;
        cin >> gru;
        gru--;
        if (i == 0 && gru == 0) { continue; }
        company[gru].minions.push_back(i);
    }
    countMinions(0);
    for (int i = 0; i < N; i++) {
        cout << minions[i] << " ";
    }
}