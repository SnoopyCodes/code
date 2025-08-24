// stress_dp.cpp
#include <bits/stdc++.h>
using namespace std;

static const int NEG = -1e9;
static const int INF = 1e9;

int colorId(char c){ return c=='T'?0: c=='J'?1:2; }
char idChar(int x){ return x==0?'T': x==1?'J':'V'; }

// -------------------- Solver A: cut-based O(N) (from earlier message) --------------------
int solve_cuts(int N, const string& S, const vector<int>& parent){
    vector<vector<int>> child(N + 1);
    for (int i = 2; i <= N; ++i) child[parent[i]].push_back(i);

    vector<int> order; order.reserve(N);
    { vector<int> st = {1}; while(!st.empty()){ int u=st.back(); st.pop_back(); order.push_back(u); for(int v:child[u]) st.push_back(v);} }

    vector<array<int,3>> sub(N + 1, {0,0,0});
    for (int i = (int)order.size()-1; i>=0; --i){
        int u = order[i];
        array<int,3> acc{0,0,0};
        for (int v: child[u]){ acc[0]+=sub[v][0]; acc[1]+=sub[v][1]; acc[2]+=sub[v][2]; }
        acc[colorId(S[u-1])]++; sub[u]=acc;
    }
    array<int,3> tot = sub[1];

    int pairIdx[3][3]; for(int a=0;a<3;a++) for(int b=0;b<3;b++) pairIdx[a][b]=-1;
    int idx=0; for(int a=0;a<3;a++) for(int b=0;b<3;b++) if(a!=b) pairIdx[a][b]=idx++;
    const int P=6;

    vector<vector<int>> base(P, vector<int>(N+1, NEG));
    for(int a=0;a<3;a++) for(int b=0;b<3;b++) if(a!=b){
        int p=pairIdx[a][b]; for(int u=2; u<=N; ++u) base[p][u]=sub[u][a]-sub[u][b];
    }

    vector<vector<int>> best(P, vector<int>(N+1, NEG));
    vector<vector<int>> childBest(P, vector<int>(N+1, NEG));
    for(int p=0;p<P;++p){
        for(int i=(int)order.size()-1; i>=0; --i){
            int u=order[i];
            int cm=NEG; for(int v:child[u]) cm=max(cm, best[p][v]);
            childBest[p][u]=cm;
            best[p][u]=max(base[p][u], cm);
        }
    }

    int keep0 = max({tot[0], tot[1], tot[2]});

    int keep1 = 0;
    for(int a=0;a<3;a++) for(int b=0;b<3;b++) if(a!=b){
        int p=pairIdx[a][b], mx=NEG;
        for(int u=2; u<=N; ++u) mx=max(mx, base[p][u]);
        if (mx>NEG) keep1=max(keep1, tot[b]+mx);
    }
    int bestKeep = max(keep0, keep1);

    auto upd_disjoint = [&](int c1,int c2,int c3){
        int p1=pairIdx[c1][c3], p2=pairIdx[c2][c3], bestAll=NEG;
        for(int u=1; u<=N; ++u){
            int m1a=NEG,m1b=NEG,i1=-1, m2a=NEG,m2b=NEG,i2=-1;
            for(int v: child[u]){
                int x1=best[p1][v]; if(x1>m1a){m1b=m1a; m1a=x1; i1=v;} else if(x1>m1b) m1b=x1;
                int x2=best[p2][v]; if(x2>m2a){m2b=m2a; m2a=x2; i2=v;} else if(x2>m2b) m2b=x2;
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
        int pA=pairIdx[c2][c3], pD=pairIdx[c1][c2], bestAll=NEG;
        for(int a=2; a<=N; ++a){
            int vA=base[pA][a], deep=childBest[pD][a];
            if(vA>NEG && deep>NEG) bestAll=max(bestAll, tot[c3]+vA+deep);
        }
        return bestAll;
    };

    vector<int> col={0,1,2}; sort(col.begin(), col.end());
    int keep2=NEG;
    do { keep2=max(keep2, max(upd_disjoint(col[0],col[1],col[2]),
                              upd_nested  (col[0],col[1],col[2]))); }
    while(next_permutation(col.begin(), col.end()));
    if(keep2>NEG) bestKeep=max(bestKeep, keep2);

    return N - bestKeep;
}

// -------------------- Solver B: bitmask DP (your approach) --------------------
int solve_dp(int N, const string& S, const vector<int>& parent){
    vector<vector<int>> ch(N+1);
    for(int i=2;i<=N;++i) ch[parent[i]].push_back(i);

    vector<int> order; order.reserve(N);
    { vector<int> st={1}; while(!st.empty()){ int u=st.back(); st.pop_back(); order.push_back(u); for(int v:ch[u]) st.push_back(v);} }

    struct NodeDP { int a[3][8]; };
    vector<NodeDP> dp(N+1);
    for(int u=1;u<=N;++u) for(int c=0;c<3;++c) for(int m=0;m<8;++m) dp[u].a[c][m]=INF;

    for(int i=(int)order.size()-1; i>=0; --i){
        int u = order[i];
        int orig = colorId(S[u-1]);

        for(int c=0;c<3;++c){
            int d1=(c+1)%3, d2=(c+2)%3;
            int cur[4]; cur[0]=(orig==c?0:1); cur[1]=cur[2]=cur[3]=INF;

            for(int v: ch[u]){
                int attach[4], detach_[4];
                for(int t=0;t<4;++t){ attach[t]=INF; detach_[t]=INF; }

                // child attaches to c
                for(int M=1; M<8; ++M){
                    if(!(M & (1<<c))) continue;
                    int z = ((M>>d1)&1) | (((M>>d2)&1)<<1);
                    attach[z] = min(attach[z], dp[v].a[c][M]);
                }
                // child detaches (up-edge color is d!=c), and must not include c
                for(int d: {d1,d2}){
                    for(int M=1; M<8; ++M){
                        if((M&(1<<c)) || !(M&(1<<d))) continue;
                        int z = ((M>>d1)&1) | (((M>>d2)&1)<<1);
                        detach_[z] = min(detach_[z], dp[v].a[d][M]);
                    }
                }

                int nxt[4]={INF,INF,INF,INF};
                for(int X=0; X<4; ++X){
                    if(cur[X]>=INF) continue;
                    for(int Y=0; Y<4; ++Y){
                        if(X & Y) continue;
                        if(attach[Y]<INF) nxt[X|Y]=min(nxt[X|Y], cur[X]+attach[Y]);
                        if(detach_[Y]<INF) nxt[X|Y]=min(nxt[X|Y], cur[X]+detach_[Y]);
                    }
                }
                for(int t=0;t<4;++t) cur[t]=nxt[t];
            }

            for(int X=0; X<4; ++X){
                if(cur[X]>=INF) continue;
                int M=(1<<c);
                if(X&1) M|=(1<<d1);
                if(X&2) M|=(1<<d2);
                dp[u].a[c][M]=min(dp[u].a[c][M], cur[X]);
            }
        }
    }

    int ans=INF;
    for(int c=0;c<3;++c) for(int M=1; M<8; ++M) ans=min(ans, dp[1].a[c][M]);
    return ans;
}

// -------------------- Brute force (3^N) --------------------
bool connectedColor(const vector<vector<int>>& g, const vector<int>& A, int c){
    int n=(int)A.size()-1;
    vector<int> nodes; for(int i=1;i<=n;++i) if(A[i]==c) nodes.push_back(i);
    if(nodes.empty()) return true;
    queue<int> q; q.push(nodes[0]);
    vector<char> vis(n+1,0); vis[nodes[0]]=1;
    int seen=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v: g[u]) if(!vis[v] && A[v]==c){ vis[v]=1; q.push(v); ++seen; }
    }
    return seen==(int)nodes.size();
}

