#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
const int MOD = 1e9+7;

struct Vertex {
   int val;
   bool used;
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

void dfs (Vertex* v) {
   if (v->used) return;
   v->used = true;
   
   for (Vertex* u: v->adj)
      dfs(u);
}

int main () {
   cin.tie(0)->sync_with_stdio(0);
   int n, m, a, b;
   int components = -1;
   vector<Vertex> road;

   cin >> n >> m;
   Graph G(n);
   
   for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      G.add_edge(a, b);
   }

   for (Vertex& v: G.vertices) {
      if (v.used) continue;
      else components++;

      dfs(&v);
      road.push_back(v);
   }
   
   cout << components << '\n';
   for (size_t i = 1; i < road.size(); ++i) {
      cout << road[i-1].val << ' ';
      cout << road[i].val << '\n';
   }
   
}