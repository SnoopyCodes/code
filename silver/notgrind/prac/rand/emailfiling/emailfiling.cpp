#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int M, N, K; cin >> M >> N >> K;
        stack<int> skipped;
        vector<int> emails(N);  //what folder it goes into
        vector<int> folders(M);  //how many emails each folder has
        vector<int> filled(M); //how many we have filled thus far
        for (int i = 0; i < N; i++) {
            cin >> emails[i];
            emails[i]--;
            folders[emails[i]]++;
        }
        bool YES = true;
        set<pair<int, int>> curr;  //current screen interval
        set<pair<int, int>> order;  //screen interval sorted by order on screen
        int email = 0;  //current email
        for (int fold = 0; fold < M; fold++) {
            while (filled[fold] != folders[fold]) {
            // cout << "\n";
                //fill up the set
                // cout << curr.size() << "\n";
                while (curr.size() != K && email != N) {
                    curr.insert({emails[email], email});
                    order.insert({email, emails[email]});
                    // cout << "adding" << " " << emails[email] << "\n";
                    email++;
                }
                // cout << curr.size() << "\n";
                auto it = curr.begin();  //the ones we will leave in the stack unless we dont have any choice
                if (email == N) {  //upscroll
                    while (curr.size() != K && !skipped.empty()) {  //we dont have to insert in order bc we know order already
                        // cout << "inserting" << " " << skipped.top() << endl;
                        curr.insert({skipped.top(), 0});
                        skipped.pop();
                    }
                }
                if ((*curr.begin()).first < fold) { YES = false; break; }
                // cout << fold << " " << (*curr.begin()).first << " " << email << " " << endl;
                // if (!skipped.empty())
                // cout << skipped.top() << endl;
                // cout << (*order.begin()).first << " " << (*order.begin()).second << "\n";
                //wait hold on
                //if at any point we scrolled past the folder it is already over
                //how do we manually scroll down?
                //if it doesn't change we should manually scroll down.
                //to achieve this, we keep a set of pairs
                //okay this isn't working
                //fold+K-1?
                auto end = curr.end();
                if (fold + K < M) { end = curr.upper_bound({fold + K-1, 0}); }  //fold+K
                it = curr.begin();
                if (it == end && email != N) {
                    // cout << "skipping" << " " << (*order.begin()).second << endl;
                    skipped.push((*order.begin()).second);
                    curr.erase({(*order.begin()).second, (*order.begin()).first});
                    order.erase(order.begin());
                    continue;
                }  //nothing changes in this set, try and manually move up
                if (it == end) { YES = false; break; }
                while (it != end) {
                    filled[(*it).first]++;
                    order.erase({(*it).second, (*it).first});
                    it++;
                }
                curr.erase(curr.begin(), end);
                // cout << curr.size() << endl;
            }
            if (!YES) { break; }
        }
        if (YES) { cout << "YES" << "\n"; }
        else { cout << "NO" << "\n"; }
    }
}