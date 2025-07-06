#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
typedef pair<int,int> Pii;
typedef vector<Pii> Vpii;
typedef vector<vector<bool>> grid;
const int MOD = 1e9+7;

vector<bool> visited;
Vii adj;

void dfs(int v){
   if (visited[v]) return;
   visited[v] = true;
		
	for(int u: adj[v])
	   dfs(u);	
}

int main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL);
	int n, m, a, b, x;
	
	cin >> n >> m;
	visited.resize(n+1,false);
	adj.resize(n + 1);
	
	for(int i = 0; i < m; ++i){
		cin >> a >> b;
		adj[a].push_back(b); 
		adj[b].push_back(a);
	}
	
   dfs(x);
	
}