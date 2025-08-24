#include <bits/stdc++.h>

using namespace std;

const int BIG = 1e9 + 1;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;
#define add push_back
//how bad can my naming conventions get
vv<int> T;
vt<int> t;
vv<vt<int>> dp;

struct mpair {
    int u = -1, v = -1;
    int i, j, k, l;
    mpair(int i, int j, int k, int l):i(i),j(j),k(k),l(l){}
    int C(int x) {
        return dp[x][i][j] - dp[x][k][l];
    }
    void put(int w) {
        if (u == -1) { u = w; }
        else if (v == -1) { v = w; if (C(v) < C(u)) { swap(u, v); } }
        else if (C(w) < C(u)) { v = u; u = w; }
        else if (C(w) < C(v)) { v = w; }
    }
};

int mtf(int u, int c_norm, int c_change, int mask_norm, int mask_change) {
    int sum = 0, mind = BIG;
    for (int v : T[u]) {
        sum += dp[v][c_norm][mask_norm];
        mind = min(dp[v][c_change][mask_change] - dp[v][c_norm][mask_norm], mind);
    }
    return sum + mind;
}

void smin(int &a, int b) { a = a < b ? a : b; }

int PRINT(int u) {
    int minv = BIG;
    for (int c : { 0, 1, 2 }) {
        for (int bm = 1; bm < 8; bm++) {
            if (!(bm & 1 << c)) { continue; }
            cout << c << "_" << bm << "_" << dp[u][c][bm] << " ";
            smin(minv, dp[u][c][bm]);
        }
        cout << "\n";
    }
    return minv;
}

int ftm(int u, int c_norm, int c_change1, int c_change2, int mask_norm, int mask_change1, int mask_change2) {
    mpair one(c_change1, mask_change1, c_norm, mask_norm);
    mpair two(c_change2, mask_change2, c_norm, mask_norm);
    int sum = 0;
    bool f = u == 0 && c_norm == 2 && c_change1 == 0 && c_change2 == 1;

    for (int v : T[u]) {
        one.put(v);
        two.put(v);
        sum += dp[v][c_norm][mask_norm];
    }
    int mix = one.C(one.u) + two.C(two.u);
    if (one.u == two.u) {
        mix = min(one.C(one.u) + two.C(two.v), one.C(one.v) + two.C(two.u));
    }
    return sum + mix;
}

void dfs(int u) { //no p needed bc already rooted at 0
    // cout << "node " << u << endl;
    for (int v : T[u]) { dfs(v); }
    // cout << "back to " << u << endl;
    if (!T[u].size()) { //i do NOT trust that my states are set right
        for (int c : { 0, 1, 2 }) {
            dp[u][c][1 << c] = t[u] != c;
        }
        return;
    }
    for (int c : { 0, 1, 2 }) {
        bool f = u == 0 && c == 2;
        // cout << c << endl;
        int norm = 1 << c; //always the normal mask.
        // cout << norm << endl;
        /* bitcount = 1*/ { int bm = norm;
            dp[u][c][bm] = 0;
            for (int v : T[u]) {
                dp[u][c][bm] += dp[v][c][bm];
            }
        }
        // cout << "o" << endl;
        vt<int> other_c{ 0, 1, 2 }; other_c.erase(find(other_c.begin(), other_c.end(), c));
        for (int bm : { norm ^ 1 << other_c[0], norm ^ 1 << other_c[1] }) { //bitcount = 2
            //case 1: c_change is same, mask_norm is bitcount 1, mask_change is bm
            //case 2: c_change is other bit, mask_change is bm ^ 1 << c
            dp[u][c][bm] = min(mtf(u, c, c, norm, bm),
                mtf(u, c, __builtin_ctz(bm ^ norm), norm, bm ^ norm));    
        }
        // cout << "v" << endl;
        /*bitcount = 3*/ {  int bm = 7;
            //1.all children are color c
            //      a.one child has both colors
            //c_norm is c, c_change is c, mask_norm is 1 << c, mask_change is bm
            smin(dp[u][c][bm], mtf(u, c, c, norm, bm));
            int &ref = dp[u][c][bm];
            //      b. one child has one, another has other
            //all colors same, mask change is bits w/
            
            if (T[u].size() > 1) {
                smin(dp[u][c][bm], ftm(u, c, c, c, norm, norm ^ 1 << other_c[0], norm ^ 1 << other_c[1]));
            }
            //2. all but one are color c
            for (int c2 : other_c) {
                //  a. v has the final different color
                smin(dp[u][c][bm], mtf(u, c, c2, norm, bm ^ norm));
                //  b. v doesn't have the final different color
                if (T[u].size() > 1) {
                    smin(dp[u][c][bm], ftm(u, c, c, c2, norm, bm ^ (1 << c2), 1 << c2));
                }
            }
            //3. all but 2 are color c
            if (T[u].size() > 1) {
                smin(dp[u][c][bm], ftm(u, c, other_c[0], other_c[1], norm, 1 << other_c[0], 1 << other_c[1]));
            }
        }
        if (c != t[u]) {  //change node color
            for (int bm = 1; bm < 8; bm++) {
                dp[u][c][bm]++;
            }
        }
    }
}

