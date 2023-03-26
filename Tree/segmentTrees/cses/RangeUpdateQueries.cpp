/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
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
const int N = 2e5 + 6;
ll arr[N], tree[4 * N];
void build(int node, int st, int en)
{
   if (st == en)
   {
      tree[node] = arr[st];
      return;
   }
   int mid = st + (en - st) / 2;
   build(2 * node, st, mid);
   build(2 * node + 1, mid + 1, en);
}
void update(int node, int st, int en, int l, int r, ll val)
{
   if (st > r || en < l)
      return;
   if (st >= l && en <= r)
   {
      tree[node] += val;
      return;
   }
   else
   {
      int mid = st + (en - st) / 2;
      update(2 * node, st, mid, l, r, val);
      update(2 * node + 1, mid + 1, en, l, r, val);
   }
}
void propagate(int node)
{
   tree[2 * node] += tree[node];
   tree[2 * node + 1] += tree[node];
   tree[node] = 0;
}
ll query(int node, int idx, int st, int en)
{
   propagate(node);
   if (st == en)
   {
      return tree[node];
   }
   int mid = st + (en - st) / 2;
   if (st <= idx && idx <= mid)
   {
      return query(2 * node, idx, st, mid);
   }
   else
   {
      return query(2 * node + 1, idx, mid + 1, en);
   }
}
int main()
{
   int n, q;
   cin >> n >> q;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   build(1, 0, n - 1);
   while (q--)
   {
      int t;
      cin >> t;
      if (t == 1)
      {
         int l, r, val;
         cin >> l >> r >> val;
         update(1, 0, n - 1, l, r, val);
      }
      else
      {
         int i;
         cin >> i;
         i--;
         cout << query(1, i, 0, n - 1) << "\n";
      }
   }

   return 0;
}