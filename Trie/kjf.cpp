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
void dfs(int n, int m, int row, int col, vector<vector<int>> &vis, string st, vector<vector<int>> &vis, int &b)
{
   if (row < 0 || row >= n)
      return;
   if (col < 0 || col >= m)
      return;
   if (vis[row][col])
      return;

   vis[row][col] = 1;
   if (row == n - 1 || row == 0 ||)
      if (st == "DL")
      {
         dfs(n, m, row + 1, col - 1, vis, st);
      }
      else if ()
}
int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n, m, sx, sy, dx, dy;
      cin >> n >> m >> sx >> sy >> dx >> dy;
      string st;
      cin >> st;
      vector<vector<int>> vis(n, vector<int>(m, 0));
      vector<vector<int>> ans;
      int b = 0;
      dfs(n, m, sx, sy, vis, st, ans, b);
   }

   return 0;
}