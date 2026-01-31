#include <bits/stdc++.h>

using namespace std;

#define int long long
const int  MOD = 1e9 + 7;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
#define add push_back
#define rep(i,a,b) for(auto i=a; i<(b); i++)

//FIND RIGHTMOST INDEX IN UNIMODAL MAXIMAL ARRAY == MAXIMUM

// ----------------- First Implementation -----------------
struct DSU {
    int N;
    vector<int> p, s;
    vt<int> contrib;
    vt<int> aug; //# of needed
    DSU(int n):N(n), p(N), s(N, 1), aug(N), contrib(N) { while (n--) p[n] = n; }
    int par(int u) { return p[u] != u ? p[u] = par(p[u]) : u; }
    bool unite(int u, int v, int w) {
        u = par(u), v = par(v);
        if (u == v) { return false; }
        if (s[u] < s[v] && !aug[u]) { swap(u, v); } //default mst speed
        if (aug[u] && aug[v]) { //just merge u in
            contrib[u] += aug[v] * w;
            aug[u] += aug[v];
            aug[v] = 0;
        }
        s[u] += s[v];
        p[v] = u;
        return N--;
    }
};

void dfs(int u, int p, int src, vt<vt<ii<2>>> &T, DSU &cc, int expense, vt<vt<int>> &cost) {
    if (cc.aug[u] && u != src) {
        cost[src][u] = expense;    
        return;
    }
    for (auto [v, w] : T[u]) {
        if (v == p) { continue; }
        dfs(v, u, src, T, cc, max(expense, w), cost);
    }
}

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vt<int> need(K);
    vt<vt<ii<2>>> T(N);
    
    rep(i, 0, K) {
        cin >> need[i], need[i]--;
    }
    vt<ii<3>> E(M);
    DSU mst(N);
    /*
    think kruskals
        each server serves a certain amount of ppl
        put a cost up with it
        now, to remove a server, we have to select a server, examine where it goes to
        we only ever look at edges in the mst
        but anyways
        consider only those that can see each other
        initially just calculate it with dfs, and update it like prims!
    */


    rep(i, 0, M) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        E[i] = { u, v, w };
    }
    vt<vt<int>> cost(N, vt<int>(N, MOD * MOD));
    DSU cc(N);
    rep(i, 0, K) {
        cc.aug[need[i]] = 1;
    }
    sort(begin(E), end(E), [](auto a, auto b) { return a[2] < b[2]; });
    for (auto [u, v, w] : E) {
        if (mst.unite(u, v, w)) {
            T[u].add({ v, w });
            T[v].add({ u, w });
        }
    }
    
    vt<int> best(N, -1);

    for (int i = 0; i < N; i++) {
        if (cc.aug[i]) {
            dfs(i, -1, i, T, cc, 0, cost);
            best[i] = ranges::min_element(cost[i]) - begin(cost[i]);
        }
    }
    auto dir = cost; //direct costs so we can update

    vt<int> ans(N);
    K--; while (K --> 0) {
        int u = -1;
        for (int i = 0; i < N; i++) {
            if (cc.aug[i] && (u == -1 || cost[i][best[i]] < cost[u][best[u]])) {
                u = i;
            }
        }
        int v = best[u];
        //we merge u into v
        ans[K] = ans[K + 1] + cost[u][v];
        cc.unite(v, u, dir[u][v]);
        for (int i = 0; i < N; i++) {
            if (cc.aug[i] && i != v && i != u) {
                if (dir[i][v] == MOD * MOD && dir[i][u] != MOD * MOD) { //can see u but not v
                    //can now see v
                    assert(dir[v][u] != MOD * MOD);
                    dir[i][v] = dir[v][i] = max(dir[v][u], dir[i][u]);
                }
                cost[i][u] = dir[i][u] = cost[u][i] = dir[u][i] = MOD * MOD;
                if (dir[i][v] != MOD * MOD) { //can see, recalculate edge weights for both.
                    cost[i][v] = dir[i][v] * cc.aug[i] - cc.contrib[i];
                    cost[v][i] = dir[i][v] * cc.aug[v] - cc.contrib[v];
                }
                if (best[i] == u || best[i] == v) {
                    //at most N^2 amortized? pray
                    best[i] = ranges::min_element(cost[i]) - begin(cost[i]); 
                }   else if (cost[i][v] < cost[i][best[i]]) {
                    best[i] = v;
                }
            }
        }
        dir[v][u] = dir[u][v] = cost[u][v] = cost[v][u] = MOD * MOD;
        best[v] = ranges::min_element(cost[v]) - begin(cost[v]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

// ----------------- Second Implementation -----------------
//brute force
struct linexx{
	int u;
	int v;
	long long w;
	friend bool operator<(linexx a,linexx b){
		return a.w<b.w;
	}
}lxx[200000];
int fa[200000],sizd[200000],id[200000],c;
long long cw[400000];
vector<int>line[400000];
void combine(int x,int y,long long w){
	while(x!=fa[x])x=fa[x];
	while(y!=fa[y])y=fa[y];
	if(x==y)return;
	if(sizd[x]>sizd[y])swap(x,y);
	fa[x]=y;
	sizd[y]+=sizd[x];
	cw[c]=w;
	line[c].push_back(id[x]);
	line[c].push_back(id[y]);
	id[y]=c;
	c++;
}
int wvis[200000];
long long siz[400000],val[400000];
vector<long long>ansv;
void dfs(int t){
	vector<int>::iterator it;
	if(line[t].empty())
	{
		if(wvis[t])siz[t]=1;
		else siz[t]=0;
		val[t]=0;
		return;
	}
	siz[t]=0;
	val[t]=-1;
	for(it=line[t].begin();it!=line[t].end();it++)
	{
		dfs(*it);
		siz[t]+=siz[*it];
		val[*it]+=(cw[t]-cw[*it])*siz[*it];
		if(val[t]==-1)val[t]=val[*it];
		else
		{
			if(val[t]>=val[*it])ansv.push_back(val[*it]);
			else
			{
				ansv.push_back(val[t]);
				val[t]=val[*it];
			}
		}
	}
}
long long ans[200000];

void solve2() {
    int T,n,m,p,i,ax;
    long long s;
		cin>>n>>m>>p;
		for(i=0;i<n;i++)wvis[i]=0;
		for(i=0;i<p;i++)
		{
			cin>>ax;
			wvis[ax-1]=1;
		}
		for(i=0;i<m;i++)
		{
			cin>>lxx[i].u>>lxx[i].v>>lxx[i].w;
			lxx[i].u--;
			lxx[i].v--;
		}
		sort(lxx,lxx+m);
		for(i=0;i<n;i++)
		{
			fa[i]=i;
			sizd[i]=1;
			id[i]=i;
			cw[i]=0;
		}
		c=n;
		for(i=0;i<m;i++)combine(lxx[i].u,lxx[i].v,lxx[i].w);
		dfs(c-1);
		ansv.push_back(val[c-1]);
		sort(ansv.begin(),ansv.end());
		s=0;
		for(i=0;i<n;i++)
		{
			ans[n-i-1]=s;
			s+=ansv[i];
		}
		ansv.clear();
		for(i=0;i<c;i++)line[i].clear();
		for(i=0;i<n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
}

//from https://github.com/eysbutno/use-a-cow/blob/main/Implementation/StresstestingFunctions.cpp
inline namespace Random {
    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

    template<typename T> T random() {
        T MAX_VAL = numeric_limits<T>::max();
        return uniform_int_distribution<T>(0, MAX_VAL)(rng);
    }

    template<typename T> T random(T bound) {
        return uniform_int_distribution<T>(0, bound)(rng);
    }

    template<typename T> T random(T l, T r) {
        return uniform_int_distribution<T>(l, r)(rng);
    }

    template<typename T> void rand_shuffle(T l, T r) {
        shuffle(l, r, rng);
    }
}

/**
 * Returns a random tree that should be pretty random.
 */
vector<array<int, 2>> gen_tree(int n) {
    vector<array<int, 2>> edges(n - 1);
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    rand_shuffle(begin(ord), end(ord));
    for (int i = 1; i < n; i++) {
        int p = ord[random(i - 1)];
        edges[i - 1] = {min(p, ord[i]), max(p, ord[i])};
    }
    return edges;
}

/**
 * Retrurns a random undirected graph. Note that
 * multiedges and edges that don't connect two nodes
 * aren't allowed.
 */
vector<array<int, 2>> gen_graph(int n, int m) {
    set<array<int, 2>> edges;
    while (edges.size() < m) {
        int a = random(n - 1), b = random(n - 1);
        if (a > b) swap(a, b);
        if (a != b && !edges.count({a, b})) {
            edges.insert({a, b});
        }
    }
    return vector<array<int, 2>>(begin(edges), end(edges));
}

/** 
 * Same as gen_graph, but the graph needs to be connected.
 */
vector<array<int, 2>> gen_con_graph(int n, int m) {
    assert(m >= n - 1);
    assert(m <= n * (n - 1) / 2);
    auto res = gen_tree(n);
    set<array<int, 2>> added(begin(res), end(res));
    while (m > n - 1) {
        int u = random(n - 1) % n, v = random(n - 1) % n;
        if (u > v) { swap(u, v); }
        if (u != v && !added.count({u, v})) {
            m--;
            added.insert({u, v});
            res.push_back({u, v});
        }
    }
    return vector<array<int, 2>>(begin(res), end(res));
}

vector<array<int, 2>> gen_rand_graph(int n, int m) {
    vector<array<int, 2>> res(m);
    for (int i = 0; i < m; i++) {
        do {
            res[i] = {random(n - 1), random(n - 1)};
        } while (res[i][0] == res[i][1]);
    }
    return res;
}


/**
 * Returns a random array with values being on [low, high]
 */
template <typename T> vector<T> gen_arr(int n, T low, T high) {
    int diff = (int) (high - low);
    vector<T> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = random(low, high);
    }
    return res;
}

// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    int n = random(5, 5);
    int m = random(n - 1, n - 1);
    int k = 0;
    vt<int> inc(n);
    rep(i, 0, n) inc[i] = rand() & 1, k += inc[i];
    auto res = gen_con_graph(n, m);
    oss << n << " " << m << " " << k << "\n";
    rep(i, 0, n) if (inc[i]) oss << i + 1 << " ";
    oss << "\n";
    for (auto [u, v] : res) {
        oss << u+1 << " " << v+1 << " " << random(1, 10) << endl;
    }

    oss << "\n";


    // cout << oss.str() << endl;
    return oss.str();
}
 

// ----------------- Helpers to Run a Solve Function -----------------
string runSolve(function<void()> solveFunc, const string &testInput) {
    // Save the original stream buffers.
    streambuf* origCin  = cin.rdbuf();
    streambuf* origCout = cout.rdbuf();
 
    // Redirect cin and cout.
    istringstream iss(testInput);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
 
    // Run the provided solve function.
    solveFunc();
 
    // Restore original stream buffers.
    cin.rdbuf(origCin);
    cout.rdbuf(origCout);
 
    return oss.str();
}
 
// ----------------- Main Stress-Testing Loop -----------------
signed main() {
    srand(time(NULL));

    //MODIFY
    int stressTests = 1000;
    for (int i = 1; i <= stressTests; i++) {
        // cout << "making test" << endl;
        string test = generateTestCase();
        // cout << "run s2" << endl;
        string out2 = runSolve(solve2, test);
        // cout << "run s" << endl;
        string out1 = runSolve(solve, test);
        if (out1 != out2) {
            cout << "Mismatch found on test case #" << i << ":\n";
            cout << "Test case input:\n" << test << "\n";
            cout << "Output from solve:\n" << out1 << "\n";
            cout << "Output should be:\n" << out2 << "\n";
            return 0;
        }
    }
    cout << "All stress tests passed.\n";
    return 0;
}
