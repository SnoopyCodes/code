#include <bits/stdc++.h>
#define ll long long

using namespace std;
struct Cow {
    int weight, pos, dir;
};
bool comp(Cow c1, Cow c2) {
    return c1.pos < c2.pos;
}
vector<pair<int, int>> times;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    int N, L; cin >> N >> L;
    vector<Cow> cows(N);
    int tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> cows[i].weight >> cows[i].pos >> cows[i].dir;
        tot += cows[i].weight;
    }
    sort(cows.begin(), cows.end(), comp);
    int left = 0, right = 0;
    for (int i = 0; i < N; i++) {  //okay so the ones on the right are not lining up correctly
    //because we iterate from teh wrong side
        if (cows[i].dir == -1) {
            left++;
            times.push_back({cows[i].pos, cows[left-1].weight});  //time it takes to end plus which weight
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (cows[i].dir == 1) {
            right++;
            times.push_back({L - cows[i].pos, cows[N - right].weight});
        }
    }
    // for (int i = 0; i < times.size(); i++) {
    //     cout << times[i].first << " ";
    //     cout << times[i].second << "\n";
    // }
    sort(times.begin(), times.end());
    int T;
    int weight;
    int it = 0;
    while (weight < tot / 2) {
        T = times[it].first;
        weight += times[it].second;
        it++;
    }
    queue<int> meet;
    int meetings = 0;
    for (int i = 0; i < N; i++) {
        if (cows[i].dir == 1) { meet.push(cows[i].pos); continue; }
        int pos = cows[i].pos;
        while (!meet.empty() && pos > meet.front() + 2 * T) { meet.pop(); }
        meetings += meet.size();
    }
    cout << meetings << "\n";
    //it is known for some cow with position i there is some cow that will end up at direction i + d * t at time t
    //this is so sad
    //is this a graph problem?
    //okay so the thing i missed
    //# of cows going left = # of cows in left barn; the leftmost (# of cows going left) go left into the barn
}