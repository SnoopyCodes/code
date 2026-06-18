#include <bits/stdc++.h>

using namespace std;
//achieves similar performance without considering aggregates
#define lc T[x].ch[0]
#define rc T[x].ch[1]
#define par T[x].p
struct SplayTree {
  struct Node {
    int ch[2] = {0, 0}, p = 0;
    long long self = 0, path = 0;        // Path aggregates
    long long sub = 0, vir = 0;          // Subtree aggregates
    bool flip = 0;                       // Lazy tags
  };
  vector<Node> T;
 
  SplayTree(int n) : T(n + 1) {}
  
  void push(int x) {
    if (!x || !T[x].flip) return;
 
    T[lc].flip ^= 1, T[rc].flip ^= 1;
    swap(lc, rc);
    T[x].flip = 0;
  }
  
  void pull(int x) {
    push(lc); push(rc);
    T[x].path = T[lc].path + T[x].self + T[rc].path;
    T[x].sub = T[x].vir + T[lc].sub + T[rc].sub + T[x].self;
  }
  
  void set(int x, int d, int y) {
    T[x].ch[d] = y; T[y].p = x; pull(x); 
  }
 
  void splay(int x) { 
    auto dir = [&](int x) {
     if (!par) return -1;
      return T[par].ch[0] == x ? 0 : T[par].ch[1] == x ? 1 : -1;
    };
    auto rotate = [&](int x) {
      int y = par, z = T[y].p, dx = dir(x), dy = dir(y);
      set(y, dx, T[x].ch[!dx]);
      set(x, !dx, y);
      if (~dy) set(z, dy, x); 
      T[x].p = z;
    };
    for (push(x); ~dir(x); ) {
      int y = par, z = T[y].p;
      push(z); push(y); push(x);
      int dx = dir(x), dy = dir(y);
      if (~dy) rotate(dx != dy ? x : y);
      rotate(x);
    }
  }
};
 
struct LinkCut : SplayTree {
  LinkCut(int n) : SplayTree(n) {}
 
  int access(int x) {
    int u = x, v = 0;
    for (; u; v = u, u = T[u].p) {
      splay(u); 
      int& ov = T[u].ch[1];
      T[u].vir += T[ov].sub;
      T[u].vir -= T[v].sub;
      ov = v; pull(u);
    }
    return splay(x), v;
  }
 
  void reroot(int x) { 
    access(x); T[x].flip ^= 1; push(x); 
  }
  
  void Link(int u, int v) { 
    reroot(u); access(v); 
    T[v].vir += T[u].sub;
    T[u].p = v; pull(v);
  }
  
  void Cut(int u, int v) {
    reroot(u); access(v);
    T[v].ch[0] = T[u].p = 0; pull(v);
  }
  
  // Rooted tree LCA. Returns 0 if u and v arent connected.
  int LCA(int u, int v) { 
    if (u == v) return u;
    access(u); int ret = access(v); 
    return T[u].p ? ret : 0;
  }
  
  // Query subtree of u where v is outside the subtree.
  long long Subtree(int u, int v) {
    reroot(v); access(u); return T[u].vir + T[u].self;
  }
  
  // Query path [u..v]
  long long Path(int u, int v) {
    reroot(u); access(v); return T[v].path;
  }
  
  // Update vertex u with value v
  void Update(int u, long long v) {
    access(u); T[u].self = v; pull(u);
  }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    LinkCut lct(N);
    while (Q--) {
		string a;
		cin >> a;
		int u, v; cin >> u >> v;
        if (a == "add") { lct.Link(u, v); }
        else if (a == "conn") { cout << (lct.LCA(u, v) ? "YES" : "NO") << "\n"; }
        else { lct.Cut(u, v); }
    }

}