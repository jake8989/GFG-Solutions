/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long arr[N], tree[4 * N];

void build(int node, int st, int en)
{
   if (st == en)
   {
      tree[node] = arr[st];
      return;
   }
   int mid = (st) + (en - st) / 2;
   build(2 * node, st, mid);
   build(2 * node + 1, mid + 1, en);
   tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long query(int node, int st, int en, int l, int r)
{
   if (st > r || en < l)
      return 0;
   if (st >= l && en <= r)
   {
      return tree[node];
   }
   int mid = (st) + (en - st) / 2;
   long long left = query(2 * node, st, mid, l, r);
   long long right = query(2 * node + 1, mid + 1, en, l, r);
   return left + right;
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
      cout << query(1, 0, n - 1, l, r) << endl;
   }
   return 0;
}