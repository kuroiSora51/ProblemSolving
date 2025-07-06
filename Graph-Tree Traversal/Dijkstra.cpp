#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> Vi;
typedef vector<Vi> Vii;
typedef pair<ll ,ll> Pii;
typedef vector<Pii> Vpii;
typedef vector<vector<bool>> grid;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX;

Vi parent;
Vi dist;
vector<Vpii> adj;
int n,m;

void dijkstra(int x) {
	dist.assign(n+1, INF);
	dist[x] = 0;
   parent[x] = 0;
	priority_queue<Pii, Vpii, greater<Pii>> q;
	q.push({0,x});
	
	while (!q.empty()) {
      auto [v_dist, v] = q.top();
		q.pop();

		if (v_dist > dist[v]) continue;
		
		for (auto [u, w]: adj[v]) {
			if (dist[v] + w < dist[u]) {
				dist[u] = dist[v] + w;
            parent[u] = v;
				q.push({dist[u], u});
			}
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int a, b, w;
	cin >> n >> m;
	adj.resize(n + 1);
   parent.resize(n + 1);
	
	for(int i = 0; i < m; ++i){
		cin >> a >> b >> w;
		adj[a].push_back({b, w}); 
	}
	
	dijkstra(1);
	cout << "Distance from 1 to " << n << ": " << dist[n] << '\n';
	
   vector<int> path;
   int u = n;
   while (u) {
      path.push_back(u);
      u = parent[u];
   }

   for (auto it = path.end() - 1; it >= path.begin(); --it)
      cout << *it << ' ';
   
}