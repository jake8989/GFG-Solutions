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
// int f(int index, int tar, string b, string tp, vector<int> &dp)
// {
//    if (index == b.length())
//    {
//       int curr = 0;
//       for (int i = 0; i < tp.length(); i++)
//       {
//          if (tp[i] == '+')
//             curr++;
//          else
//             curr--;
//       }
//       // cout << "output" << curr << endl;
//       return curr == tar;
//    }
//    if (dp[index] != -1)
//       return dp[index];
//    if (b[index] == '?')
//    {
//       int take = f(index + 1, tar, b, tp + "+", dp);
//       int not_take = f(index + 1, tar, b, tp + "-", dp);
//       return dp[index] = take + not_take;
//    }
//    else
//    {
//       return dp[index] = f(index + 1, tar, b, tp + b[index], dp);
//    }
// }
int main()
{
   string a, b;
   cin >> a >> b;
   int targ = 0;
   int sec = 0;
   for (int i = 0; i < a.length(); i++)
   {
      if (a[i] == '+')
         targ++;
      else
         targ--;
   }
   for (int i = 0; i < b.length(); i++)
   {
      if (b[i] == '?')
         sec++;
   }
   string tp = "";
   vector<int> dp(a.length() + 1, 0);
   int pos = f(0, targ, b, tp, dp);
   if (sec == 0)
   {
      if (pos)
      {
         cout << "1.000000000\n";
      }
      else
         cout << "0.000000000\n";
   }
   else
   {
      double x = pow(2, sec);
      double prob = pos / x;
      std::cout << std::fixed << std::setprecision(12) << prob;
   }

   return 0;
}