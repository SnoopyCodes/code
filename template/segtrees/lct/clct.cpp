namespace lct{
	const int N=100050;
	int go[N][2],fa[N];
	int pd(int x){ return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
	void rot(int x)
	{
		int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
		if(q!=-1) go[z][q]=x;go[x][p^1]=y;go[y][p]=w;
		if(w) fa[w]=y;fa[x]=z;fa[y]=x;
	}
	void splay(int x){ while(pd(x)!=-1){ if(pd(fa[x])!=-1) rot(pd(fa[x])==pd(x)?fa[x]:x);rot(x);}}
	void access(int x){ for(splay(x),go[x][1]=0;fa[x];rot(x)) splay(fa[x]),go[fa[x]][1]=x;}
	int rt(int x){ access(x);while(go[x][0]) x=go[x][0];splay(x);return x;}
	bool same(int u,int v){ return rt(u)==rt(v);}
	void link(int u,int v){ if(rt(u)==rt(v))return;splay(u);fa[u]=v;}
	void cut(int u,int v)
	{
		if(rt(u)!=rt(v))return;splay(u);access(v);
		fa[v]=fa[v]==u?0:fa[v];fa[u]=fa[u]==v?0:fa[u];
	}
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		int b, c;
		cin >> b >> c;
		if (a == "add") { lct::link(b, c); }
		if (a == "rem") { lct::cut(b, c); }
		if (a == "conn") { cout << (lct::same(b, c) ? "YES" : "NO") << "\n"; }
	}
}