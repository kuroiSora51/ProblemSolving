#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define dlt(x) pop_back(x)
#define input(L,n) for(int w=0;w<n;++w) cin>>L[w] 
#define add(x,y) push_back({x,y})
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

const Vpii directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const string moves = "RDLU";
grid board;
Pii start,ending = {-1,-1};
Vii dist;
Vpii monsters, borders;
rolan parent;
int n,m;
bool forMonst = false;
vector<char> path;

void BFS(){
	dist.assign(n+1, Vi(m+1,-1));
	parent.assign(n+1, Vpii(m+1, {-1,-1}));
	queue<Pii> q;
	if (!forMonst){
		dist[start.fst][start.snd] = 0;
		q.push(start); 
	}
	else{
		for(auto M: monsters){
			dist[M.fst][M.snd] = 0;
			q.push(M);
		}
	}
	
	while(!q.empty()){
		Pii v = q.front(); q.pop();
		//process node v
		for(auto [dx,dy]: directions){
			int X = v.fst + dx;
			int Y = v.snd + dy;
			if (board[X][Y] || dist[X][Y] != -1) continue;
			dist[X][Y] = dist[v.fst][v.snd]+1;
			parent[X][Y] = v;
			q.push({X,Y});
		}		
	}
	
}

void retrace(rolan parent){
    for (Pii v = ending; v != start; v = parent[v.fst][v.snd]){
        Pii u = parent[v.fst][v.snd];
        
        for (int d = 0; d < 4; ++d) {
            if (u.fst + directions[d].fst == v.fst && u.snd + directions[d].snd == v.snd) {
                path.pb(moves[d]);
                break;
            }
        }
    }
    
    reverse(path.begin(), path.end());
	for(char z: path) cout<<z;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	board.resize(n+2, vector<bool>(m+2,false));
	char c;
	
	//covering
	for(int i=0;i<n+2;i++){
		board[i][0] = true;
		board[i][m+1] = true;
	}
	for(int j=0;j<m+2;j++){
		board[0][j] = true;
		board[n+1][j] = true;
	}
	//input
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin>>c;
			board[i][j] = (c == '#');
			if (c == 'A') start = {i,j};
			if (c == 'M') monsters.add(i,j);	
		}
	}
	//make borders
	for(int i=1; i<=n; i++){
		if (!board[i][m]) borders.add(i,m);
		if (!board[i][1]) borders.add(i,1);
	}
	for(int j=1; j<=m; j++){
		if (!board[n][j]) borders.add(n,j);
		if (!board[1][j]) borders.add(1,j);
	}
	
	
	bool possible = false;
	BFS(); //player's BFS
	Vii mainDist = dist;
	rolan mainDad = parent;
	forMonst = true;
	BFS(); // monster's BFS
	for(auto [b1,b2]: borders){
		if (mainDist[b1][b2] == -1) continue;
		if (dist[b1][b2] == -1){
			ending = {b1,b2}; break;
			}
		else{
			if (mainDist[b1][b2] < dist[b1][b2] ){
				ending = {b1,b2}; break;	
			}
		}
	}	
	if (ending == MK(-1,-1)) cout<<"NO";
	else{
		cout<<"YES\n"<<mainDist[ending.fst][ending.snd]<<'\n';
		retrace(mainDad);
	}
	
}
	
	
	
	
	
