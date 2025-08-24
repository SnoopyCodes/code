// bribery_dp.cpp
#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

inline int cid(char c){ return c=='T' ? 0 : (c=='J'?1:2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; 
        cin >> N;
        string S; 
        cin >> S;

        vector<vector<int>> ch(N+1);
        vector<int> par(N+1, 0);
        for (int i = 2; i <= N; ++i) {
            int p; cin >> p;
            par[i] = p;
            ch[p].push_back(i);
        }

        // iterative postorder
        vector<int> order; order.reserve(N);
        {
            vector<int> st = {1};
            while (!st.empty()){
                int u = st.back(); st.pop_back();
                order.push_back(u);
                for (int v: ch[u]) st.push_back(v);
            }
        }

        // dp[u][c][M], M=1..7; initialize to INF
        // store as vector of arrays for cache-friendliness
        struct NodeDP { int a[3][8]; };
        vector<NodeDP> dp(N+1);
        for (int u=1; u<=N; ++u)
            for (int c=0;c<3;++c)
                for (int m=0;m<8;++m) dp[u].a[c][m] = INF;

        // process bottom-up
        for (int i=(int)order.size()-1; i>=0; --i){
            int u = order[i];
            int orig = cid(S[u-1]);

            for (int c=0; c<3; ++c){
                int d1 = (c+1)%3, d2 = (c+2)%3;

                int cur[4]; // mask over {d1,d2}
                cur[0] = (orig==c ? 0 : 1);
                cur[1] = cur[2] = cur[3] = INF;

                // merge each child
                for (int v: ch[u]){
                    int attach[4], detach_[4];
                    for (int t=0;t<4;++t){ attach[t]=INF; detach_[t]=INF; }

                    // child attaches to color c (same component as parent)
                    for (int M=1; M<8; ++M){
                        if (!(M & (1<<c))) continue;
                        int z = ((M>>d1)&1) | (((M>>d2)&1)<<1);
                        attach[z] = min(attach[z], dp[v].a[c][M]);
                    }
                    // child detaches; its up-edge color is d!=c and M must NOT contain c
                    for (int d : {d1,d2}){
                        for (int M=1; M<8; ++M){
                            if ((M&(1<<c)) || !(M&(1<<d))) continue;
                            int z = ((M>>d1)&1) | (((M>>d2)&1)<<1);
                            detach_[z] = min(detach_[z], dp[v].a[d][M]);
                        }
                    }

                    int nxt[4]; nxt[0]=nxt[1]=nxt[2]=nxt[3]=INF;
                    for (int X=0; X<4; ++X){
                        if (cur[X] >= INF) continue;
                        for (int Y=0; Y<4; ++Y){
                            if (X & Y) continue; // each other-color may appear in at most one child
                            if (attach[Y] < INF) nxt[X|Y] = min(nxt[X|Y], cur[X] + attach[Y]);
                            if (detach_[Y] < INF) nxt[X|Y] = min(nxt[X|Y], cur[X] + detach_[Y]);
                        }
                    }
                    for (int t=0;t<4;++t) cur[t] = nxt[t];
                }

                // write results to dp[u][c][M]
                for (int X=0; X<4; ++X){
                    if (cur[X] >= INF) continue;
                    int M = (1<<c);
                    if (X&1) M |= (1<<d1);
                    if (X&2) M |= (1<<d2);
                    dp[u].a[c][M] = min(dp[u].a[c][M], cur[X]);
                }
            }

            // Leaf shortcut (optional clarity): already handled by the generic loop.
        }

        int ans = INF;
        for (int c=0;c<3;++c)
            for (int M=1; M<8; ++M)
                ans = min(ans, dp[1].a[c][M]);

        cout << ans << '\n';
    }
    return 0;
}
