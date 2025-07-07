#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pii;
typedef tuple<ll, ll, bool> lol;
typedef vector<Pii> Vpii;
typedef vector<lol> Vlol;

const int MOD = 1e9+7;
const ll INF = LLONG_MAX;
vector<ll> d0, d1;
vector<Vpii> adj;
int n, m;

void dijkstra(const int& x) {
	d0.assign(n + 1, INF);
   d1.assign(n + 1, INF);
   priority_queue<lol, Vlol, greater<lol>> q;

	d0[x] = d1[x] = 0;
	q.push({0, x, false});
	
	while (!q.empty()) {
      auto [v_dist, v, used] = q.top();
		q.pop();

		if (!used && v_dist > d0[v]) continue;
      if (used && v_dist > d1[v]) continue;
		
	   for (auto [u, w]: adj[v]) {
         ll dist = v_dist + w;
         // not using discount
		   if (!used && dist < d0[u]) {
			   d0[u] = dist;
				q.push({d0[u], u, false});
			}
         if (used && dist < d1[u]) {
            d1[u] = dist;
            q.push({d1[u], u, true});
         }
         // using discount
         dist = v_dist + w / 2;
         if (used) continue;

         if (dist < d1[u]){
            d1[u] = dist;
            q.push({d1[u], u, true});
         }
		}
	}
}



int main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL);

	int a, b, w;
	cin >> n >> m;
	adj.resize(n + 1);
	
	for (int i = 0; i < m; ++i) {
	   cin >> a >> b >> w;
		adj[a].push_back({b,w}); 
	}
	
	dijkstra(1);
	cout << min(d0[n], d1[n]);
	
}