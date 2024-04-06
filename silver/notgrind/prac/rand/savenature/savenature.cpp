#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> tickets;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int n; cin >> n;
        tickets.resize(n);
        for (int i = 0; i < n; i++) { cin >> tickets[i]; tickets[i] /= 100; }
        sort(tickets.begin(), tickets.end(), greater<int>());
        //what is the greedy strategy
        //stick useless stuff in the blank spots obviously
        //
        //we can consider an "average" contribution as we iterate through spots in order
        //then consider which ones we want to use for only the spots that we are allowing 
        //well...we only theoretically swap one thing at a time so we just have to figure out how to 
        //keep 3 priority queues of slots of maximum value
        //if the maximum value of one pq is > than another where the contribution is less in the first pq swap them
        pair<int, int> p1; cin >> p1.first >> p1.second;
        pair<int, int> p2; cin >> p2.first >> p2.second;
        if (p2.first > p1.first) {//swap
            pair<int, int> tmp = p1;
            p1 = p2;
            p2 = tmp;
        }//swap
        ll k; cin >> k;
        priority_queue<int> cont1;
        priority_queue<int> cont2;
        ll total = 0;
        bool finish = false;
        //cout << p1.second << " " << p2.second << "\n";
        int index = 1;
        for (int i = 0; index <= n; index++) {
            if (index % p1.second == 0 && index % p2.second == 0) {
                //cout << "." << "\n";
                //do we check both lower ones? in theory only the first lower one unless theyre equal...
                //do we only need priority queues? maybe
                //why are we only going for the very smallest? isn't that just wrong?
                if (!cont2.empty() && -cont2.top() > tickets[i]) {
                    int x = -cont2.top();
                    cont2.pop();
                    total -= x * p2.first;
                    total += tickets[i] * p2.first;
                    total += x * (p1.first + p2.first);
                    cont2.push(-tickets[i]);
                }   else if (!cont1.empty() && -cont1.top() > tickets[i]) {
                    int x = -cont1.top();
                    cont1.pop();
                    total -= x * p1.first;
                    total += tickets[i] * p1.first;
                    total += x * (p1.first + p2.first);
                    cont1.push(-tickets[i]);
                }   else {
                    total += tickets[i] * (p1.first + p2.first);
                }
                i++;
            }   else if (index % p1.second == 0) {  //if the second has elements larger than ticket then swap them
                if (!cont2.empty() && -cont2.top() > tickets[i]) {
                    int x = -cont2.top();
                    cont2.pop();
                    total -= x * p2.first;
                    total += tickets[i] * p2.first;
                    total += x * p1.first;
                    cont1.push(-x);
                    cont2.push(-tickets[i]);
                }   else {
                    cont1.push(-tickets[i]);
                    total += tickets[i] * p1.first;
                }
                i++;
            }   else if (index % p2.second == 0) {
                cont2.push(-tickets[i]);
                total += tickets[i] * p2.first; i++;
            }
            //cout << total << "\n";
            if (total >= k) { cout << index << "\n"; finish = true; break; }
        }
        if (!finish)
        cout << -1 << "\n";
    }
}