int solve(int N, const string& S, const vector<int>& parent) {
    T.resize(N);
    t.resize(N);
    dp.resize(N, vv<int>(3, vt<int>(8, BIG)));  
    assert(S.size() == N);
    assert(parent.size() == N + 1);
    for (int i = 0; i < N; i++) {
        char c; c = S[i];
        if (c == 'T') { t[i] = 0; }
        else if (c == 'J') { t[i] = 1; }
        else { t[i] = 2; }
    }
    for (int i = 2; i <= N; i++) {
        int p = parent[i]; p--;
        T[p].add(i-1);
    }
    dfs(0);
    int ans = BIG;
    for (int c : { 0, 1, 2 }) {
        for (int bm = 1; bm < 8; bm++) {
            if (!(bm & 1 << c)) { continue; }
            ans = min(ans, dp[0][c][bm]);
        }
    }
    dp.clear();
    T.clear();
    t.clear();
    return ans;
}

static const int NEG = -1e9;

int colorId(char ch){ return ch=='T'?0: ch=='J'?1:2; }
char idChar(int x){ return x==0?'T': x==1?'J':'V'; }

int solve_min_bribes(int N, const string& S, const vector<int>& parent){
    vector<vector<int>> child(N + 1);
    for (int i = 2; i <= N; ++i) child[parent[i]].push_back(i);

    // build postorder
    vector<int> order; order.reserve(N);
    {
        vector<int> st = {1};
        while (!st.empty()){
            int u = st.back(); st.pop_back();
            order.push_back(u);
            for (int v: child[u]) st.push_back(v);
        }
    }

    // subtree color counts
    vector<array<int,3>> sub(N + 1, {0,0,0});
    for (int i = (int)order.size()-1; i>=0; --i){
        int u = order[i];
        array<int,3> acc{0,0,0};
        for (int v: child[u]){
            acc[0]+=sub[v][0]; acc[1]+=sub[v][1]; acc[2]+=sub[v][2];
        }
        acc[colorId(S[u-1])]++;
        sub[u]=acc;
    }
    array<int,3> tot = sub[1];

    // pair index
    int pairIdx[3][3];
    for(int a=0;a<3;a++) for(int b=0;b<3;b++) pairIdx[a][b]=-1;
    int idx=0;
    for(int a=0;a<3;a++) for(int b=0;b<3;b++) if(a!=b) pairIdx[a][b]=idx++;
    const int P=6;

    // base[p][u]
    vector<vector<int>> base(P, vector<int>(N+1, NEG));
    for(int a=0;a<3;a++) for(int b=0;b<3;b++) if(a!=b){
        int p=pairIdx[a][b];
        for(int u=2; u<=N; ++u) base[p][u]=sub[u][a]-sub[u][b];
    }

    // best/childBest
    vector<vector<int>> best(P, vector<int>(N+1, NEG));
    vector<vector<int>> childBest(P, vector<int>(N+1, NEG));
    for(int p=0;p<P;++p){
        for(int i=(int)order.size()-1;i>=0;--i){
            int u=order[i];
            int cm=NEG;
            for(int v: child[u]) cm=max(cm, best[p][v]);
            childBest[p][u]=cm;
            best[p][u]=max(base[p][u], cm);
        }
    }

    // 0 cuts
    int keep0 = max({tot[0],tot[1],tot[2]});

    // 1 cut
    int keep1 = 0;
    for(int a=0;a<3;a++) for(int b=0;b<3;b++) if(a!=b){
        int p=pairIdx[a][b];
        int mx=NEG;
        for(int u=2; u<=N; ++u) mx=max(mx, base[p][u]);
        if(mx>NEG) keep1=max(keep1, tot[b]+mx);
    }
    int bestKeep = max(keep0, keep1);

    // 2 cuts (both disjoint and nested) for all permutations
    auto upd_disjoint = [&](int c1,int c2,int c3){
        int p1=pairIdx[c1][c3], p2=pairIdx[c2][c3];
        int bestAll=NEG;
        for(int u=1; u<=N; ++u){
            int m1a=NEG,m1b=NEG,i1=-1;
            int m2a=NEG,m2b=NEG,i2=-1;
            for(int v: child[u]){
                int x1=best[p1][v];
                if(x1>m1a){m1b=m1a; m1a=x1; i1=v;}
                else if(x1>m1b) m1b=x1;
                int x2=best[p2][v];
                if(x2>m2a){m2b=m2a; m2a=x2; i2=v;}
                else if(x2>m2b) m2b=x2;
            }
            int pairSum=NEG;
            if(i1!=-1 && i2!=-1){
                if(i1!=i2) pairSum=m1a+m2a;
                else{
                    if(m2b>NEG) pairSum=max(pairSum, m1a+m2b);
                    if(m1b>NEG) pairSum=max(pairSum, m1b+m2a);
                }
            }
            if(pairSum>NEG) bestAll=max(bestAll, tot[c3]+pairSum);
        }
        return bestAll;
    };
    auto upd_nested = [&](int c1,int c2,int c3){
        int pA=pairIdx[c2][c3], pD=pairIdx[c1][c2];
        int bestAll=NEG;
        for(int a=2; a<=N; ++a){
            int vA=base[pA][a], deep=childBest[pD][a];
            if(vA>NEG && deep>NEG) bestAll=max(bestAll, tot[c3]+vA+deep);
        }
        return bestAll;
    };

    vector<int> col={0,1,2};
    int keep2=NEG;
    sort(col.begin(), col.end());
    do{
        int c1=col[0], c2=col[1], c3=col[2];
        keep2=max(keep2, max(upd_disjoint(c1,c2,c3), upd_nested(c1,c2,c3)));
    }while(next_permutation(col.begin(), col.end()));
    if(keep2>NEG) bestKeep=max(bestKeep, keep2);

    return N - bestKeep;
}

