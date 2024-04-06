#include <bits/stdc++.h>

using namespace std;
struct Bill {  //could have used pairs but whatever
    int val, expire;
};
vector<Bill> bills;
bool comp(Bill b1, Bill b2) {
    return b1.expire < b2.expire;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int N; cin >> N;
    bills.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bills[i].val >> bills[i].expire;
    }
    sort(bills.begin(), bills.end(), comp);
    int bill = N - 1;
    int total = 0;
    priority_queue<int> valid;  //take the highest at this point
    // for (int i = 0; i < N; i++) {
    //     cout << bills[i].expire << " " << bills[i].val << "\n";
    // }
    for (int time = 1e4; time >= 1; time--) {
        while (bill != -1 && bills[bill].expire >= time) { valid.push(bills[bill].val); bill--; }
        if (valid.empty()) { continue; }
        total += valid.top(); valid.pop();
    }
    cout << total << "\n";
}
//keep a priority queue of variable choices