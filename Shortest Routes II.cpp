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

Vii d;
rolan adj;
int n,m;

void dijkstra(int x){
	Vi dist(n+1, INF);
	dist[x] = 0;
	priority_queue<Pii, Vpii> q;
	q.push({0,x});
	
	while (!q.empty()){
		int v = q.top().snd;
		int vDist = -q.top().fst; 
		q.pop();
		if (vDist != dist[v]) continue;
		
		for (auto [u,w]: adj[v]){
			if (dist[v]+w < dist[u]){
				dist[u] = dist[v]+w;
				q.push( {-dist[u],u} );
			}
		}
	}
	for(int i=1; i<=n; ++i){
		if (dist[i] == INF) dist[i] = -1;
		d[x][i] = dist[i];
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int a,b,w,q;
	cin >> n >> m>> q;
	adj.resize(n+1);
	d.resize(n+1, Vi(n+1));
	Vii repeated(n+1, Vi(n+1,INF));
	
	for(int i=0; i<m; ++i){
		cin >> a >> b >> w;
		repeated[a][b] = repeated[b][a] = min(repeated[a][b],w);
	}
	
	//to adj list cuz im to lazy
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if (repeated[i][j] == INF) continue;
			adj[i].add(j,repeated[i][j]);
		}
	}
	
	for(int x=1; x<=n; ++x)
		dijkstra(x);
		
	while(q--){
		cin >> a >> b;
		cout<<d[a][b]<<'\n';
	}
	
}