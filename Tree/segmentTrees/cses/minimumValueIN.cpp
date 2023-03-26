/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
// template <class T>
// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int N = 2e5 + 5;
long long arr[N], tree[4 * N];
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
   tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
long long query(int node, int st, int en, int l, int r)
{
   if (st > r || en < l)
   {
      return INT_MAX;
   }
   if (st >= l && en <= r)
      return tree[node];
   int mid = st + (en - st) / 2;
   long long left = query(2 * node, st, mid, l, r);
   long long right = query(2 * node + 1, mid + 1, en, l, r);
   return min(left, right);
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
   for (int i = 0; i < q; i++)
   {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << query(1, 0, n - 1, l, r) << "\n";
   }

   return 0;
}