int brute_min_bribes(int N, const string& S, const vector<int>& parent){
    vector<vector<int>> g(N+1);
    for(int i=2;i<=N;++i){ int p=parent[i]; g[p].push_back(i); g[i].push_back(p); }
    vector<int> orig(N+1); for(int i=1;i<=N;++i) orig[i]=colorId(S[i-1]);

    long long total=1; for(int i=0;i<N;++i) total*=3;
    int bestKeep=-1; vector<int> A(N+1,0);
    for(long long mask=0; mask<total; ++mask){
        long long x=mask;
        for(int i=1;i<=N;++i){ A[i]=x%3; x/=3; }
        if(!connectedColor(g,A,0) || !connectedColor(g,A,1) || !connectedColor(g,A,2)) continue;
        int keep=0; for(int i=1;i<=N;++i) if(A[i]==orig[i]) ++keep;
        bestKeep=max(bestKeep, keep);
    }
    return N - bestKeep;
}

// -------------------- Generators --------------------
struct RNG { uint64_t s; explicit RNG(uint64_t seed): s(seed){} 
    uint32_t next(){ s^=s<<7; s^=s>>9; s^=s<<8; return (uint32_t)s; }
    int randint(int lo,int hi){ return lo + (int)(next()%((uint32_t)(hi-lo+1))); }};

vector<int> make_tree(int N, RNG& rng, int mode){
    vector<int> par(N+1); par[1]=0;
    if(mode==1){ for(int i=2;i<=N;++i) par[i]=i-1; return par; } // path
    if(mode==2){ for(int i=2;i<=N;++i) par[i]=1;   return par; } // star
    if(mode==3){ for(int i=2;i<=N;++i) par[i]=rng.randint(1, max(1,i/2)); return par; } // bushy
    for(int i=2;i<=N;++i) par[i]=rng.randint(1,i-1); // random
    return par;
}
string random_colors(int N, RNG& rng){
    string s; s.reserve(N);
    for(int i=0;i<N;++i){
        int r=rng.randint(0,99);
        int c=(r<10)?0: (r<55)?1:2; // skewed mix
        s.push_back(idChar(c));
    }
    return s;
}

// -------------------- Main stress harness --------------------
int main(int argc, char** argv){
    int REPS     = 20000;
    int MAX_N    = 10;
    uint64_t SEED= (argc>=5)? strtoull(argv[4], nullptr, 10)
                            : (uint64_t)chrono::high_resolution_clock::now().time_since_epoch().count();
    RNG rng(SEED);

    for(int tc=1; tc<=REPS; ++tc){
        int N = rng.randint(1, MAX_N);
        int modePick=rng.randint(0,99);
        int mode = (modePick<40)?0: (modePick<60)?1: (modePick<80)?2:3;
        auto par = make_tree(N, rng, mode);
        string S = random_colors(N, rng);

        int ans_dp   = solve_dp(N, S, par);
        int ans_cuts = solve_cuts(N, S, par);

        if(ans_dp != ans_cuts){
            cerr << "Mismatch DP vs Cuts!\n";
            cerr << "N="<<N<<"\nS="<<S<<"\nparents:"; for(int i=2;i<=N;++i) cerr<<" "<<par[i];
            cerr << "\nDP="<<ans_dp<<"  Cuts="<<ans_cuts<<"\n";
            return 1;
        }

        if(tc%2000==0) cerr << ".";
    }
    cerr << "\nAll tests passed!  REPS="<<REPS<<", MAX_N="<<MAX_N<<", SEED="<<SEED<<"\n";
    return 0;
}
