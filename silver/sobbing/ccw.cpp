#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int K, M, N; cin >> K >> M >> N;
    vector<array<int, 2>> patch(K + M);
    for (int i = 0; i < K; i++) {
        cin >> patch[i][0] >> patch[i][1];
    }
    for (int i = K; i < K + M; i++) {
        cin >> patch[i][0];
        patch[i][1] = -1;
    }
    sort(patch.begin(), patch.end());
    //we need to claim stuff between nhoj's patches
    //so for every interval between two of nhoj's cows
    //the cows that are there must be distinct
    //or something
    //so well
    //note that it doesn't make sense to do it for each claimable patch individually
    //like i thouht at first durr
    int lastnhoj = -1;
    vector<ll> ones;
    vector<ll> twos;
    for (int i = 0; i < K + M; i++) {
        if (patch[i][1] == -1) {
            ll sum = 0;
            for (int j = lastnhoj + 1; j < i; j++) {
                sum += patch[j][1];
            }
            if (lastnhoj == -1) { lastnhoj = i; ones.push_back(sum); continue; }
            ll twosum = sum;
            //now find the maximum that we can get with just one
            int start = patch[lastnhoj][0];
            int end = patch[i][0];
            ll maxsum = 0;
            sum = 0;
            int l = lastnhoj + 1, r = lastnhoj + 1;
            for (int j = lastnhoj + 1; j < i; j++) {
                while (r < i && end - patch[r][0] > patch[r][0] - patch[j][0]) {
                    sum += patch[r][1];
                    r++;
                }
                while (l < i && patch[l][0] - start <= patch[j][0] - patch[l][0]) {
                    sum -= patch[l][1];
                    l++;
                }
                maxsum = max(maxsum, sum);
            }
            if (twosum > maxsum * 2) {
                twos.push_back(twosum);
            }   else {
                ones.push_back(maxsum);
                ones.push_back(twosum - maxsum);
            }
            lastnhoj = i;
        }
    }
    /*final iteration*/ {
        ll sum = 0;
        for (int j = lastnhoj + 1; j < K + M; j++) {
            sum += patch[j][1];
        }
        ones.push_back(sum);
    }
    //we have now obtained the sums we can get with 2, and the sums we can get with one
    //ok hold on. if twos > 2 * one, we will never use the one, so discard
    //otherwise, break it up into two sums
    sort(ones.begin(), ones.end()); reverse(ones.begin(), ones.end());
    sort(twos.begin(), twos.end()); reverse(twos.begin(), twos.end());

    int oi = 0, ti = 0;
    ll ans = 0;
    while (N > 0 && (oi < ones.size() || ti < twos.size())) {
        if (N == 1 && oi == ones.size()) { break; }
        else if (N == 1) { ans += ones[oi]; break; }
        if (N == 2) {
            if (ti == twos.size()) { ans += ones[oi] + (oi != ones.size() - 1 ? ones[oi + 1] : 0); break; }
            if (oi != ones.size() && ones[oi] >= twos[oi]) { ans += ones[oi]; break; }
            if (oi == ones.size() || oi == ones.size() - 1) { ans += twos[ti]; break; }
            if (twos[ti] > ones[oi] + ones[oi + 1]) { ans += twos[ti]; break; }
            else { ans += ones[oi] + ones[oi + 1]; break; }
        }
        if (oi == ones.size() || ti < twos.size() && twos[ti] > 2 * ones[oi]) { ans += twos[ti]; ti++; N -= 2; }
        else { ans += ones[oi]; oi++; N--; }
    }
    cout << ans << "\n";

}