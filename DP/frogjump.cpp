/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// void solve(int n, int ans, int arr[])
// {
//    if (n == 0)
//       return;
//    int left = solve(n - 1, ans, arr) + abs(arr[n - 1] - arr[n]);
//    int right = INT_MAX;
//    if (n > 1)
//    {
//       right = solve(n - 2, ans, arr) + abs(arr[n - 2] - arr[n]);
//    }
//    return min(left, right);
// }

int frogJump(int n, int ans, int arr[])
{
   int ans = 0;
   // solve(n, ans, arr);
   vector<int> dp(n);
   dp[0] = 0;
   for (int i = 1; i < n; i++)
   {
      int fs = dp[i - 1] + abs(dp[i] - dp[i - 1]);
      int ss = INT_MAX;
      if (i > 1)
      {
         ss = dp[i - 2] + abs(dp[i - 2] - dp[i]);
      }
      dp[i] = min(fs, ss);
   }
   return dp[n - 1];
}
int main()
{

   return 0;
}