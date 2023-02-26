/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int &ans)
{
   if (n == 0)
   {
      return 1;
   }
   if (n < 0)
      return 0;
   for (int dice = 1; dice <= 6; dice++)
   {
      ans += solve(n - dice, ans);
   }
}
int main()
{
   int n;
   cin >> n;
   int ans = 0;
   return solve(n, ans);
   return 0;
}