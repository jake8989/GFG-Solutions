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
void dfs(int node, vector<int> &vis, vector<int> adj[])
{
   if (vis[node])
      return;
   vis[node] = 1;
   for (auto it : adj[node])
   {
      if (!vis[it])
         dfs(it, vis, adj);
   }
}
int main()
{
   int n, m;
   cin >> n >> m;
   vector<int> adj[n + 1];
   for (int i = 0; i < m; i++)
   {
      int a, b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
   }
   vi vis(n + 1, 0);
   vi ans;
   for (int i = 1; i <= n; i++)
   {
      if (!vis[i])
      {
         ans.pb(i);
         dfs(i, vis, adj);
      }
   }
   cout << ans.size() - 1 << "\n";
   for (int i = 0; i < ans.size() - 1; i++)
   {
      cout << ans[i] << " " << ans[i + 1] << "\n";
   }
   return 0;
}