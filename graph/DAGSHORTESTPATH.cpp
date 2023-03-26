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
   int t;
   cin >> t;
   while (t--)
   {
      ll a, b, c, d;
      cin >> a >> b >> c >> d;
      if ((a + 1) % b == (c + 1) % d)
      {
         cout << 1;
      }
      else
      {
         ll fac = a % b;
         ll x = (a - fac);
         ll ans = (b * d) / __gcd(b, d);
         x += ans;
         if (x - a < 0)
            cout << "0\n";
         else
            cout << x - a << endl;
      }
   }
   return 0;
}