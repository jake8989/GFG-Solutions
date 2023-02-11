/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<int, string> pis;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;
ll MOD = 998244353;
double eps = 1e-12;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define loop(s, e) for (int i = s; i < e; i++)
// \Input:
// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########
int main()
{
   int n, m;

   cin >> n >> m;
   char grid[n][m];
   string dir = "LURD";
   vector<vector<int>> vis(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> grid[i][j];
      }
   }
   int sx = -1;
   int sy = -1;
   int dx = -1;
   int dy = -1;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 'A')
            sx = i, sy = j;
         if (grid[i][j] == 'B')
            dx = i, dy = j;
      }
   }
   queue<pair<int, int>> q;
   q.push({sx, sy});
   vis[sx][sy] = 1;
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   int dis = 0;
   vector<vector<int>> dist(n, vector<int>(m, 1e9));
   dist[sx][sy] = 0;
   while (!q.empty())
   {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 0 && dr < n && dc >= 0 && dc < m && (!vis[dr][dc]) && grid[dr][dc] == '.' && (dist[dr][dc] > dist[row][col] + 1))
         {
            q.push({dr, dc});
            dist[dr][dc] = dist[row][col] + 1;
            vis[dr][dc] = 1;
         }
      }
   }
   cout << dist[dx][dy];

   return 0;
}