#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;


// ----------------- First Implementation -----------------

//splay tree node
struct node {
    array<node*, 2> c{};
    node* p = nullptr;
    node *aux = nullptr;
    int key;
    bool rev = false; //lazy

    node(int k) { key = k; }

    void push() {
        if (!rev) { return; }
        rev = false;
        swap(c[0], c[1]);
        if (c[0]) { c[0]->rev ^= true; }
        if (c[1]) { c[1]->rev ^= true; }
    }
    
    bool side() { return this == p->c[1]; }  //req parent

    void attach(node* v, bool x) {
        c[x] = v;
        if (v) { v->p = this; }
    }

    void detach() { p = p->c[side()] = nullptr; }  //req parent

    void rot() {  //req parent
        p->push();
        push();
        bool x = side();
        aux = p->aux;
        p->aux = nullptr;
        node* o = p;
        if (o->p) { o->p->attach(this, o->side()); }
        else { p = nullptr; }
        o->attach(c[!x], x);
        attach(o, !x);
    }

    void splay() {  //become root
        while (p) {
            if (!p->p) {}
            else if (side() == p->side()) { p->rot(); }
            else { rot(); }
            rot();
        }
    }

    void print() {
        if (c[0]) { c[0]->print(); }
        cout << key << " ";
        if (c[1]) { c[1]->print(); }
    }

    void access() {
        push();
        splay();
        if (c[1]) {
            c[1]->aux = this;
            c[1]->detach();
        }
        while (aux) {
            aux->splay();
            aux->push();
            if (aux->c[1]) {
                aux->c[1]->aux = aux;
                aux->c[1]->p = nullptr;
            }
            aux->attach(this, 1);
            aux = nullptr;
            splay();
        }
    }

    void reroot() {
        access();
        if (!c[0]) { return; }
        c[0]->rev ^= true;
        c[0]->aux = this;
        c[0]->detach();
    }
    node *find() {
        access();
        node *res = this;
        while (res->c[0]) { res = res->c[0]; }
        return res;
    }
    void cut(node *v) {
        reroot();
        v->access();
        detach();
    }
    void link(node *v) {
        reroot();
        v->access();
        v->attach(this, 1);
    }
    bool con(node *v) {
        return find() == v->find();
    }
};


void solve() {
    //MODIFY
    //run as normal, without multitest
    int N, Q; cin >> N >> Q;
    vec<node*> lct(N);
    rep(i, N) {
        lct[i] = new node(i);
    }
    rep(q, Q) {
		string a;
		cin >> a;
		int b, c;
		cin >> b >> c; b--; c--;
		if (a == "add") { lct[b]->link(lct[c]); }
		if (a == "rem") { lct[b]->cut(lct[c]); }
		if (a == "conn") { cout << (lct[b]->con(lct[c]) ? "YES" : "NO") << "\n"; }
    }
}

// ----------------- Second Implementation -----------------
//brute force
void solve2() {
    //MODIFY
    int N, Q; cin >> N >> Q;
    vec<vec<bool>> con(N, vec<bool>(N));
    rep(q, Q) {
        string t; cin >> t;
        int u, v; cin >> u >> v; u--; v--;
        if (t == "add") {
            con[u][v] = true;
            con[v][u] = true;
        }   else if (t == "rem") {
            con[u][v] = false;
            con[v][u] = false;
        }   else {
            vec<bool> vis(N);
            queue<int> q;
            q.push(u);
            vis[u] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                rep(v, N) {
                    if (con[u][v] && !vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            cout << (vis[v] ? "YES" : "NO") << "\n";
        }
    }
}
 
// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    // cout << "GENERATING" << endl;

    int N = 10, Q = 10;
    oss << N << " " << Q << "\n";
    vec<vec<bool>> con(N, vec<bool>(N));
    vec<arr<int, 2>> e;

    rep(q, Q) {
        int t = rand() % 3;
        while (((t == 1) && e.size() == 0) || (t == 0 && e.size() == N - 1)) {
            t = rand() % 3;
        }
        if (t == 0) {
            oss << "add ";
            arr<int, 2> x = { rand() % N, rand() % N };

            auto yes = [&](int u, int v) {
                vec<bool> vis(N);
                vis[u] = true;
                queue<int> q; q.push(u);
                while (!q.empty()) {
                    int i = q.front(); q.pop();
                    rep(j, N) {
                        if (con[i][j] && !vis[j]) {
                            vis[j] = true;
                            q.push(j);
                        }
                    }
                }
                return bool(vis[v]);
            };

            sort(x.begin(), x.end());
            while (yes(x[0], x[1])) {
                x[0] = rand() % N, x[1] = rand() % N;
                if (x[0] > x[1]) { swap(x[0], x[1]); }
            }
            oss << x[0]+1 << " " << x[1]+1;
            e.push_back({x[0], x[1]});
            con[x[0]][x[1]] = con[x[1]][x[0]] = true;
            
        }
        else if (t == 1) {
            oss << "rem ";
            int i = rand() % e.size();
            oss << e[i][0]+1 << " " << e[i][1]+1;
            con[e[i][0]][e[i][1]] = con[e[i][0]][e[i][1]] = false;
            e.erase(e.begin() + i);
        }
        else {
            oss << "conn ";
            oss << (rand() % N + 1) << " " << (rand() % N + 1);
        }
        oss << "\n";
    }
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
int main() {
    srand(time(NULL));
    //MODIFY
    int stressTests = 100000;
    for (int i = 1; i <= stressTests; i++) {
        string test = generateTestCase();
        // cout << test << endl;
        string out2 = runSolve(solve2, test);
        // cout << ".." << endl;
        string out1 = runSolve(solve, test);
        // cout << "." << endl;
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
