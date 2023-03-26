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
const int N = 2e5 + 3;
int arr[N];
int prefix[N];
int main()
{
   int n, q;
   cin >> n >> q;
   for (int i = 1; i <= n; ++i)
   {
      cin >> arr[i];
   }
   prefix[1] = arr[1];
   for (int i = 2; i <= n; i++)
   {
      prefix[i] = prefix[i - 1] ^ arr[i];
   }

   while (q--)
   {
      int a, b;
      cin >> a >> b;
      cout << (prefix[a - 1] ^ prefix[b]) << endl;
   }

   return 0;
}