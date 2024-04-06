#include <bits/stdc++.h>
#define ll long long

using namespace std;
struct Cow {
    int w1, w2;  //wants w1 more than w2
    int line;
    bool active = true;  //is currently searching for a cereal
};
struct Cereal {
    int index;
    int taken = -1;
    queue<int> wanted;  //cows that want it
};
vector<Cow> cows;
vector<Cereal> cereal; 
int ans = 0;
void open(int ci) {
    if (cereal[ci].wanted.empty()) { ans--; return; }  //no one wants this cereal anymore :(
    int tmp = cereal[ci].taken;
    while (!cereal[ci].wanted.empty() && cereal[ci].taken == tmp) {
        Cow candidate = cows[cereal[ci].wanted.front()];
        cereal[ci].wanted.pop();
        if (!candidate.active && candidate.w2 == ci) { continue; }  //if candidate alr has first choice give up
        else if (candidate.active) { cows[candidate.line].active = false; } //candidate wants the cereal.!
        else {  //candidate alr has second choice option but wants this one
            open(candidate.w2);  //first fix this then
        }
        cereal[ci].taken = candidate.line;
    }
    if (cereal[ci].wanted.empty() && cereal[ci].taken == tmp) { ans--; }  //nothing there
}
//first is the closest in line that wants it most
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    int N, M; cin >> N >> M;
    cows.resize(N);
    cereal.resize(M);
    for (int i = 0; i < M; i++) {
        cereal[i].index = i;
    }
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        cows[i].w1 = a;
        cows[i].w2 = b;
        cows[i].line = i;
        if (cereal[cows[i].w1].taken == -1) { cereal[cows[i].w1].taken = i; ans++; cows[i].active = false; } //if this cereal has no one taking it yet, take it
        else {
            cereal[cows[i].w1].wanted.push(i);  //say we want this cereal later
            if (cereal[cows[i].w2].taken == -1) { cereal[cows[i].w2].taken = i; ans++; cows[i].active = false; }  //take it
            else {
                cereal[cows[i].w2].wanted.push(i);  //we want it later
            }
        }
    }
    cout << ans << "\n";
    //start with 0
    for (int i = 0; i < N-1; i++) {
        //every time we remove a cow i, if it was taking nothing before, nothign changes; however, if it is open now to another cow that cow will take it
        //it may be the case that a cow likes a cereal better and goes for that one instead of the one they currently have, opening another one up.
        //it appears we need to have an array of which cows want cereal i for each i, and also an array of what cows want cereal i
        if (cows[i].active) { cout << ans << "\n";  continue; }
        //okay now find which one it is on
        int ci = cows[i].w1;
        if (cereal[ci].taken != i) { ci = cows[i].w2; }
        open(ci);
        cout << ans << "\n";
    }
    //obviously O(NM) simulation
    //but is this a graph question
}