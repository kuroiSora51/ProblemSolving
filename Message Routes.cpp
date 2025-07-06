#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define dlt(x) pop_back(x)
#define input(L,n) for(int w=0;w<n;++w) cin>>L[w] 
#define add(x) insert(x)
#define MK(x,y) make_pair(x,y)
#define fst first
#define snd second
typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
typedef pair<int,int> Pii;
typedef vector<Pii> Vpii;
typedef vector<Vpii> rolan;
typedef vector<vector<bool>> grid;
const int MOD = 1e9+7;

Vii adj;
int n,m;
void BFS(int start,int ending){
	vector<bool> visited(n+1);
	Vi parent(n+1), dist(n+1);
	queue<int> q;
	visited[start] = true;
	dist[start] = 0; 
	q.push(start);
	
	while(!q.empty()){
		int v = q.front(); q.pop();	
		
		for(int u: adj[v]){
			if (visited[u]) continue;
			visited[u] = true;
			dist[u] = dist[v] + 1;
			parent[u] = v;
			q.push(u);
			if(u == ending) break;
		}
	}
	if(!visited[ending]){
		cout<<"IMPOSSIBLE";
		return;
	}
	Vi path;
	for(int v=ending; v!=0; v=parent[v])
		path.pb(v);
	reverse(path.begin(), path.end());
	
	cout<<path.size()<<'\n';
	for(int p: path)
		cout<<p<<' ';
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int a,b;
	cin >> n >> m;
	adj.resize(n+1);
	
	for(int i=0; i<m; ++i){
		cin >> a >> b;
		adj[a].pb(b); 
		adj[b].pb(a);
	}
	
	BFS(1,n);
	
	

}