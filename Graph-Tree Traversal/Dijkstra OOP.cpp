#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX;

struct Vertex;

struct Edge {
   Vertex* v;
   Vertex* u;
   ll w;

   Edge(Vertex* v_, Vertex* u_, ll w_) : v(v_), u(u_), w(w_) {} 
   Edge() = default;
};

struct Vertex {
   int val;
   ll dist = INF;
   vector<Edge> adj;
};

class Graph {
   public:
      vector<Vertex> vertices;
      Graph(int n) {
         vertices.resize(n + 1);
         for (int i = 1; i <= n; ++i) {
            vertices[i].val = i;
         }
      }
      void add_edge(int a, int b, ll w) {
         vertices[a].adj.emplace_back(&vertices[a], &vertices[b], w);
      }
};

void dijkstra (Vertex* x) {
   using P = pair<ll, Vertex*>;
   priority_queue<P, vector<P>, greater<P>> q;
   
   x->dist = 0;
	q.push({0, x});
   
   while (!q.empty()) {
      auto [d, v] = q.top();
      q.pop();

      if (d != v->dist) continue;

      for (Edge& e: v->adj) {
         Vertex* u = e.u;
         if (v->dist + e.w >= u->dist) continue;

         u->dist = v->dist + e.w;
         q.push({u->dist, u});
      }
   }

}


int main () {
   cin.tie(0)->sync_with_stdio(0);
   int n, m, a, b;
   ll w;
   vector<Vertex*> path;

   cin >> n >> m;
   Graph G(n);

   for (int i = 0; i < m; ++i) {
      cin >> a >> b >> w;
      G.add_edge(a, b, w);
   }
   
   dijkstra(&G.vertices[1]);

   for (int i = 1; i <= n; ++i) 
      cout << G.vertices[i].dist << ' ';
   
   
   return 0;
}