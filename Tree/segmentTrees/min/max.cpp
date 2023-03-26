/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int arr[N], tree[4 * N];
void build(int node, int st, int en)
{
   if (st == en)
   {
      tree[node] = arr[en];
      return;
   }
   int mid = (st) + (en - st) / 2;
   build(2 * node, st, mid);
   build(2 * node, mid + 1, en);
   tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int st, int en, int l, int r)
{
   if (st > r || en < l)
      return INT_MIN;

   if (st >= l && en <= r)
   {
      return tree[node];
   }

   int mid = st + (en - st) / 2;
   int left = query(2 * node, st, mid, l, r);
   int right = query(2 * node + 1, mid + 1, en, l, r);
   return max(left, right);
}
void update(int node, int st, int en, int idx, int val)
{
   if (st == en)
   {
      arr[st] = val;
      tree[node] = val;
      return;
   }
   int mid = st + (en - st) / 2;
   if (idx <= mid)
   {
      update(2 * node, st, mid, idx, val);
   }
   else
   {
      update(2 * node + 1, mid + 1, en, idx, val);
   }
   tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int main()
{

   return 0;
}