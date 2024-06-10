#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int K; cin >> K;
    //what?
    //first note that any power of 2 can be neutralized by multiplying by 5, and any power of 5 by multiplying by 2
    //ur welcome from captain obvious
    //oh this is arc
    //goddamn rip
    //okay lets try bsing it!
    //okay so say we construct a graph based on that
    //right so
    vector<int> dist(K, INT_MAX);
    deque<int> deck;
    deck.push_front(1);
    dist[1] = 1;
    while (!deck.empty()) {
        int x = deck.front();
        deck.pop_front();
        //first consider multiplying by 10, append to the front
        int m10 = x * 10 % K;
        if (dist[x] < dist[m10]) {
            dist[m10] = dist[x];
            deck.push_front(m10);
        }
        int add1 = (x + 1) % K;
        if (dist[x] + 1 < dist[add1]) {
            dist[add1] = dist[x] + 1;
            deck.push_back(add1);
        }
    }
    cout << dist[0] << "\n";
}