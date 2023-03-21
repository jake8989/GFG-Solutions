/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int arr[N], tree[4 * N];

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
int query(int node, int st, int en, int l, int r)
{
   if (st > r || en < l)
      return 0;
   if (st >= l && en <= r)
   {
      return tree[node];
   }
   int mid = (st) + (en - st) / 2;
   int left = query(2 * node, st, mid, l, r);
   int right = query(2 * node + 1, mid + 1, en, l, r);
   return left + right;
}
int main()

{
   int n;
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> arr[i];

   build(1, 0, n - 1);
   for (int i = 1; i < 10; i++)
      cout << tree[i] << ": \n";
   cout << query(1, 0, n - 1, 2, 3);
   return 0;
}