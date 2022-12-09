#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define pb push_back
#define all(b) b.begin(),b.end()
#define revall(b) b.rbegin(),b.rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define F first
#define S second
const int N = 1010;
const int mod = 1e9 + 7;

// 4 direction (u,d,l,r)
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;
char s[N][N];
bool vis[N][N];

int dis[N][N];
int dis1[N][N];

bool isBoundary(int x,int y) {
    return (x == 0 || x == n - 1 || y == 0 || y == m - 1);
}

bool ok(int x,int y) {
    return (x >= 0 and x < n && y >= 0 && y < m && !vis[x][y] && s[x][y] == '.');
}

void solve() {
  int px = 0,py = 0;
  queue<pair<int,int>> q;

  cin >> n >> m;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      cin >> s[i][j];
      if (s[i][j] == 'A') {
        px = i;
        py = j;
      }if (s[i][j] == 'M') {
        q.push({i,j});
      }
    }
  }
  int a = px,b = py;
  if (isBoundary(px,py)) {
    yes;
    cout << 0 << '\n';
    return;
  }

  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    int x = it.F,y = it.S;
    vis[x][y] = 1;
    // if (y + 1 < m && !vis[x][y + 1] && s[x][y + 1] == '.') {
    //   vis[x][y + 1] = 1;
    //   dis[x][y + 1] = dis[x][y] + 1;
    //   q.push({x,y + 1});
    // }
    // if (y - 1 >= 0 && !vis[x][y - 1] && s[x][y - 1] == '.') {
    //   vis[x][y - 1] = 1;
    //   dis[x][y - 1] = dis[x][y] + 1;
    //   q.push({x,y - 1});
    // }
    // if (x + 1 < n && !vis[x + 1][y] && s[x + 1][y] == '.') {
    //   vis[x + 1][y] = 1;
    //   dis[x + 1][y] = dis[x][y] + 1;
    //   q.push({x + 1,y});
    // }
    // if (x - 1 >= 0 && !vis[x - 1][y] && s[x - 1][y] == '.') {
    //   vis[x - 1][y] = 1;
    //   dis[x - 1][y] = dis[x][y] + 1;
    //   q.push({x - 1,y});
    // }
    for (int i = 0;i <= 3;i++) {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (ok(X,Y)) {
          vis[X][Y] = 1;
          dis[X][Y] = dis[x][y] + 1;
          q.push({X,Y});
        }
    }

  }

  map<pair<int,int>,pair<int,int>> mp;

  memset(vis,0,sizeof(vis));

  q.push({px,py});
  vis[px][py] = 1;
  dis1[px][py] = 0;
  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    int x = it.F,y = it.S;
    
    // if (y + 1 < m && !vis[x][y + 1] && s[x][y + 1] == '.') {
    //   vis[x][y + 1] = 1;
    //   dis1[x][y + 1] = dis1[x][y] + 1;
    //   q.push({x,y + 1});
    //   mp[{x,y + 1}] = {x,y};
    // }
    // if (y - 1 >= 0 && !vis[x][y - 1] && s[x][y - 1] == '.') {
    //   vis[x][y - 1] = 1;
    //   dis1[x][y - 1] = dis1[x][y] + 1;
    //   mp[{x,y - 1}] = {x,y};
    // }
    // if (x + 1 < n && !vis[x + 1][y] && s[x + 1][y] == '.') {
    //   vis[x + 1][y] = 1;
    //   dis1[x + 1][y] = dis1[x][y] + 1;
    //   q.push({x + 1,y});
    //   mp[{x + 1,y}] = {x,y};
    // }
    // if (x - 1 >= 0 && !vis[x - 1][y] && s[x - 1][y] == '.') {
    //   vis[x - 1][y] = 1;
    //   dis1[x - 1][y] = dis1[x][y] + 1;
    //   q.push({x - 1,y});
    //   mp[{x - 1,y}] = {x,y};
    // }
    for (int i = 0;i <= 3;i++) {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (ok(X,Y)) {
          vis[X][Y] = 1;
          dis1[X][Y] = dis1[x][y] + 1;
          q.push({X,Y});
          mp[{X,Y}] = {x,y};
        }
    }
  }
  
  bool pos = 0;
  px = 0,py = 0;
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      if (s[i][j] == '.' && isBoundary(i,j)) {
        if (!dis[i][j] && dis1[i][j]) {
          pos = 1;
          px = i;
          py = j;
          break;
        }
        else if (dis1[i][j] && dis[i][j] && dis1[i][j] < dis[i][j]) {
          pos = 1;
          px = i;
          py = j;
          break;
        }
      }
    }
    if (pos) break;
  }

  if (pos) {
    yes;
    string ans = "";
    while (px != a || py != b) {
      auto it = mp[{px,py}];
      int x = it.F,y = it.S;
      if (px - x == 1) {
        ans += "D";
      }
      else if (x - px == 1) {
        ans += "U";
      }else if (y - py == 1) {
        ans += "L";
      }else if (py - y == 1) {
        ans += "R";
      }
      px = x,py = y;
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    cout << ans << '\n';
  }else {
    no;
  }

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif

  // int t,test = 1;
  // cin >> t;
  // while (t--)
    solve();
  
    
  return 0;
}
