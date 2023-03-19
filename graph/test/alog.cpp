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
   vi arr = {-1, 3, 4, -3, 5, -4};
   int cnt = 0;
   int k = 0;
   int ip = 0;
   for (int i = 0; i < 6; i++)
   {
      if (arr[i] < 0)
      {
         swap(arr[i], arr[ip]);
         ip++;
      }
   }
   for (int i = 0; i < 6; i++)
      cout << arr[i] << " ";
}
