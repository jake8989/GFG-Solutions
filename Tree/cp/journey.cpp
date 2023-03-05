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
// void dfs(int node, int &time, vector<int> tree[], vector<int> &vis, int &cnt, int &t)
// {
//    if (vis[node])
//       return;
//    vis[node] = 1;
//    time++;
//    if (tree[node].size() == 1)
//    {
//       // cout << time << endl;
//       cnt++;
//       t += time;
//    }
//    for (auto it : tree[node])
//    {
//       if (!vis[it])
//       {
//          dfs(it, time, tree, vis, cnt, t);
//       }
//    }
//    time--;
// }
int main()
{

   int n;
   cin >> n;
   vector<int> tree[n + 1];
   vector<int> vis(n + 1, 0);
   for (int i = 0; i < n - 1; i++)
   {
      int a, b;
      cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
   }
   vector<int> ds;
   int time = -1;
   int cnt = 0;
   map<int, vector<int>> mpp;
   queue<pair<int, int>> q;
   q.push({1, 0});
   vis[1] = 1;
   int leaf = 0;
   int t = 0;
   int l = 0;
   while (!q.empty())
   {
      auto p = q.front();
      int node = p.first;
      int level = p.second;
      q.pop();
      mpp[level].push_back(node);
      for (auto it : tree[node])
      {
         if (tree[it].size() == 1)
         {
            t = t + level + 1;
            l++;
         }
         if (!vis[it])
         {
            q.push({it, level + 1});
            vis[it] = 1;
         }
      }
   }
   // cout << t << " " << l << endl;s
   double ans = (float)((float)t / l);
   cout << fixed << setprecision(12) << ans << endl;

   return 0;
}