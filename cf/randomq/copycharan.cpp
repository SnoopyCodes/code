#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
 
vector<int> e[N];
int dis[N];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	e[i].clear();
		dis[i] = i-1;
	}
	for(int i=1;i<n;i++)
	{
		e[i].push_back(i+1);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v; u++; v++;
		e[u].push_back(v);
	}
	int pre = 0;
	
	for(int i=1;i<=n -1 ;i++)
	{	
        cout << pre << " ";
		// if( i >= pre )
		// 	cout<<1;
		// else 
		// 	cout<<0;
		for(auto v:e[i])
		{
			if(dis[v] > dis[i] + 1)
			{	dis[v] = dis[i] +1;
				pre = max(pre,v - dis[v]);
			}	
		}
	}
	cout<<endl;
	
}  
signed main (){
	std::ios::sync_with_stdio(false);  
	cin.tie(NULL); 
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
} 