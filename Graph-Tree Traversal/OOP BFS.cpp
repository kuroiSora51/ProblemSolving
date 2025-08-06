#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
const int MOD = 1e9+7;

Vi dist;
struct Vertex {
   int val;
   int dist;
   bool used;
   Vertex* parent;

   vector<Vertex*> adj;
};

class Graph {
   public:
      vector<Vertex> vertices;
      Graph(int n) {
         vertices.resize(n + 1);
         vertices[0].used = true;
         for (int i = 1; i <= n; ++i) {
            vertices[i].val = i;
            vertices[i].used = false;
         }
      }
      void add_edge(int a, int b) {
         vertices[a].adj.push_back(&vertices[b]);
         vertices[b].adj.push_back(&vertices[a]);
      }
};


void bfs(Vertex* start, Vertex* end) {
    queue<Vertex*> q;
    start->used = true;
    start->dist = 0;
    start->parent = nullptr;
    q.push(start);

    while (!q.empty()) {
        Vertex* v = q.front(); q.pop();

        for (Vertex* u: v->adj) {
            if (u->used) continue;
            u->used = true;
            u->dist = v->dist + 1;
            u->parent = v;

            q.push(u);
            if (u->val == end->val) break;
        }
    }
}

int main () {
   cin.tie(0)->sync_with_stdio(0);
   int n, m, a, b;
   vector<Vertex*> path;

   cin >> n >> m;
   Graph G(n);

   for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      G.add_edge(a, b);
   }
   Vertex* start = &G.vertices[1];
   Vertex* end = &G.vertices[n];
   bfs(start, end);

   if (!end->used) {
      cout << "IMPOSSIBLE";
      return 0;
   }
   
   Vertex* v = end;
   while(v) {
      path.push_back(v);
      v = v->parent;
   }
   reverse(path.begin(), path.end());

   cout << path.size() << '\n';
   for (Vertex* v: path) cout << v->val << ' ';

}