// ---------- generators ----------
struct RNG {
    uint64_t s;
    explicit RNG(uint64_t seed): s(seed){}
    uint32_t next(){ s^=s<<7; s^=s>>9; s^=s<<8; return (uint32_t)s; }
    int randint(int lo,int hi){ return lo + (int)(next()%((uint32_t)(hi-lo+1))); }
};

vector<int> make_random_tree(int N, RNG& rng, int mode){
    // mode: 0=random, 1=path, 2=star, 3=bushy
    vector<int> par(N+1,0);
    par[1]=0;
    if(mode==1){ for(int i=2;i<=N;++i) par[i]=i-1; return par; }
    if(mode==2){ for(int i=2;i<=N;++i) par[i]=1; return par; }
    if(mode==3){
        for(int i=2;i<=N;++i) par[i]=rng.randint(1, max(1,i/2));
        return par;
    }
    for(int i=2;i<=N;++i) par[i]=rng.randint(1,i-1);
    return par;
}

string random_colors(int N, RNG& rng){
    string s; s.reserve(N);
    for(int i=0;i<N;++i){
        int r=rng.randint(0,99);
        int c = (r<10)?0 : (r<55)?1 : 2; // slight skew
        s.push_back(idChar(c));
    }
    return s;
}

int main(int argc, char** argv){
    int REPS = 200000;
    int MAXN = 8;
    uint64_t SEED = 101;
    RNG rng(SEED);
    for(int tc=1; tc<=REPS; ++tc){
        int N = rng.randint(1, MAXN);
        int modePick = rng.randint(0, 99);
        int mode = (modePick<40)?0 : (modePick<60)?1 : (modePick<80)?2 : 3;
        auto par = make_random_tree(N, rng, mode);
        string S = random_colors(N, rng);

        int ans1 = solve(N, S, par);
        int ans2 = solve_min_bribes(N, S, par);

        if(ans1 != ans2){
            cerr << "Mismatch!\n";
            cerr << "N="<<N<<"\nS="<<S<<"\nparents:";
            for(int i=2;i<=N;++i) cerr << " " << par[i];
            cerr << "\nsolver="<<ans1<<" brute="<<ans2<<"\n";
            return 1;
        }
        if(tc%2000==0) cerr << ".";
    }
    cerr << "\nAll tests passed! REPS="<<REPS<<", MAXN="<<MAXN<<", SEED="<<SEED<<"\n";
    return 0;
}
