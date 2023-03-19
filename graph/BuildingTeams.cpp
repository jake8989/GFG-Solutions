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
   vi adj[n + 1];
   for (int i = 0; i < m; i++)
   {
      int a, b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
   }
   bool is_bip = true;
   queue<int> q;

   vector<int> color(n + 1, -1);

   for (int i = 1; i <= n; i++)
   {
      if (color[i] == -1)
      {
         q.push(i);
         color[i] = 0;
         while (!q.empty())
         {
            int par = q.front();
            q.pop();
            for (auto it : adj[par])
            {
               if (color[it] == -1)
               {
                  color[it] = !color[par];
                  q.push(it);
               }
               else
               {
                  if (color[it] == color[par])
                  {
                     is_bip = false;
                     break;
                  }
               }
            }
         }
      }
   }
   if (is_bip)
   {
      for (int i = 1; i <= n; i++)
      {
         if (color[i] == 0)
         {
            cout << "1 ";
         }
         else
            cout << "2 ";
      }
   }
   else
      cout << "IMPOSSIBLE\n";

   return 0;
}