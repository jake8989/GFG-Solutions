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
int main()
{
   int n, m;
   cin >> n >> m;
   vector<pair<int, int>> adj[n + 1];
   for (int i = 0; i < m; i++)
   {
      int a, b, w;
      cin >> a >> b >> w;
      adj[a].pb({b, w});
      adj[b].pb({a, w});
   }
   vector<int> dist(n + 1, 1e9);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, 1});
   dist[1] = 0;
   vector<int> vis(n + 1, 0);
   while (!pq.empty())
   {

      int wi = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      if (vis[node])
         continue;
      vis[node] = 1;
      for (auto it : adj[node])
      {
         int u = it.first;
         int w = it.second;
         if (dist[u] > wi + w)
         {
            dist[u] = wi + w;
            pq.push({dist[u], u});
         }
      }
   }
   for (int i = 1; i <= n; i++)
   {
      cout << dist[i] << " ";
   }

   return 0;
}