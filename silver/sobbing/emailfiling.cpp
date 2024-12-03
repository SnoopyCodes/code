#include <bits/stdc++.h>

using namespace std;

void solve() {
	int M, N, K; cin >> M >> N >> K;
	vector<int> order(N);
	vector<int> count(M);  //total count
	for (int i = 0; i < N; i++) {
		cin >> order[i]; order[i]--;
		count[order[i]]++;
	}
	vector<bool> see_file(M);  //which folders we see
	for (int i = 0; i < K - 1; i++) { see_file[i] = true; }
	int next = 0;
	stack<int> scroll;  //we can scroll up to later
    int t = 0;
	set<array<int, 2>> emails; //current window with {time, folder belonging}
    vector<set<int>> in(M);  //currently in thing
	for (int i = K - 1; i < M; i++) {  //bottom of screen file
		see_file[i] = true;
        //remove every occurrence of this in the window
        for (auto a : in[i]) {
            emails.erase({a, i});
        }
        count[i] -= in[i].size();
        in[i].clear();
		while ((next < N || !scroll.empty()) && emails.size() < K) {
			int e = next < N ? order[next] : scroll.top();
			if (next >= N) { scroll.pop(); }
			if (!see_file[e]) {
                in[e].insert(t);
				emails.insert({t++, e});
			}	else {
				count[e]--;
			}
			if (next < N) { next++; }
		}
		while (next < N && count[i - (K - 1)]) {
			int v = (*emails.begin())[1];
            in[v].erase((*emails.begin())[0]);
            emails.erase(emails.begin());
            
			scroll.push(v);
            int e;
            while (next < N) {
                e = order[next]; next++;
                if (!see_file[e]) { break; }
                count[e]--;
            }
            if (!see_file[e]) {
                in[e].insert(t);
                emails.insert({t++, e});
            }
			if (next == N) {
				while (count[i - (K - 1)] && !scroll.empty()) {
                    e = scroll.top(); scroll.pop();
                    if (see_file[e]) { count[e]--; }
				}
                if (count[i - (K - 1)]) { cout << "NO" << "\n"; return; }
			}
		}
		see_file[i - (K - 1)] = false;
	}
	for (int i = 0; i < M; i++) {
		if (count[i]) { cout << "NO" << "\n"; return; }
	}

	cout << "YES" << "\n";
}

int main() {
	int T; cin >> T; while(T--) { solve(); }
}
