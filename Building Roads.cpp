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

vector<bool> visited;
Vi C;
Vii adj;

void DFS(int v){
	if (visited[v]) return;
	visited[v] = true;
		
	for(int u: adj[v])
		DFS(u);	
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m,a,b;
	int components = 0;
	cin >> n >> m;
	visited.resize(n+1,false);
	adj.resize(n+1);
	
	for(int i=0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b); 
		adj[b].push_back(a);
	}
	
	for(int v=1; v<=n; ++v){
		if (visited[v]) continue;
		++components;
		DFS(v); C.pb(v);
	}
	
	
	cout<<components-1<<'\n';
	for(int i=1; i<components; ++i)
		cout<<C[i-1]<<' '<<C[i]<<'\n';
}