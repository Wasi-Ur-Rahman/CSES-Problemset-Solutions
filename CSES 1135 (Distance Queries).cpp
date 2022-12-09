#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define revall(a) a.rbegin(),a.rend()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a * b) / gcd(a,b)
using namespace std;
 
 
const int MAXN = 2e5 + 10; // N nodes
const int N = 21; // log2(1e5)
 
// here we will store the 2^j th nodes of ith node (formally we will add 2nd parent)
int parent[MAXN][N];
int lev[MAXN];
vector<int> g[MAXN];
 
// finding the level of each node of the tree
void dfs(int u,int p) {
  for (int i:g[u]) {
    if (i != p) {
      lev[i] = lev[u] + 1;
      parent[i][0] = u;
      dfs(i,u);
    }
  }
}
 
// teleport to the kth ancestor on logn complexity
// splitting a number in its binary form,say 14 = 1110 = 2^3 + 2^2 + 2^1. teleport to 2^2 -> 2^2 -> 2^1
int kth_ancestor(int u,int k) {
  for (int i = 0;i < N;i++) {
    if (k & (1 << i)) {
      u = parent[u][i];
    }
  }
  return u;
}
 
// finding the lowest common ancestor
int find_lca(int a,int b) {
  if (lev[a] > lev[b])
    swap(a,b);
  int diff = lev[b] - lev[a];
  b = kth_ancestor(b,diff);
 
  if (a == b) return a;
 
  for (int i = N - 1;i >= 0;i--) {
    if ((parent[a][i] != parent[b][i])) {
      a = parent[a][i];
      b = parent[b][i];
    }
  }
  return parent[a][0];
}
 
// precalculating the 2nd parent of each of the nodes
void precal(int n) {
  // run dfs for calculating the levels
  dfs(1,0);
  // preprocessing 
  for (int i = 1;i < N;i++) {
    for (int j = 1;j <= n;j++) {
      int p = parent[j][i - 1];
      parent[j][i] = parent[p][i - 1];
    }
  }
}
 
void solve() {
  int n,q;
  cin >> n >> q;
  for (int i = 1;i <= n - 1;i++) {
    int a,b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  precal(n);
 
  while (q--) {
    int a,b;
    cin >> a >> b;
 
    int x = find_lca(a,b);
 
    cout << lev[a] + lev[b] - 2*lev[x] << '\n';
  }
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
 
  // int t,test = 1;
  // cin >> t;
 
  // while (t--)
    //cout << "Case " << test++ << ": ";
    solve();
 
  return 0; 
}
