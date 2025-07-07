#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define dlt(x) pop_back(x)
#define input(L,n) for(int w=0;w<n;++w) cin>>L[w] 
#define add(x,y) push_back({x,y})
#define MK(x,y) make_pair(x,y)
#define fst first
#define snd second
#define int long long
typedef vector<int> Vi;
typedef vector<Vi> Vii;
typedef pair<int,int> Pii;
typedef vector<Pii> Vpii;
typedef vector<Vpii> rolan;
typedef vector<vector<bool>> grid;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

Vi dist;
rolan adj;
int n,m;

void dijkstra(int x){
	dist.assign(n+1, INF);
	dist[x] = 0;
	priority_queue<Pii, Vpii, greater<Pii>> q;
	q.push({0,x});
	
	while (!q.empty()){
      auto [v_dist, v] = q.top();
		q.pop();

		if (v_dist > dist[v]) continue;
		
		for (auto [u, w]: adj[v]) {
			if (dist[v] + w < dist[u]) {
				dist[u] = dist[v] + w;
				q.push({dist[u], u});
			}
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int a,b,w;
	cin >> n >> m;
	adj.resize(n+1);
	
	for(int i=0; i<m; ++i){
		cin >> a >> b >> w;
		adj[a].add(b,w); 
	}
	
	dijkstra(1);
	for(int i=1; i<=n; ++i)
		cout<<dist[i]<<' ';
	
}