#include <bits/stdc++.h>

using namespace std;
struct City {
    int x, y;
};
vector<City> cities;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k, sc, ec;
        cin >> n >> k >> sc >> ec;
        sc--; ec--;
        cities.resize(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            cities[i].x = x; cities[i].y = y;
        }
        //so if s and e are major, then cost is just 0. 
        //otherwise do we just need to find the major cities closest to s and e?
        //and then sum their distances. if there are no similarities
        //oh or compare against going directly
        long long cs = (long long) INT_MAX * 4;  //dist to closest maj city
        for (int i = 0; i < k; i++) {
            cs = min(cs, (long long) abs(cities[i].x - cities[sc].x) + abs(cities[i].y - cities[sc].y));
        }
        long long es = (long long) INT_MAX * 4;  //dist to closest maj city
        for (int i = 0; i < k; i++) {
            es = min(es, (long long) abs(cities[i].x - cities[ec].x) + abs(cities[i].y - cities[ec].y));
        }
        long long ans = cs + es;
        ans = min(ans, (long long) abs(cities[sc].x - cities[ec].x) + abs(cities[sc].y - cities[ec].y));  //direct distance
        cout << ans << "\n";
    }
}