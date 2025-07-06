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


int n,m;
Vi parent, color;
Vii adj;
int start, ending;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
    	
        if (color[u] == 0) {
            parent[u] = v;
            if ( dfs(u) ) return true;
        } 
		else if (color[u] == 1) {
			if (parent[v] == u) return false;
            ending = v;
            start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void findCycle(){
    color.assign(n+1, 0);
    parent.assign(n+1, -1);
    start = -1;

    for (int v = 1; v <= n; v++){
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (start == -1) 
        cout << "IMPOSSIBLE";
    else{
        Vi cycle;
        cycle.pb(start);
        for (int v = ending; v != start; v = parent[v])
            cycle.push_back(v);
        cycle.pb(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size()<<'\n';
        for (int v: cycle)
            cout << v << ' ';
    }
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
	
	findCycle();
	


}