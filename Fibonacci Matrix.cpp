#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> Vi;
typedef vector<Vi> Vii;
typedef pair<ll ,ll> Pii;
typedef vector<Pii> Vpii;
typedef vector<vector<bool>> grid;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX;

class Matrix {
   public:
      Vii data;
      int n, m;

      Matrix(int rows, int cols) : n(rows), m(cols), data(rows, Vi(cols, 0)) {}

      Matrix(const Vii& d) : n(d.size()), m(d[0].size()), data(d) {}

      static Matrix identity(int size) {
         Matrix I(size, size);
         for (int i = 0; i < size; ++i)
            I.data[i][i] = 1;
         return I;
      }

      Matrix operator+(const Matrix& other) const {
         Matrix res(n, m);
         for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
               res.data[i][j] = (data[i][j] + other.data[i][j]) % MOD;
         return res;
      }

      Matrix operator-() const {
         Matrix res(n, m);
         for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
               res.data[i][j] = -data[i][j];
         return res;
      }

      Matrix operator-(const Matrix& other) const {
         return *this + (-other);
      }

      Matrix operator*(const Matrix& other) const {
         Matrix res(n, other.m);
         for (int i = 0; i < n; ++i)
            for (int j = 0; j < other.m; ++j)
               for (int k = 0; k < m; ++k)
                  res.data[i][j] += data[i][k] * other.data[k][j];
         return res;
      }

      Matrix operator^(ll exp) const {
         Matrix res = identity(n);
         Matrix base = *this;
         while (exp) {
         if (exp & 1) 
            res = res * base;

         base = base * base;
         exp >>= 1;
         }
         return res;
      }
};


int main () {
   
   Vii data = {{1, 1}, {1, 0}};
   Matrix F(data);
   int n = 7;
   
   Matrix ans = F^n;

   cout << ans.data[0][1];

   return 0;
}