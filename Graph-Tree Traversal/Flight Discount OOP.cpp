#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX / 3;

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
   ll d0 = INF;
   ll d1 = INF;
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
   using Tpl = tuple<ll, Vertex*, bool>;
   priority_queue<Tpl, vector<Tpl>, greater<Tpl>> q;
   
   x->d0 = x->d1 = 0;
	q.push({0, x, false});
   
   while (!q.empty()) {
      auto [d, v, used] = q.top();
      q.pop();

      if (!used && v->d0 != d) continue;
      if (used && v->d1 != d) continue;

      for (Edge& e: v->adj) {
         Vertex* u = e.u;
         ll dist = d + e.w;
         ll disc_dist = d + e.w / 2;

         if (!used) {
            // use discount
            if (disc_dist < u->d1) {
               u->d1 = disc_dist;
               q.push({u->d1, u, true});
            }
            // don't use it
            if (dist < u->d0) {
               u->d0 = dist;
               q.push({u->d0, u, false});
            }
         }
         else {
            // discount used before
            if (dist < u->d1) {
               u->d1 = dist;
               q.push({u->d1, u, true});
            } 
         }
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
   cout <<  G.vertices[n].d1;
   
   return 0;
}