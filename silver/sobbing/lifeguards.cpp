#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int N; cin >> N;
    vector<array<int, 2>> shifts(N);
    int cover = 0;
    for (int i = 0; i < N; i++) {
        cin >> shifts[i][0] >> shifts[i][1];
    }
    sort(shifts.begin(), shifts.end());
    vector<int> single(N);  //time spent single
    int i = 0;
    int t = shifts[0][0];
    int covers = 0;
    while (i < N) {
        int j = i + 1;
        covers += shifts[i][1] - t;
        while (j < N && shifts[j][1] <= shifts[i][1]) {
            single[i] += shifts[j][0] - t;
            if (shifts[j][1] >= shifts[i][1]) { break; }  //on i's interval we can add no more
            //every single one while j exists is cooked
            int k = j + 1;
            while (k < N && shifts[k][1] <= shifts[j][1]) { k++; }  //ignore all of these
            t = shifts[j][1];
            j = k;
        }
        if (j < N) {
            if (shifts[j][0] > shifts[i][1]) {
                single[i] += shifts[i][1] - t;
                t = shifts[j][0];
            }   else {
                single[i] += shifts[j][0] - t;
                t = shifts[i][1];
            }
        }   else {
            single[i] += (int) shifts[i][1] - t;
        }
        i = j;
    }
    cout << covers - *min_element(single.begin(), single.end()) << "\n";
    
}